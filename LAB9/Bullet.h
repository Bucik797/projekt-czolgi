#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace sf;
using namespace std;

class Bullet : public Sprite
{
public:
	Bullet(int v, int d, const string& bulletFile);

	int getVelocity() const;
	int getDamage() const;
	void setVelocity(int v);
	void setDamage(int d);
	void setCurrentPosition();


private:
	int velocity;
	Texture bullet_texture;
	int damage;

};

