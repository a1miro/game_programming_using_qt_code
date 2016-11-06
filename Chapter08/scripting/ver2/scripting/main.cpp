#include <QCoreApplication>
#include "gameengine.h"

int main(int argc, char **argv) {
  QCoreApplication app(argc, argv);
  GameEngine engine;

  engine.player()->setMaxHp(50);
  engine.player()->setHp(50);
  engine.player()->setDex(10);
  engine.player()->setBaseAttack(10);
  engine.player()->setArmor(3);

  engine.npc()->setMaxHp(100);
  engine.npc()->setHp(100);
  engine.npc()->setDex(4);
  engine.npc()->setBaseAttack(7);
  engine.npc()->setArmor(1);

  engine.start(argv[1]);
  return app.exec();
}
