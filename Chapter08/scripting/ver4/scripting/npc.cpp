#include "npc.h"

NPC::NPC(QObject *parent) : LivingEntity(parent) {}

void NPC::attack(LivingEntity *enemy) { LivingEntity::attack(enemy); }
void NPC::dodge() { LivingEntity::dodge(); }
void NPC::wait() { LivingEntity::wait(); }
bool NPC::moveForward() { return LivingEntity::moveForward(); }
bool NPC::moveBackward() { return LivingEntity::moveBackward(); }
void NPC::turnLeft() { LivingEntity::turnLeft(); }
void NPC::turnRight() { LivingEntity::turnRight(); }
