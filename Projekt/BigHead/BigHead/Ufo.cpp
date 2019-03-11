#include "Ufo.h"

Ufo::Ufo() : Ufo({ 1,1 })
{
}

Ufo::Ufo(Vector2f scale) : Moveable(scale)
{
	setAnimations();
	updateAnimation(0);
}

Ufo::~Ufo()
{

}
void Ufo::updateAnimation(int index)
{
	moveableObject.setTexture(alienAnim[index]);
}


void Ufo::setAnimations()
{
	alienAnim.addAnimation("images/ufo/ufo1.png");
	alienAnim.addAnimation("images/ufo/ufo2.png");
}