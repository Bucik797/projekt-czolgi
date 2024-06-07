#include "RangeEnemy.h"
#include "EnemyManager.h"
#include "Tank.h"


RangeEnemy::RangeEnemy(int h, int str, float speed, const string& meleeFile, float xPos, float yPos, int id) : EnemyManager(h, str, speed, meleeFile, xPos, yPos,id)
{

}

void RangeEnemy::attack()
{
	cout << "attack";
}

void RangeEnemy::move(Tank& tank)
{
    Vector2f direction = Vector2f(static_cast<float>(tank.getCurrentPosition().x), static_cast<float>(tank.getCurrentPosition().y)) - this->getPosition();
    float distance = sqrt(direction.x * direction.x + direction.y * direction.y);

    
    if (distance != 0)
    {
        direction.x /= distance;
        direction.y /= distance;
    }

    Vector2f movement = direction * this->speed * 0.01f;
    Sprite::move(movement);
}
