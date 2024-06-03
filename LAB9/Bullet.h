#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace sf;
using namespace std;

class Bullet : public CircleShape
{
public:
	Bullet(int v, int d);

	int getVelocity() const;
	int getDamage() const;
	void setVelocity(int v);
	void setDamage(int d);
	void setCurrentPosition();
	void shooted(RenderWindow& window);
	void drawBullets(RenderWindow& window);


private:
	int velocity;
	
	int damage;
	float current_angle;
	

};

