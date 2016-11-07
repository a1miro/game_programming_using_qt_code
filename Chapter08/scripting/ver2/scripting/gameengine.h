#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <QScriptEngine>
#include "livingentity.h"
#include "npc.h"
#include "aiscript.h"

class GameEngine : public QScriptEngine {
public:
  GameEngine(QObject *parent = 0);
  LivingEntity *player() const;
  LivingEntity *npc() const;
  void start(const QString &fileName);
protected:
  QScriptProgram readScriptFromFile(const QString &fileName) const;
  void timerEvent(QTimerEvent *te);
private:
  LivingEntity *m_player;
  NPC *m_creature;
  QScriptProgram m_npcProgram;
  int m_timerId;
  AIScript m_ai;
};
#endif // GAMEENGINE_H
