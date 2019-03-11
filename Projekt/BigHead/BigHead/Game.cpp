#include "Game.h"

Game::Game(RenderWindow & window)
{
	windowSize = window.getSize();

	originalGroundHeight = windowSize.y * (600.0 / 768.0); gravitySpeed = windowSize.y * (0.8 / 768.0); jumpSpeed = windowSize.y * (0.6 / 768.0); moveSpeed = windowSize.x * (0.6 / 1366.0);
	originalMaxJumpHeight = windowSize.y * (350.0 / 768.0); topGameBound = windowSize.y * (40.0 / 768.0); ufoHorizontalMoveSpeed = horizontalMoveSpeed = windowSize.y * (0.15 / 768.0);
	actualMaxJumpHeight = originalMaxJumpHeight;

	line.setPosition({ 0, topGameBound });
	line.setSize({ (float)windowSize.x, 3.0f });
	// calculating size of objects:
	playerSize = backgroundSize = alienSize = ufoSize = heartSize = { (float)windowSize.x / 1366, (float)windowSize.y / 768 };
	blockSize = { windowSize.x * 0.40f, windowSize.y * 0.03f };
	coinSize = windowSize.y * 0.01f;
	// calculating possible positions of ufos:
	ufosPosTab.setTop(windowSize.y * (70.0 / 768.0));
	ufosPosTab.setMid(windowSize.y * (100.0 / 768.0));
	ufosPosTab.setBot(windowSize.y * (120.0 / 768.0));
	// calculating possible positions of blocks:
	blocksPosTab.setTop(windowSize.y * 0.50f);
	blocksPosTab.setMid(windowSize.y * 0.60f);
	blocksPosTab.setBot(windowSize.y * 0.72f);
	// calculeting gravity variables:
	groundHeight = windowSize.y / 1.276;
	// setting background:	
	txrBackground.loadFromFile("images/background2.png");
	background.setTexture(txrBackground);
	background.setScale({ backgroundSize });
	// creating player object:
	player.setScale({ playerSize });
	player.setPos({ 10, groundHeight });
	player.setStartPos({ 10, groundHeight });
	// creating ufo object:
	ufo.setScale(ufoSize);
	ufo.setPos({ -1000.0f, (float)windowSize.y });
	setPrimaryBlocks();

	try {
		setLifeHeartVec();
	}
	catch(invalid_argument ia){
		ia.what();
	}
	
	try {
		setScoreObjects();
	}
	catch (invalid_argument ia)
	{
		ia.what();
	}
}

Game::~Game()
{}

void Game::run(RenderWindow & window)
{
	ostringstream score, runTime;
	mainGameClock.restart();
	while (!isGameOver)
	{
		window.clear();

		if (player.isDead()) {
			gameOver(window);
		}

		window.draw(background);
		window.draw(line);

		// events:
		if (Keyboard::isKeyPressed(Keyboard::Escape) && !isGamePaused) isGamePaused = true;

		if (isGamePaused) gamePaused();
		
		gravityLogic();
		keyboardInput();
		updatePlayerAnimation();
		checkPlayerPositionLimits();
		// blocks:
		addNewBlock();
		playerBlockInteraction();
		// coins:
		putCoinOnTheGround();
		playerCoinInteraction();
		// enemies:
		updateUfoAnimation();
		updateUfoPosistion();
		playerUfoInteraction();
		playerAlienInteraction();
		// scores, lives, time:
		setScore(score);
		updateGameplayTime(runTime);

		deleteUnnecessaryThings();
		drawThings(window);

		window.display();
	}
}

void Game::addNewBlock()
{
	blocksIt = blocksVec.begin();
	if (blocksIt->getGlobalBounds().left + (blocksIt->getWidth() / 2.0) < 0 && canAddBlock) {
		canAddBlock = false;
		blocksVec.push_back(Block());
		blocksIt = blocksVec.end() - 1;
		blocksIt->setSize(blockSize);

		// setting color:
		blocksIt->setColor(rand() % 5 + 0);

		// setting position:
		float newBlockPosY = blocksPosTab[rand() % 3 + 0];
		float newBlockPosX = (float)windowSize.x;
		if (player.getY() > blocksPosTab.bottom) newBlockPosY = blocksPosTab.bottom;
		blocksIt->setPos({ newBlockPosX , newBlockPosY });

		putThingsOnBlock();
	}	
}

void Game::setPrimaryBlocks()
{
	// rigid setting 3 first blocks:
	float blockWidthHalf = blockSize.x / 2.0;
	float tmp = windowSize.x;
	// 1:
	blocksVec.push_back(Block());
	blocksIt = blocksVec.begin();
	blocksIt->setSize(blockSize);
	blocksIt->setPos({ tmp, blocksPosTab.bottom });
	blocksIt->setColor(0);
	tmp = blocksIt->getRightBound();
	// 2:
	blocksVec.push_back(Block());
	blocksIt = blocksVec.end() - 1;
	blocksIt->setSize(blockSize);
	blocksIt->setPos({ tmp + blockWidthHalf , blocksPosTab.middle });
	blocksIt->setColor(1);
	putThingsOnBlock();
	tmp = blocksIt->getRightBound();
	// 3:
	blocksVec.push_back(Block());
	blocksIt = blocksVec.end() - 1;
	blocksIt->setSize(blockSize);
	blocksIt->setPos({ tmp + blockWidthHalf , blocksPosTab.middle });
	blocksIt->setColor(3);
	putThingsOnBlock();

	blocksIt = blocksVec.begin();
}

void Game::updateGameplayTime(ostringstream & oss)
{
	static bool wait = false;

	if (isGamePaused)
	{
		oss.str("");
		oss << "PAUSED";
	}
	
	else
	{
		Time mainTime;
		if (wait)
		{
			mainTime = mainGameClockTmp.getElapsedTime();
			if (mainTime.asSeconds() >= 1.0) wait = false;
		}
		else
		{
			mainTime = mainGameClock.getElapsedTime();
			oss.str("");
			oss << "000" << mainTime.asMilliseconds();
			if (mainTime.asMilliseconds() % 10000 == 0.0)
			{
				// updating move speed!: 
				horizontalMoveSpeed *= 1.1;

				runTimeText.setFillColor(Color::Red);
				wait = true;
				mainGameClockTmp.restart();
			}
			else
			{
				runTimeText.setFillColor(Color::White);

			}

		}
	}
	runTimeText.setString(oss.str());
}



void Game::playerCoinInteraction()
{	
	for (coinsIt = coinsVec.begin(); coinsIt != coinsVec.end(); )
	{
		if (player.isCollidingWith(*coinsIt))
		{
			coinsIt = coinsVec.erase(coinsIt);
		}
		else
		{
			++coinsIt;
		}
	}

}

void Game::playerBlockInteraction()
{
	int blockOnWhichIsPlayer_index = -1, i = -1;
	bool flag = true;
	for (blocksIt = blocksVec.begin(); blocksIt != blocksVec.end(); ++blocksIt)
	{
		++i;
		player.CollisionWith(*blocksIt);
		if (player.isOnBlock && flag)
		{
			blockOnWhichIsPlayer_index = i;
			flag = false;
		}
	}
	if (player.isOnBlock)
	{
		groundHeight = blocksVec[blockOnWhichIsPlayer_index].getY() - player.getHeight() - blocksVec[blockOnWhichIsPlayer_index].outlineThickness;
		actualMaxJumpHeight = blocksVec[blockOnWhichIsPlayer_index].getY() - originalMaxJumpHeight * 1.1;
	}
	else
	{
		groundHeight = originalGroundHeight;
		if (player.getY() >= groundHeight) actualMaxJumpHeight = originalMaxJumpHeight;
	}
}

void Game::playerAlienInteraction()
{
	static bool alienFlag = false;
	for (alienIt = alienVec.begin(); alienIt != alienVec.end(); ++alienIt)
	{
		if (player.isCollidingWith(*alienIt))
		{
			--player.lifes;
			clockAlien.restart();
			alienFlag = true;
			player.setPos(player.getStartPos());
			player.isJumping = false;
		}
		else alienIt->updateAnimation(0);

		time = clockAlien.getElapsedTime();

		if (time.asSeconds() <= 2 && alienFlag)
		{
			alienIt->updateAnimation(1);
		}
		else if (time.asSeconds() > 2) alienFlag = false;
	}
	
}

void Game::playerUfoInteraction()
{
	if (player.isCollidingWith(ufo))
	{
		player.lifes--;
		player.setPos(player.getStartPos());
		player.isJumping = false;
	}
}

void Game::keyboardInput()
{
	if (Keyboard::isKeyPressed(Keyboard::Up) && player.getY() >= groundHeight) player.isJumping = true;
	else if (Keyboard::isKeyPressed(Keyboard::Left)) player.isMovingLeft = true;
	else if (Keyboard::isKeyPressed(Keyboard::Right)) player.isMovingRight = true;
}

void Game::gravityLogic()
{

	if (player.isMovingLeft) player.move({ -moveSpeed, 0 });
	else if (player.isMovingRight)  player.move({ moveSpeed, 0 });

	if (player.isJumping) player.move({ 0, -jumpSpeed });

	if (player.getY() <= actualMaxJumpHeight || player.getY() <= topGameBound) player.isJumping = false;

	if (player.getY() < groundHeight && !player.isJumping) player.move({ 0, gravitySpeed });

	player.isMovingLeft = player.isMovingRight = player.isOnBlock = false;


}

void Game::setLifeHeartVec()
{
	if (!lifeHeartTxr.loadFromFile("images/heart/heart.png"))
		throw invalid_argument("no image file!");
	lifeHeartTxr.setSmooth(true);
	lifeHeart.setTexture(lifeHeartTxr);
	lifeHeart.setScale(heartSize);

	lifeHeartVec.push_back(lifeHeart);
	lifeHeartVec[0].setPosition({ windowSize.x - (float)lifeHeartTxr.getSize().x, 1.0 });
	lifeHeartVec.push_back(lifeHeart);
	lifeHeartVec[1].setPosition({ windowSize.x - (float)(2 * lifeHeartTxr.getSize().x), 1.0 });
	lifeHeartVec.push_back(lifeHeart);
	lifeHeartVec[2].setPosition({ windowSize.x - (float)(3 * lifeHeartTxr.getSize().x), 1.0 });
}

void Game::setScoreObjects()
{
	// seting time, coin and text located in the top of the screen:
	if (gameFont.loadFromFile("fonts/AmericanCaptain.ttf"))
	{
		scoreCoin.setRadius(coinSize);
		scoreCoin.setFillColor(Color(249, 161, 1));
		scoreCoin.setPosition({ (float)windowSize.x * 5 / 1366, (float)windowSize.y * 10 / 768 });

		playerScoreText.setCharacterSize(windowSize.y * 25 / 768);
		playerScoreText.setFillColor(Color::White);
		playerScoreText.setFont(gameFont);
		playerScoreText.setPosition({ ((scoreCoin.getRadius() * 2.0f) + 9.0f), 1 });

		runTimeText.setCharacterSize(windowSize.y * 25 / 768);
		runTimeText.setFont(gameFont);
		runTimeText.setPosition({ windowSize.x / 2.0f - 10, 3 });
	}
	else throw invalid_argument("no font file!");
}

void Game::updatePlayerAnimation()
{
	if (!player.isJumping)
	{
		if (player.isMovingRight)
		{
			player.updateAnimation(playerAnimationIndex, false);

			time = clockPlayer.getElapsedTime();

			if (time.asSeconds() >= 0.1)
			{
				playerAnimationIndex++; clockPlayer.restart();
			}
		}
		else if (player.isMovingLeft)
		{
			player.updateAnimation(playerAnimationIndex, true);

			time = clockPlayer.getElapsedTime();

			if (time.asSeconds() >= 0.1)
			{
				playerAnimationIndex++; clockPlayer.restart();
			}
		}
	}
	else
	{
		player.updateAnimation(1, player.isMovingLeft);
	}

	if (playerAnimationIndex > 3) playerAnimationIndex = 0;
}

void Game::setScore(ostringstream & oss)
{
	oss.str("");
	oss << player.score;
	playerScoreText.setString(oss.str());	
}



void Game::putThingsOnBlock()
{
	blocksIt = blocksVec.end() - 1;
	float blockLeft = blocksIt->getGlobalBounds().left, blockWith = blocksIt->getWidth(), blockY = blocksIt->getY();
	int probability = rand() % 100 + 0;
	if (probability < 33)
	{
		// coin and coin:
		coinsVec.push_back(Coin(coinSize)); coinsIt = coinsVec.end() - 1;
		coinsIt->setPos({ blockLeft + blockWith * 0.25f, blockY - coinsIt->getHeight() * 2.0f });

		coinsVec.push_back(Coin(coinSize)); coinsIt = coinsVec.end() - 1;
		coinsIt->setPos({ blockLeft + blockWith * 0.75f, blockY - coinsIt->getHeight() * 2.0f });
	}
	else if (probability > 66)
	{
		// coin and alien:
		coinsVec.push_back(Coin(coinSize)); coinsIt = coinsVec.end() - 1;
		coinsIt->setPos({ blockLeft + blockWith * 0.25f, blockY - coinsIt->getHeight() * 2.0f });

		alienVec.push_back(Alien(alienSize)); alienIt = alienVec.end() - 1;
		alienIt->setPos({ blockLeft + blockWith * 0.75f, blockY - alienIt->getHeight() - 5.0f });
	}
	else
	{
		// alien and coin:
		alienVec.push_back(Alien(alienSize)); alienIt = alienVec.end() - 1;
		alienIt->setPos({ blockLeft + blockWith * 0.25f, blockY - alienIt->getHeight() - 5.0f });

		coinsVec.push_back(Coin(coinSize)); coinsIt = coinsVec.end() - 1;
		coinsIt->setPos({ blockLeft + blockWith * 0.75f, blockY - coinsIt->getHeight() * 2.0f });
	}
}

void Game::putCoinOnTheGround()
{
	Time timeFromLast = clockCoin.getElapsedTime();
	if (timeFromLast.asSeconds() >= 5.0f)
	{
		coinsVec.push_back(Coin(coinSize));
		coinsIt = coinsVec.end() - 1;
		coinsIt->setPos({ (float)windowSize.x, originalGroundHeight + windowSize.y * 5 / 768 });
		clockCoin.restart();
	}
}

void Game::updateUfoPosistion()
{
	static float secondsToNext = -1.0;
	if (ufo.getRightBound() < 0 && canAddUfo)
	{
		clockUfoAdd.restart();
		secondsToNext = rand() % 5 + 5;
		canAddUfo = false;
	}
	if (!canAddUfo) time = clockUfoAdd.getElapsedTime();
	if (secondsToNext <= time.asSeconds())
	{
		ufo.setPos({ (float)windowSize.x, ufosPosTab[rand() % 3 + 0] });
		canAddUfo = true;
	}
}

void Game::updateUfoAnimation()
{
	time = clockUfoAnim.getElapsedTime();
	if (time.asSeconds() > 0.5)
	{
		if (ufoAnimationIndex > 1) ufoAnimationIndex = 0;
		ufo.updateAnimation(ufoAnimationIndex);
		ufoAnimationIndex++;
		clockUfoAnim.restart();
	}
}

void Game::checkPlayerPositionLimits()
{
	if (player.getGlobalBounds().left <= 0) player.setPos({ 0,player.getY() });
	if (player.getRightBound() > windowSize.x) player.isMovingRight = false;
}
 
void Game::gamePaused()
{
	player.abilityToMove(false);
	if (Keyboard::isKeyPressed(Keyboard::Up) ||
		Keyboard::isKeyPressed(Keyboard::Left) ||
		Keyboard::isKeyPressed(Keyboard::Right))
	{
		isGamePaused = false;
		player.abilityToMove(true);
	}

}

void Game::gameOver(RenderWindow & window)
{
	isGameOver = true;

	if (player.score > highscore.getHighscoreInt() ){
		highscore.setHighscore(player.score); }

	ostringstream oss;
	oss << "GAME OVER";
	runTimeText.setString(oss.str());
	Clock gameOverClock;
	Time gameOverTime = gameOverClock.getElapsedTime();
	while ((float)time.asSeconds() < 3.0f)
	{
		window.draw(playerScoreText);
		window.draw(scoreCoin);
		window.draw(runTimeText);
		gameOverTime = gameOverClock.getElapsedTime();
	}
	
}

void Game::deleteUnnecessaryThings()
{
	// blocks:
	for (blocksIt = blocksVec.begin(); blocksIt != blocksVec.end(); )
	{
		if (blocksIt->getRightBound() < 0) {
			blocksIt = blocksVec.erase(blocksIt); // all block is outside window, has to be removed from vec
			canAddBlock = true;
		}
		else {
			++blocksIt;
		}
	}
	// coins:
	for (coinsIt = coinsVec.begin(); coinsIt != coinsVec.end(); )
	{
		if (coinsIt->getRightBound() < 0) {	
			coinsIt = coinsVec.erase(coinsIt);
		}
		else {
			++coinsIt;
		}
	}
	// alien:
	for (alienIt = alienVec.begin(); alienIt != alienVec.end();)
	{
		if (alienIt->getRightBound() < 0)
		{
			alienIt = alienVec.erase(alienIt);
		}
		else {
				++alienIt;
			}
	}
}

void Game::drawThings(RenderWindow & window)
{
	float speed, ufoSpeed;
	if (isGamePaused) { speed = ufoSpeed = 0.0; }
	else { speed = horizontalMoveSpeed, ufoSpeed = ufoHorizontalMoveSpeed; }

	// player:
	if (player.isOnBlock && !player.isMovingRight) player.move({ -speed, 0 });
	player.drawTo(window);
	// enemies:
		// ufos:
	ufo.move({ -ufoSpeed, 0 });
	ufo.drawTo(window);
		// alien:
	for (alienIt = alienVec.begin(); alienIt != alienVec.end(); ++alienIt)
	{
		alienIt->move({ -speed, 0 });
		alienIt->drawTo(window);
	}
	// blocks:
	for (blocksIt = blocksVec.begin(); blocksIt != blocksVec.end(); ++blocksIt)
	{
		blocksIt->move({ -speed, 0 });
		blocksIt->drawTo(window);
	}
	// coins:
	for (coinsIt = coinsVec.begin(); coinsIt != coinsVec.end(); ++coinsIt)
	{
		coinsIt->move({ -speed, 0 });
		coinsIt->drawTo(window);
	}
	// static game objects:
		// score:
	window.draw(playerScoreText);
	window.draw(scoreCoin);
		// lives:
		for (int i = 0; i < (player.lifes); ++i)
		{
			window.draw(lifeHeartVec[i]);
		}	
		// time:
	window.draw(runTimeText);
	
}
