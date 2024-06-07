#include "EnemyManager.h"
#include "Tank.h"


class MeleeEnemy : public EnemyManager
{
public: 

    MeleeEnemy(int h=200, int str=10, float speed=0.1f, const string& meleeFile="", float xPos=0,float yPos=0,int id=0);
    void attack() override;
    void move(Tank& tank) override;
    void drawMelee(RenderWindow& window);

};



