#include "Player.h"

Player::Player(Vector2f scale) : Moveable(scale)
{
	isJumping = false;
	isMovingLeft = isMovingRight = false;
	lifes = 3;
	score = 0;
	setAnimations();
	updateAnimation(1, false);
}

Player::Player(): Player({1,1})
{
}

Player::~Player()
{
}



void Player::setStartPos(Vector2f startPos)
{
	this->startPos = startPos;
}

Vector2f Player::getStartPos()
{
	return startPos;
}

void Player::CollisionWith(Block & block)
{
	if (moveableObject.getGlobalBounds().intersects(block.getGlobalBounds()))
	{
		if (getBottomBound() < block.getBottomBound() && moveableObject.getGlobalBounds().top <= block.getY() && getRightBound()  >= block.getGlobalBounds().left && moveableObject.getGlobalBounds().left <= block.getRightBound())
		{
			isOnBlock = true;
		}
		else if (moveableObject.getGlobalBounds().left < block.getGlobalBounds().left && getRightBound() >= block.getGlobalBounds().left) // touched left bound
		{
			isMovingRight = false;
			isJumping = false;

		}
		else if (moveableObject.getGlobalBounds().left <= block.getRightBound() && moveableObject.getGlobalBounds().left > block.getGlobalBounds().left) // touched right bound
		{
			isMovingLeft = false;
			isJumping = false;
		}
	}
}

bool Player::isCollidingWith(Coin & coin)
{
	if (moveableObject.getGlobalBounds().intersects(coin.getGlobalBounds()))
	{
		score++;
		return true;		
	}
	else return false;
}

bool Player::isCollidingWith(Alien & alien)
{
	if (moveableObject.getGlobalBounds().intersects(alien.getGlobalBounds()))
	{
		return true;
	}
	else return false;
}

bool Player::isCollidingWith(Ufo & ufo)
{
	if (moveableObject.getGlobalBounds().intersects(ufo.getGlobalBounds()))
	{
		return true;
	}
	else return false;
}

void Player::updateAnimation(unsigned int index, bool isLeft)
{
	if (isAbleToMove)
	{
		if (isLeft)
		{
			moveableObject.setTexture(playerAnimLeft[index]);
		}
		else
		{
			moveableObject.setTexture(playerAnimRight[index]);
		}
	}
}

void Player::abilityToMove(bool canMove)
{
	if (canMove)
	{
		isMovingLeft = isMovingRight = isAbleToMove =  true;
	}
	else
	{
		isMovingLeft = isMovingRight = isJumping = isAbleToMove = false;
	}
}

	

bool Player::isDead()
{
	if (lifes <= 0) return true;
	else return false;
}
void Player::setAnimations()
{
	playerAnimRight.addAnimation("images/player/walk_right_2.png");
	playerAnimRight.addAnimation("images/player/walk_right_1.png");
	playerAnimRight.addAnimation("images/player/walk_right_3.png");
	playerAnimRight.addAnimation("images/player/walk_right_1.png");

	playerAnimLeft.addAnimation("images/player/walk_left_2.png");
	playerAnimLeft.addAnimation("images/player/walk_left_1.png");
	playerAnimLeft.addAnimation("images/player/walk_left_3.png");
	playerAnimLeft.addAnimation("images/player/walk_left_1.png");
}