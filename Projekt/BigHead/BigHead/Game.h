#pragma once
#include <sstream>
#include <iostream>
#include "include\SFML\Graphics.hpp"
#include "GameObjectsContainers.h"
#include "Movealbe.h"
#include "tableOfPositions.h"
#include "AnimationManager.h"
#include "Highscore.h"

using namespace sf;
class Game: public GameObjectsContainers
{
public:
	Game(RenderWindow & window);
	~Game();
	void run(RenderWindow & window);
private:
	// widow size
	Vector2u windowSize;
	// Game state variables:
	bool isGamePaused = false, isGameOver = false;
	// Gravity variables:
	float groundHeight, originalGroundHeight, gravitySpeed, jumpSpeed, moveSpeed, originalMaxJumpHeight, topGameBound, actualMaxJumpHeight;
	// Blocks variables:
	TableOfPositions blocksPosTab;
	bool canAddBlock = false;
	// Right to left moving varibles:
	float horizontalMoveSpeed = 0.15, ufoHorizontalMoveSpeed;
	// Animation managment variables:
	int playerAnimationIndex = 0, ufoAnimationIndex = 0;
	Clock clockAlien/*for Aliens*/, clockUfoAnim, clockUfoAdd /*for UFOs*/, clockPlayer /*for player*/, clockCoin; /* for coins (putting on the ground)*/
	Clock mainGameClockTmp;
	Clock mainGameClock;
	Time time;
	// Player variables:
	Player player;
	// Ufo variables:
	Ufo ufo;
	TableOfPositions ufosPosTab;
	bool canAddUfo = true;
	// Static elements (score, background, etc.):
	Sprite background, lifeHeart;
	Texture txrBackground, lifeHeartTxr;
	RectangleShape line;
	CircleShape scoreCoin; // coin that is located in left upper corner
	Text playerScoreText, runTimeText; Font gameFont;
	// Variables used to scale game objects:
	Vector2f playerSize, blockSize, backgroundSize, alienSize, heartSize, ufoSize;
	float coinSize;
	// Procedures:
	void gravityLogic();
	void keyboardInput();
	void checkPlayerPositionLimits();

	void setPrimaryBlocks();
	void setScoreObjects();
	void setScore(ostringstream & oss);
	void setLifeHeartVec();

	void playerCoinInteraction();
	void playerBlockInteraction();
	void playerAlienInteraction();
	void playerUfoInteraction();

	void addNewBlock();
	void putThingsOnBlock();
	void putCoinOnTheGround();
	
	void updateGameplayTime(ostringstream & oss);
	void updatePlayerAnimation();
	void updateUfoPosistion();
	void updateUfoAnimation();
	
	void gamePaused();
	void gameOver(RenderWindow & window);

	void deleteUnnecessaryThings();
	void drawThings(RenderWindow & window);
	
	Highscore highscore;
};
