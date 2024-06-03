#include "Bullet.h"
#include "Tank.h"
#include <iostream>

using namespace sf;
using namespace std;


   Bullet::Bullet(int v, int d) : velocity(v), damage(d) 
    {
       
            
        
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
        
        
    }



