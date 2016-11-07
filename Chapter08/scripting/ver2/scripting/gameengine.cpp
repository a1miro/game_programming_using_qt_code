#include "gameengine.h"
#include <QFile>
#include <QTimerEvent>
#include "aiscript.h"
#include <QtDebug>

GameEngine::GameEngine(QObject *parent) : QScriptEngine(parent) {
    m_timerId = 0;
    m_player = new LivingEntity(this);
    m_creature = new NPC(this);
    QScriptValue go = globalObject();
    go.setProperty("player", newQObject(m_player));
    go.setProperty("self", newQObject(m_creature));
}

LivingEntity *GameEngine::player() const {return m_player; }

LivingEntity *GameEngine::npc() const { return m_creature; }

void GameEngine::start(const QString &fileName) {
    m_ai = AIScript();
    QScriptProgram program = m_ai.read(fileName);
    m_ai.evaluate(program, this);
    qDebug() << m_ai.initFunction.toString();
    qDebug() << m_ai.heartbeatFunction.toString();
    qDebug() << m_ai.defendFunction.toString();
}

QScriptProgram GameEngine::readScriptFromFile(const QString &fileName) const {
    QFile file(fileName);
    if(!file.open(QFile::ReadOnly|QFile::Text)) return QScriptProgram();
    return QScriptProgram(file.readAll(), fileName);
}

void GameEngine::timerEvent(QTimerEvent *te) {
    if(te->timerId() != m_timerId) return;
    m_creature->reset();
    m_player->reset();
    evaluate(m_npcProgram);
}
