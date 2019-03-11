#pragma once
#include "include\SFML\Graphics.hpp"
#include "Movealbe.h"
#include "Block.h"
#include "Coin.h"
#include "Alien.h"
#include "Ufo.h"
#include "AnimationManager.h"
using namespace sf;

class Player: public Moveable<Sprite>
{
public:
	Player();
	~Player();
	Player(Vector2f scale);
	//Moving variables:
	bool isJumping;
	bool isMovingLeft;
	bool isMovingRight;	
	//Setters:
	void setStartPos(Vector2f startPos);
	//Getters:
	Vector2f getStartPos();
	//Interaction with blocks:
	void CollisionWith(Block & block);
	bool isOnBlock = false;
	//Interaction with coins:
	bool isCollidingWith(Coin & coin);
	//Interaction with enemies:
	bool isCollidingWith(Alien & alien);
	bool isCollidingWith(Ufo & ufo);
	//Updating to actual texture animation:
	void updateAnimation(unsigned int index, bool isLeft);
	//Turning off/on player movement:
	void abilityToMove(bool canMove);

	unsigned int lifes;
	unsigned int score;
	bool isDead();
private:
	// Setting all animations that will be used for a player object:
	void setAnimations();
	AnimationManager playerAnimRight, playerAnimLeft;
	bool isAbleToMove = true;
	Vector2f startPos;
};
