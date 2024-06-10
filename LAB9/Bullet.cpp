#include "Bullet.h"
#include "Tank.h"
#include <iostream>

using namespace sf;
using namespace std;


   Bullet::Bullet(int v, int d) : velocity(v), damage(d) 
    {
   
    }
   
   
   
    int Bullet::getVelocity()
    { 
        return velocity; 
    }
    
    int Bullet::getDamage() const 
    { 
        return damage; 
    }

    float Bullet::getAngle()
    {
        return angle;
    }

   

    void Bullet::setAngle(float a)
    {
        this->angle = a;
    }

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



