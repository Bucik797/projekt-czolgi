#include "Tank.h"

#include "Map.h"
#include <iostream>

using namespace sf;
using namespace std;

// Konstruktor
Tank::Tank(float x, float y, float speed, int health, const sf::Texture& texture, float rs, bool dw, int strength)
    : speed(speed), health(health), rotation_speed(rs), driving_backwards(dw), strength(strength)
{
    


    setPosition(x, y);
    setTexture(texture);
    setScale(1,1);

    
    
}

// Metody
void Tank::move(int d) {
    current_angle = (Sprite::getRotation() - 90) * (3.14159265f / 180.0f);

    Vector2f movement(cos(current_angle) * speed*d, sin(current_angle) * speed*d);
    Sprite::move(movement); 
    
}

void Tank::setStrength(int s)
{
    strength = s;
}

float Tank::getRotation()
{
    return Sprite::getRotation();
}

void Tank::rotate(int angle)
{
    this->setOrigin(this->getLocalBounds().width / 2, this->getLocalBounds().height / 2);
    Sprite::rotate(this->rotation_speed * angle);


}

void Tank::driving() 
{
   

    if (Keyboard::isKeyPressed(Keyboard::Up)) {
        move(1);
        //driving_backwards = false;
    }
    if (Keyboard::isKeyPressed(Keyboard::Down)) {
        driving_backwards = true;
        move(-1);
    }
    else
    {
        driving_backwards = false;
    }
    

    if (Keyboard::isKeyPressed(Keyboard::Left)) {
        if (driving_backwards) {
            rotate(1);  
            rotation_left = false;
        }
        else {
            rotate(-1);
            rotation_left = true;
        }
    }
    if (Keyboard::isKeyPressed(Keyboard::Right)) {
        if (driving_backwards) {
            rotate(-1);  
            rotation_left = true;
        }
        else {
            rotate(1);  
            rotation_left = false;
        }
    }
}

bool Tank::isRotatingLeft()
{
    return rotation_left;
}


void Tank::boundCollision(const RenderWindow& window) {
    sf::FloatRect tankBounds = getGlobalBounds();
    if (tankBounds.left < 0) {
        setPosition(tankBounds.width / 2, getPosition().y);
    }
    if (tankBounds.left + tankBounds.width > window.getSize().x) {
        setPosition(window.getSize().x - tankBounds.width / 2, getPosition().y);
    }
    if (tankBounds.top < 0) {
        setPosition(getPosition().x, tankBounds.height / 2);
    }
    if (tankBounds.top + tankBounds.height > window.getSize().y) {
        setPosition(getPosition().x, window.getSize().y - tankBounds.height / 2);
    }
}





void Tank::shoot() {
    
    
}

void Tank::takeDamage(int damage) {
    health -= damage;
    if (health < 0) {
        health = 0;
    }
}

// Gettery

int Tank::getStrength()
{
    return strength;
}

Vector2f Tank::getCurrentPosition()
{
    return this->getPosition();
}

bool Tank::isDrivingBackwards()
{
    return driving_backwards;
}
float Tank::getSpeed() const {
    return speed;
}

int Tank::getHealth() const {
    return health;
}

// Settery
void Tank::setSpeed(float speed) {
    this->speed = speed;
}

void Tank::setHealth(int health) {
    this->health = health;
}

void Tank::setRotation_speed(float rs) {
    this->rotation_speed = rs;
}


