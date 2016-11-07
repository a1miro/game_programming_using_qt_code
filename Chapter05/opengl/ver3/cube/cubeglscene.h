#ifndef CUBEGLSCENE_H
#define CUBEGLSCENE_H

#include <QImage>
#include "abstractglscene.h"
#include <QVector3D>
#include <QVector2D>

class QOpenGLTexture;
class SceneGLWindow;
class CubeGLScene : public AbstractGLScene
{
public:
    CubeGLScene(SceneGLWindow *wnd);
    ~CubeGLScene();

    void initialize();
    void paint();
    void setTexture(const QImage &img);

protected:
    void initializeTexture();
    void initializeCubeData();
    void paintCube();

private:
    QImage m_tex;
    QOpenGLTexture* m_texture = nullptr;
    bool m_initialized = false;

    struct TexturedPoint {
        QVector3D coord;
        QVector2D uv;
        TexturedPoint(const QVector3D& pcoord, const QVector2D& puv) : coord(pcoord), uv(puv) {}
    };

    QVector<TexturedPoint> m_data;
};

#endif // CUBEGLSCENE_H
