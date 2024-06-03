#include "MeleeEnemy.h"
#include "EnemyManager.h"
#include "Tank.h"


MeleeEnemy::MeleeEnemy(int h, int str, float speed, const string& meleeFile, float xPos, float yPos) : EnemyManager(h, str, speed, meleeFile, xPos, yPos)
{

}

void MeleeEnemy::attack()
{
	cout << "attack";
}

void MeleeEnemy::move()
{
	cout << "move";
}

void MeleeEnemy::drawMelee(RenderWindow& window)
{
	
}