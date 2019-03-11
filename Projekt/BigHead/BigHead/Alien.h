#pragma once
#include "Movealbe.h"
#include "AnimationManager.h"
class Alien : public Moveable<Sprite>
{
public:
	Alien();
	Alien(Vector2f scale);
	~Alien();
	void updateAnimation(int index);
private:
	AnimationManager alienAnim;
	void setAnimations();
};