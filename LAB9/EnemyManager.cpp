#include "EnemyManager.h"
#include "Tank.h"
#include <iostream>


EnemyManager::EnemyManager(int hp, int strength, int speed, const string enemyFile, float xPos, float yPos,int id) : hp(hp), strength(strength), speed(speed), enemyFile(enemyFile), xPos(xPos),yPos(yPos),id(id)
{
    if (!enemy_texture.loadFromFile(enemyFile))
    {
        cout << "Failed to load enemy texture" << endl;
    }
    else
    {
        this->setTexture(enemy_texture);
        this->setPosition(xPos, yPos);
    }
}

void EnemyManager::takeDamage(Tank& tank)
{
    cout << "Enemy before shoot has " << hp << " HP remaining." << std::endl;
    hp -= tank.getStrength();
    if (hp < 0) hp = 0;
    cout << "Enemy now has " << hp << " HP remaining." << std::endl;
}

void EnemyManager::dealDamage(Tank& tank)
{
    cout << "tank before shoot has " << tank.getHealth() << " hp" << endl;
    tank.setHealth(tank.getHealth() - strength);
    cout << "tank after shoot has " << tank.getHealth() << " hp" << endl;
}



Vector2f EnemyManager::getCurrentPosition()
{
    return this->getPosition();
}

int EnemyManager::getId() const
{
    return id;
}

int EnemyManager::getHp() const
{
    return hp;
}
int EnemyManager::getStrength()const
{
    return strength;
}
float EnemyManager::getSpeed()const
{
    return speed;
}


void EnemyManager::drawEnemy(RenderWindow& window)
{
    window.draw(*this);
}