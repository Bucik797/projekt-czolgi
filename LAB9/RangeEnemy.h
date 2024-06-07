#include "EnemyManager.h"
#include "Tank.h"


class RangeEnemy : public EnemyManager
{

public:
    RangeEnemy(int h = 100, int str = 20, float speed = 0.1f, const string& meleeFile = "", float xPos=0, float yPos=0, int id=0);
    void attack() override;
    void move(Tank& tank) override;

};

