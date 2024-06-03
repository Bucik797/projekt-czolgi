#include "EnemyManager.h"
#include "Tank.h"
#include <iostream>


void EnemyManager::takeDamage(Tank& tank)
{
    std::cout << "Enemy before shoot has " << hp << " HP remaining." << std::endl;
    hp -= tank.getStrength();
    if (hp < 0) hp = 0;
    std::cout << "Enemy now has " << hp << " HP remaining." << std::endl;
}

void EnemyManager::dealDamage(Tank& tank)
{
    cout << "tank before shoot has " << tank.getHealth() << " hp" << endl;
    tank.setHealth(tank.getHealth() - strength);
    cout << "tank after shoot has " << tank.getHealth() << " hp" << endl;
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