#include "Tank.h"
#include <cmath>

// Konstruktor
Tank::Tank(float x, float y, float speed, int health, const sf::Texture& texture, float rs)
    : speed(speed), health(health), rotation_speed(rs) {
    setPosition(x, y);
    setTexture(texture);
    setScale(0.3, 0.3);
}

// Metody
void Tank::move(int d) {
    current_angle = (Sprite::getRotation() - 90) * (3.14159265f / 180.0f);
    sf::Vector2f movement(std::cos(current_angle) * speed * d, std::sin(current_angle) * speed * d);
    Sprite::move(movement);
    
}

void Tank::rotate(int angle) {
    this->setOrigin(this->getLocalBounds().width / 2, this->getLocalBounds().height / 2);
    Sprite::rotate(this->rotation_speed * angle);
    
}

/*
void Tank::keepInside() {
    sf::FloatRect tankbounds = this->getGlobalBounds();
    sf::Vector2u windowSize = parent->getSize();

    // SprawdŸ i koryguj pozycjê sprite'a w poziomie
    if (tankbounds.left < 0) {
        this->setPosition(0, this->getPosition().y);
    }
    else if (tankbounds.left + tankbounds.width > windowSize.x) {
        this->setPosition(windowSize.x - tankbounds.width, this->getPosition().y);
    }

    // SprawdŸ i koryguj pozycjê sprite'a w pionie
    if (tankbounds.top < 0) {
        this->setPosition(this->getPosition().x, 0);
    }
    else if (tankbounds.top + tankbounds.height > windowSize.y) {
        this->setPosition(this->getPosition().x, windowSize.y - tankbounds.height);
    }
}
*/

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

void Tank::setRotation_speed(float rs) {
    this->rotation_speed = rs;
}


