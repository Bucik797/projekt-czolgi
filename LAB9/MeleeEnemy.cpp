#include "MeleeEnemy.h"
#include "EnemyManager.h"
#include "Tank.h"


MeleeEnemy::MeleeEnemy(int h, int str, float speed) : EnemyManager(h, str, speed){}

void MeleeEnemy::attack()
{
	cout << "attack";
}

void MeleeEnemy::move()
{
	cout << "move";
}