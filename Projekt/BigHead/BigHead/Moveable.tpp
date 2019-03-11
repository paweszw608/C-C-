#include "Movealbe.h"
#pragma once

template<typename T1 = sf::Sprite>
Moveable<T1>::Moveable() {}

template<typename T1 = sf::Sprite>
Moveable<T1>::~Moveable() {}

template<typename T1 = sf::Sprite>
Moveable<T1>::Moveable(sf::Vector2f scale) 
{
	moveableObject.setScale(scale);
}

template<typename T1 = sf::Sprite>
void Moveable<T1>::drawTo(sf::RenderWindow & window)
{
	window.draw(moveableObject);
}

template<typename T1 = sf::Sprite>
void Moveable<T1>::move(sf::Vector2f distance)
{
	moveableObject.move(distance);
}

template<typename T1 = sf::Sprite>
void Moveable<T1>::setPos(sf::Vector2f newPos)
{
	moveableObject.setPosition(newPos);
}

template<typename T1>
void Moveable<T1>::setScale(Vector2f scale)
{
	moveableObject.setScale(scale);
}




template<typename T1 = sf::Sprite>
float Moveable<T1>::getY()
{
	return moveableObject.getPosition().y;
}

template<typename T1 = sf::Sprite>
float Moveable<T1>::getX()
{
	return moveableObject.getPosition().x;
}

template<typename T1 = sf::Sprite>
float Moveable<T1>::getWidth()
{
	return moveableObject.getGlobalBounds().width;
}

template<typename T1 = sf::Sprite>
float Moveable<T1>::getHeight()
{
	return moveableObject.getGlobalBounds().height;
}

template<typename T1 = sf::Sprite>
float Moveable<T1>::getRightBound()
{
	return (moveableObject.getGlobalBounds().left + moveableObject.getGlobalBounds().width);
}

template<typename T1 = sf::Sprite>
float Moveable<T1>::getBottomBound()
{
	return (moveableObject.getGlobalBounds().top + moveableObject.getGlobalBounds().height);
}
template<typename T1 = sf::Sprite>
sf::FloatRect Moveable<T1>::getGlobalBounds()
{
	return moveableObject.getGlobalBounds();
}

