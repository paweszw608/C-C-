#include "Alien.h"

Alien::Alien() : Alien({ 1,1 })
{
}

Alien::Alien(Vector2f scale) : Moveable(scale)
{
	setAnimations();
	updateAnimation(0);
}

Alien::~Alien()
{
}

void Alien::updateAnimation(int index)
{
	moveableObject.setTexture(alienAnim[index]);
}

void Alien::setAnimations()
{
	alienAnim.addAnimation("images/alien/alien1.png");
	alienAnim.addAnimation("images/alien/alien2.png");
}
