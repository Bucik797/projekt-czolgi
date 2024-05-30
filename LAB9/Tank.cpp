#include "Tank.h"
#include <iostream>

using namespace sf;
using namespace std;

// Konstruktor
Tank::Tank(float x, float y, float speed, int health, const sf::Texture& texture, float rs)
    : speed(speed), health(health), rotation_speed(rs)
{
    setPosition(x, y);
    setTexture(texture);
    setScale(0.3, 0.3);
}

// Metody
void Tank::move(int d) {

    current_angle = (Sprite::getRotation() - 90) * (3.14159265f / 180.0f);
    Vector2f movement(cos(current_angle) * speed*d, sin(current_angle) * speed*d);
    Sprite::move(movement); // U¿ycie funkcji move z klasy sf::Sprite
}


void Tank::rotate(int angle)
{
    this->setOrigin(this->getLocalBounds().width / 2, this->getLocalBounds().height / 2);
    Sprite::rotate(this->rotation_speed*angle);
}

void Tank::shoot() {
    // Logika strzelania
    std::cout << "Tank shoots!" << std::endl;
}

void Tank::takeDamage(int damage) {
    health -= damage;
    if (health < 0) {
        health = 0;
    }
}

// Gettery
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

void Tank::setRotation_speed(float rs)
{
    this->rotation_speed = rs;
}
