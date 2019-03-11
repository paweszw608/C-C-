#pragma once
#include "include\SFML\Graphics.hpp"
using namespace sf;
template<typename T1 = Sprite>
class Moveable
{
	protected:
		T1 moveableObject;
	public:
		Moveable(Vector2f scale);
		void drawTo(RenderWindow & window);
		void move(Vector2f distance);
		void setPos(Vector2f newPos);
		void setScale(Vector2f scale);
		float getY();
		float getX();
		float getWidth();
		float getHeight();
		float getBottomBound();
		float getRightBound();
		FloatRect getGlobalBounds();
		Moveable();
		virtual ~Moveable();
};

#include "Moveable.tpp"