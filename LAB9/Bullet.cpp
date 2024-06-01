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
            this->setTexture(bullet_texture);
            
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



