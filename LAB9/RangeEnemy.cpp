#include "RangeEnemy.h"
#include "EnemyManager.h"
#include "Tank.h"


RangeEnemy::RangeEnemy(int h, int str, float speed) : EnemyManager(h, str, speed) {}

void RangeEnemy::attack()
{
	cout << "attack";
}

void RangeEnemy::move()
{
	cout << "move";
}
