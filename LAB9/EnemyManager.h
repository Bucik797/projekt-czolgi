#ifndef ENEMY_MANAGER_H
#define ENEMY_MANAGER_H
#include "Tank.h"
#include <iostream>

class EnemyManager {

protected:
    int hp;
    int strength;
    float speed;

public:
    EnemyManager(int hp, int strength, int speed) : hp(hp), strength(strength), speed(speed) {}

    virtual void attack() = 0;
    virtual void move() = 0;
    virtual ~EnemyManager() {}
    void takeDamage(Tank& tank);
    void dealDamage(Tank& tank);

    //Gettery 

    int getHp() const;
    int getStrength() const;
    float getSpeed() const;
    
};

#endif // ENEMY_MANAGER_H
