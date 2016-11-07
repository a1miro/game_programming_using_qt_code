#include "shaderglscene.h"
#include <QFile>
#include "glhelpers.h"
#include "plyreader.h"

ShaderGLScene::ShaderGLScene(SceneGLWindow *wnd) : AbstractGLScene(wnd) {
    wnd->setScene(this);
    m_initialized = false;
    initializeCubeData();
}

void ShaderGLScene::initialize() {
    AbstractGLScene::initialize();
    m_initialized = true;
    glClearColor(0,0,0,0);

    m_shader.addShaderFromSourceCode(QOpenGLShader::Vertex, fileContent(":/phong.vert"));
    m_shader.addShaderFromSourceCode(QOpenGLShader::Fragment, fileContent(":/phong.frag"));
    m_shader.link();
    m_shader.bind();
    m_shader.setAttributeArray("Vertex", GL_FLOAT, m_data.constData(), 3, sizeof(ScenePoint));
    m_shader.enableAttributeArray("Vertex");

    m_shader.setAttributeArray("Normal", GL_FLOAT, &m_data[0].normal, 3, sizeof(ScenePoint));
    m_shader.enableAttributeArray("Normal");

    m_shader.setUniformValue("mat.ka", QVector3D(0.1, 0, 0.0));
    m_shader.setUniformValue("mat.kd", QVector3D(0.7, 0.0, 0.0));
    m_shader.setUniformValue("mat.ks", QVector3D(1.0, 1.0, 1.0));
    m_shader.setUniformValue("mat.shininess", 128.0f);

    m_shader.setUniformValue("light.position", QVector3D(2, 1, 1));
    m_shader.setUniformValue("light.intensity", QVector3D(1,1,1));
}

void ShaderGLScene::paint() {
    m_projectionMatrix.setToIdentity();
    m_projectionMatrix.perspective(90, qreal(window()->width())/qreal(window()->height()), 0.5, 40);

    m_viewMatrix.setToIdentity();
    m_viewMatrix.lookAt({0,0,2}, {0,0,0}, {0, 1, 0});

    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
    glViewport(0, 0, window()->width(), window()->height());


    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    m_modelMatrix.setToIdentity();
    m_modelMatrix.scale(2);
    m_modelMatrix.rotate(m_angle, 0, 1, 0);
    m_modelMatrix.rotate(-90, 1, 0, 0);

    QMatrix4x4 modelViewMatrix = m_viewMatrix*m_modelMatrix;

    paintCube(modelViewMatrix);
}

qreal ShaderGLScene::angle() const { return m_angle; }

void ShaderGLScene::paintCube(const QMatrix4x4 &mvMatrix) {
    m_shader.bind();
    m_shader.setUniformValue("projectionMatrix", m_projectionMatrix);
    m_shader.setUniformValue("modelViewMatrix", mvMatrix);
    m_shader.setUniformValue("mvpMatrix", m_projectionMatrix*mvMatrix);
    m_shader.setUniformValue("normalMatrix", mvMatrix.normalMatrix());

    glDrawArrays(GL_TRIANGLES, 0, m_data.size());
}

void ShaderGLScene::setAngle(qreal a) {
    m_angle = a;
    window()->update();
}

void ShaderGLScene::initializeCubeData() {
    PLYReader reader(":/monkey.ply");
    if(reader.read()) {
        // reconstruct faces
        const QVector<PLYReader::ScenePoint> vertices = reader.vertices();
        const QVector<QVector<int> > faces = reader.faces();
        foreach(QVector<int> face, faces) {
            ScenePoint pt;
            for(int idx = 0; idx < face.count(); ++idx) {
                int vertexId = face.at(idx);
                PLYReader::ScenePoint scenePoint = vertices.at(vertexId);
                pt.coords = scenePoint.coord;
                pt.normal = scenePoint.normal;
                m_data << pt;
            }
        }
    }
}
