#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Bullet.h"

using namespace sf;
using namespace std;

class Tank : public Sprite {
public:
    
    Tank(float x, float y, float speed, int health, const sf::Texture& texture, float rs,bool dw, int strength);

    
    void move(int d);
    void shoot();
    void takeDamage(int damage);
    void rotate(int angle);

    void driving();
    void boundCollision(const RenderWindow& window);
    
    


    
    float getSpeed() const;
    int getHealth() const;
    float getRotation();
    bool isDrivingBackwards();
    bool isRotatingLeft();
    Vector2f getCurrentPosition();
    int getStrength();

    
    void setSpeed(float speed);
    void setHealth(int health);
    void setRotation_speed(float rotation_speed);
    void setStrength(int s);

private:
    
    
    bool show_explosion = false;
    float speed;    
    int health;    
    float rotation_speed;
    float current_angle;
    int strength;

    bool driving_backwards;
    bool rotation_left;
    

};
