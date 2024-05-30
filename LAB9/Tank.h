#include <SFML/Graphics.hpp>
#include <iostream>

class Tank : public sf::Sprite {
public:
    // Konstruktor
    Tank(float x, float y, float speed, int health, const sf::Texture& texture, float rs);

    // Metody
    void move(int d);
    void shoot();
    void takeDamage(int damage);
    void rotate(int angle);

    // Gettery
    float getSpeed() const;
    int getHealth() const;

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
    
};


