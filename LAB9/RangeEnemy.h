#include "EnemyManager.h"
#include "Tank.h"


class RangeEnemy : public EnemyManager
{

public:
    RangeEnemy(int h = 100, int str = 20, float speed = 0.1f);
    void attack() override;
    void move() override;

};

