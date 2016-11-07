#include "livingentity.h"

LivingEntity::LivingEntity(QObject *parent) : QObject(parent)
{
    m_armorBonus = 0;
}

void LivingEntity::setName(const QString &newName)
{
    if (name() == newName) return;
    m_name = newName;
    emit nameChanged(newName);
}

void LivingEntity::setDirection(char newDirection)
{
    if (direction() == newDirection) return;
    m_direction = newDirection;
    emit directionChanged(newDirection);
}

void LivingEntity::setPosition(const QPoint &newPosition)
{
    if (position() == newPosition) return;
    m_position = newPosition;
    emit positionChanged(newPosition);
}

void LivingEntity::setHp(int newHp)
{
    if (hp() == newHp) return;
    m_hp = newHp;
    emit hpChanged(newHp);
}

void LivingEntity::setMaxHp(int newMaxHp)
{
    if (maxHp() == newMaxHp) return;
    m_maxHp = newMaxHp;
    emit maxHpChanged(newMaxHp);
}

void LivingEntity::setDex(int newDex)
{
    if (dex() == newDex) return;
    m_dex = newDex;
    emit dexChanged(newDex);
}

void LivingEntity::setBaseAttack(int newBaseAttack)
{
    if (m_baseAttack == newBaseAttack) return;
    m_baseAttack = newBaseAttack;
    emit baseAttackChanged(m_baseAttack);
}

void LivingEntity::setArmor(int newArmor)
{
    if (m_armor == newArmor) return;
    m_armor = newArmor;
    emit armorChanged(m_armor+m_armorBonus);
}

void LivingEntity::wait() {  if(hp() < maxHp()) setHp(hp()+1); }

bool LivingEntity::moveForward()
{
    int x = position().x();
    int y = position().y();

    switch(direction()) {
    case 'N': setPosition(QPoint(x, y-1)); break;
    case 'E': setPosition(QPoint(x+1, y)); break;
    case 'S': setPosition(QPoint(x, y+1)); break;
    case 'W': setPosition(QPoint(x-1, y)); break;
    }
    return true;
}

bool LivingEntity::moveBackward()
{
    int x = position().x();
    int y = position().y();

    switch(direction()) {
    case 'N': setPosition(QPoint(x, y+1)); break;
    case 'E': setPosition(QPoint(x-1, y)); break;
    case 'S': setPosition(QPoint(x, y-1)); break;
    case 'W': setPosition(QPoint(x+1, y)); break;
    }
    return true;
}

void LivingEntity::turnLeft()
{
    switch(direction()) {
    case 'N': setDirection('W'); return;
    case 'E': setDirection('N'); return;
    case 'S': setDirection('E'); return;
    case 'W': setDirection('S'); return;
    }
}

void LivingEntity::turnRight()
{
    switch(direction()) {
    case 'N': setDirection('E'); return;
    case 'E': setDirection('S'); return;
    case 'S': setDirection('W'); return;
    case 'W': setDirection('N'); return;
    }
}

QString LivingEntity::name() const
{
    return m_name;
}

char LivingEntity::direction() const
{
    return m_direction;
}

QPoint LivingEntity::position() const
{
    return m_position;
}

int LivingEntity::hp() const
{
    return m_hp;
}

int LivingEntity::maxHp() const
{
    return m_maxHp;
}

int LivingEntity::dex() const
{
    return m_dex;
}

int LivingEntity::baseAttack() const
{
    return m_baseAttack;
}

int LivingEntity::armor() const
{
    return m_armor+m_armorBonus;
}

void LivingEntity::reset()
{
    m_armorBonus = 0;
}
void LivingEntity::dodge() {
    m_armorBonus += dex();
    emit armorChanged(armor()); // m_baseArmor + m_armorBonus
}
void LivingEntity::attack(LivingEntity *enemy) {
    int damage = qrand() % baseAttack();
    int enemyArmor = enemy->armor();
    int inflictedDamage = qMax(0, damage-enemyArmor);
    enemy->setHp(qMax(0, enemy->hp() - inflictedDamage));
}
