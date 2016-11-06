#ifndef LIVINGENTITY_H
#define LIVINGENTITY_H

#include <QObject>
#include <QPoint>

class LivingEntity : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name 	READ name       NOTIFY nameChanged)
    Q_PROPERTY(char direction 	READ direction 	NOTIFY directionChanged)
    Q_PROPERTY(QPoint position	READ position 	NOTIFY positionChanged)
    Q_PROPERTY(int hp           READ hp         NOTIFY hpChanged)
    Q_PROPERTY(int maxHp 		READ maxHp      NOTIFY maxHpChanged)
    Q_PROPERTY(int dex          READ dex        NOTIFY dexChanged)
    Q_PROPERTY(int baseAttack 	READ baseAttack NOTIFY baseAttackChanged)
    Q_PROPERTY(int armor 		READ armor      NOTIFY armorChanged)

public:
    explicit LivingEntity(QObject *parent = 0);
    void setName(const QString &newName);
    void setDirection(char newDirection);
    void setPosition(const QPoint &newPosition);
    void setHp(int newHp);
    void setMaxHp(int newMaxHp);
    void setDex(int newDex);
    void setBaseAttack(int newBaseAttack);
    void setArmor(int newArmor);

    void attack(LivingEntity *enemy);
    void dodge();
    void wait();
    bool moveForward();
    bool moveBackward();
    void turnLeft();
    void turnRight();

    QString name() const;
    char direction() const;
    QPoint position() const;
    int hp() const;
    int maxHp() const;
    int dex() const;
    int baseAttack() const;
    int armor() const;

    void reset();

signals:
    void nameChanged(QString name);
    void directionChanged(char direction);
    void positionChanged(QPoint position);
    void hpChanged(int hp);
    void maxHpChanged(int maxHp);
    void dexChanged(int dex);
    void baseAttackChanged(int baseAttack);
    void armorChanged(int armor);

private:
    QString m_name;
    char m_direction;
    QPoint m_position;
    int m_hp;
    int m_maxHp;
    int m_dex;
    int m_baseAttack;
    int m_armor;
    int m_armorBonus;
};

#endif // LIVINGENTITY_H
