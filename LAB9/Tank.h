#include <SFML/Graphics.hpp>

class Tank : public sf::Sprite {
public:
    // Konstruktor
    Tank(float x, float y, float speed, int health, const sf::Texture& texture);

    // Metody
    void move(float dx, float dy);
    void shoot();
    void takeDamage(int damage);

    // Gettery
    float getSpeed() const;
    int getHealth() const;

    // Settery
    void setSpeed(float speed);
    void setHealth(int health);

private:
    // W³asciwoœci czo³gu
    float speed;    // Prêdkoœæ
    int health;     // Zdrowie
};


