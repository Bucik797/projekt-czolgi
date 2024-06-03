#include "RangeEnemy.h"
#include "EnemyManager.h"
#include "Tank.h"


RangeEnemy::RangeEnemy(int h, int str, float speed, const string& meleeFile, float xPos, float yPos) : EnemyManager(h, str, speed, meleeFile, xPos, yPos)
{

}

void RangeEnemy::attack()
{
	cout << "attack";
}

void RangeEnemy::move()
{
	cout << "move";
}
