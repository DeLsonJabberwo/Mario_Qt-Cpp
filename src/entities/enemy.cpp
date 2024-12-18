#include "enemy.h"
#include "goomba.h"
#include <QDebug>

QList<Enemy*> Enemy::ENEMIES;

Enemy::Enemy(float x, float y)
    : m_isAlive(true)
{
    setPosition(x, y);
    ENEMIES.push_back(this);
}

Enemy::~Enemy()
{
    ENEMIES.removeOne(this);
}

void Enemy::CreateEnemy(Type type, QPointF position)
{
    if(type == Type::Goomba)
    {
        Goomba* goomba = new Goomba(position.x(), position.y());
    }
    /* 2024-12-06 KGD: Added method to create entities at the flag used to call endScreen GUI*/
    else if (type == Type::flagEntity)
    {
        flagEntity* flagentity = new flagEntity(position.x(), position.y());
    }
}

void Enemy::setAlive(bool on)
{
    m_isAlive = on;
}

bool Enemy::isAlive() const
{
    return m_isAlive;
}

