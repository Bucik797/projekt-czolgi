#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace sf;
using namespace std;

class Tank : public sf::Sprite {
public:
    // Konstruktor
    Tank(float x, float y, float speed, int health, const sf::Texture& texture, float rs,bool dw);

    // Metody
    void move(int d);
    void shoot();
    void takeDamage(int damage);
    void rotate(int angle);

    void driving();
    void boundCollision(const RenderWindow& window);
    


    // Gettery
    float getSpeed() const;
    int getHealth() const;
    float getRotation();
    bool isDrivingBackwards();
    bool isRotatingLeft();
    Vector2f getCurrentPosition();

    // Settery
    void setSpeed(float speed);
    void setHealth(int health);
    void setRotation_speed(float rotation_speed);
  

private:
    // W³asciwoœci czo³gu
    float speed;    // Prêdkoœæ
    int health;     // Zdrowie
    float rotation_speed;
    float current_angle;

    bool driving_backwards;
    bool rotation_left;
    

};
