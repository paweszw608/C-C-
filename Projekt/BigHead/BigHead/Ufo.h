#pragma once
#include "Movealbe.h"
#include "AnimationManager.h"
 class Ufo : public Moveable<Sprite>
{
public:
	Ufo();
	Ufo(Vector2f scale);
	~Ufo();
	void updateAnimation(int index);
private:
	AnimationManager alienAnim;
	void setAnimations();

};