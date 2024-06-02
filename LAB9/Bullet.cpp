#include "Bullet.h"
#include "Tank.h"
#include <iostream>

using namespace sf;
using namespace std;


   Bullet::Bullet(int v, int d, const string& bulletFile) : velocity(v), damage(d) 
    {
       if (!bullet_texture.loadFromFile(bulletFile))
        {
            cout << "Failed to load bullet texture";
        }
        else
        {
            
           //setPosition(100, 200);
           setTexture(bullet_texture);
           setScale(1, 1);

           cout << "konstruktor";
            
        }
        

        
        
    }


    // Gettery
    int Bullet::getVelocity() const 
    { 
        return velocity; 
    }
    
    int Bullet::getDamage() const 
    { 
        return damage; 
    }

    // Settery
    void Bullet::setVelocity(int v) 
    { 
        velocity = v; 
    }
    
    void Bullet::setDamage(int d) 
    { 
        damage = d; 
    }

    void Bullet::setCurrentPosition()
    {
        
    }

    void Bullet::drawBullets(RenderWindow & window)
    {
        window.draw(*this);
    }

    void Bullet::shooted(RenderWindow& window)
    {
        
        
        cout << "funkcja dziala" << endl;
        
            if (Keyboard::isKeyPressed(Keyboard::Space))
            {
                
                //bullets.push_back(*this);
                //bullets.back(setPosition())

                this->drawBullets(window);
                cout << "tank shoots" << endl;
                current_angle = (Sprite::getRotation() - 90) * (3.14159265f / 180.0f);
                Vector2f movement(cos(current_angle) * velocity, sin(current_angle) * velocity);
                
                this->move(movement);
                



            }
        
        
    }



