#include "Tank.h"
#include <iostream>

// Konstruktor
Tank::Tank(float x, float y, float speed, int health, const sf::Texture& texture)
    : speed(speed), health(health) 
{
    setPosition(x, y);
    setTexture(texture);
    setScale(0.3, 0.3);
}

// Metody
void Tank::move(float dx, float dy) {
    sf::Vector2f movement(dx * speed, dy * speed);
    sf::Sprite::move(movement); // U¿ycie funkcji move z klasy sf::Sprite
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
