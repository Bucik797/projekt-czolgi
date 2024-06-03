#include "EnemyManager.h"
#include "Tank.h"


class MeleeEnemy : public EnemyManager
{
public: 

    MeleeEnemy(int h=200, int str=10, float speed=0.1f);
    void attack() override;
    void move() override;

};



