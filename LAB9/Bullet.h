#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Tank.h"

using namespace sf;
using namespace std;

class Bullet : public CircleShape
{
public:
	Bullet(int v, int d);

	int getVelocity();
	int getDamage() const;
	void setVelocity(int v);
	void setDamage(int d);
	void setCurrentPosition();
	void shooted(RenderWindow& window);
	void drawBullets(RenderWindow& window);
	void setAngle(float a);
	float getAngle();
	//void setColor1(Tank* tank, Tank& tank1, Tank& tank2, Tank& tank3);

private:
	int velocity;
	float angle;
	int damage;
	float current_angle;
	

};

