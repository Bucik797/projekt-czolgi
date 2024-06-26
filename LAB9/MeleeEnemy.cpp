#include "MeleeEnemy.h"
#include "EnemyManager.h"
#include "Tank.h"



MeleeEnemy::MeleeEnemy(int h, int str, float speed, const string& meleeFile, float xPos, float yPos, int id) : EnemyManager(h, str, speed, meleeFile, xPos, yPos,id)
{

}

void MeleeEnemy::attack()
{
	cout << "attack";
}

void MeleeEnemy::move(Tank& tank)
{
	Vector2f direction = Vector2f(static_cast<float>(tank.getCurrentPosition().x-25), static_cast<float>(tank.getCurrentPosition().y-20)) - this->getPosition();
    float distance = sqrt(direction.x * direction.x + direction.y * direction.y);

    
    if (distance != 0)
    {
        direction.x /= distance;
        direction.y /= distance;
    }
    
    Vector2f movement = direction * this->speed * 0.01f;
    Sprite::move(movement);
    
    
    
}

void MeleeEnemy::drawMelee(RenderWindow& window)
{
	
}