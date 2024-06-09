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
    Texture explosion_texture;
    Sprite explosion_sprite;
    Sprite explosion_sprite2;
    bool show_explosion = false;
    bool show_E_explosion = false;
    bool animation_finished = false;
    float explosion_duration = 0.2; 
    float explosion_timer = 0.0;
    float explosion_E_timer = 0.0;


public:
    EnemyManager(int hp, int strength, int speed, const string enemyFile, float xPos, float yPos,int id);

    virtual void attack() = 0;
    virtual void move(Tank& tank) = 0;
    virtual ~EnemyManager() {}
    void takeDamage(Tank& tank);
    void dealDamage(Tank& tank);
    void dealRangeDamageAnimation(Tank& tank);
    void takeDamageAnimation(Tank& tank);
    void drawEnemy(RenderWindow& window);
    void update(float dt,float dt1);
    

    //Gettery 

    bool isAnimationFinished();
    int getId() const;
    int getHp() const;
    int getStrength() const;
    float getSpeed() const;
    Vector2f getCurrentPosition();
    vector <Sprite> objects;

    
    
};

#endif // ENEMY_MANAGER_H
