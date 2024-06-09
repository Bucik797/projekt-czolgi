#include "EnemyManager.h"
#include "Tank.h"
#include <iostream>


EnemyManager::EnemyManager(int hp, int strength, int speed, const string enemyFile, float xPos, float yPos,int id) : hp(hp), strength(strength), speed(speed), enemyFile(enemyFile), xPos(xPos),yPos(yPos),id(id)
{
    if (!enemy_texture.loadFromFile(enemyFile))
    {
        cout << "Failed to load enemy texture" << endl;
    }
    else
    {
        this->setTexture(enemy_texture);
        this->setPosition(xPos, yPos);
    }
    explosion_texture.loadFromFile("boom.png");
    explosion_sprite.setTexture(explosion_texture);
    explosion_sprite2.setTexture(explosion_texture);

}

void EnemyManager::takeDamage(Tank& tank)
{
    cout << "Enemy before shoot has " << hp << " HP remaining." << std::endl;
    hp -= tank.getStrength();
    if (hp < 0) hp = 0;
    cout << "Enemy now has " << hp << " HP remaining." << std::endl;
}

void EnemyManager::dealDamage(Tank& tank)
{
    cout << "tank before shoot has " << tank.getHealth() << " hp" << endl;
    tank.setHealth(tank.getHealth() - strength);
    if (tank.getHealth() < 0)
    {
        tank.setHealth(0);
    }
    cout << "tank after shoot has " << tank.getHealth() << " hp" << endl;
}

void EnemyManager::dealRangeDamageAnimation(Tank& tank)
{
    
    explosion_sprite.setPosition(tank.getPosition().x-25, tank.getPosition().y-20);
    show_explosion = true;
    explosion_timer = 0.0;
    animation_finished = false;


}


void EnemyManager::takeDamageAnimation(Tank& tank)
{
    explosion_sprite2.setPosition(this->getCurrentPosition().x, this->getCurrentPosition().y);
    show_E_explosion = true;
    explosion_E_timer = 0.0;

}


void EnemyManager::update(float dt,float dt1) {
    if (show_explosion) 
    {
        explosion_timer += dt;
        if (explosion_timer >= explosion_duration) 
        {
            show_explosion = false;
            animation_finished = true;
        }
    }

    if (show_E_explosion)
    {
        explosion_E_timer +=dt1;
        if (explosion_E_timer >= explosion_duration)
        {
            show_E_explosion = false;
        }
    }
}


bool EnemyManager::isAnimationFinished()
{
    return animation_finished;
}

Vector2f EnemyManager::getCurrentPosition()
{
    return this->getPosition();
}

int EnemyManager::getId() const
{
    return id;
}

int EnemyManager::getHp() const
{
    return hp;
}
int EnemyManager::getStrength()const
{
    return strength;
}
float EnemyManager::getSpeed()const
{
    return speed;
}


void EnemyManager::drawEnemy(RenderWindow& window)
{
    window.draw(*this);
    if (show_explosion)
    {
        window.draw(explosion_sprite);
    }

    if (show_E_explosion)
    {
        window.draw(explosion_sprite2);
    }
}