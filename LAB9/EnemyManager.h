#ifndef ENEMY_MANAGER_H
#define ENEMY_MANAGER_H
#include "Tank.h"
#include <iostream>

class EnemyManager : public Sprite
{

protected:
    int hp;
    int strength;
    float speed;
    Texture enemy_texture;
    const string enemyFile;
    float xPos;
    float yPos;
    int id;


public:
    EnemyManager(int hp, int strength, int speed, const string enemyFile, float xPos, float yPos,int id);

    virtual void attack() = 0;
    virtual void move(Tank& tank) = 0;
    virtual ~EnemyManager() {}
    void takeDamage(Tank& tank);
    void dealDamage(Tank& tank);
    void drawEnemy(RenderWindow& window);

    //Gettery 

    int getId() const;
    int getHp() const;
    int getStrength() const;
    float getSpeed() const;
    Vector2f getCurrentPosition();
    vector <Sprite> objects;

    
    
};

#endif // ENEMY_MANAGER_H
