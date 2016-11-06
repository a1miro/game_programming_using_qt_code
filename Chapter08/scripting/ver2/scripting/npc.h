#ifndef NPC_H
#define NPC_H

#include "livingentity.h"

class NPC : public LivingEntity {
  Q_OBJECT
public:
  NPC(QObject *parent = 0);
public slots:
  void attack(LivingEntity *enemy);
  void dodge();
  void wait();
  bool moveForward();
  bool moveBackward();
  void turnLeft();
  void turnRight();
};
#endif // NPC_H
