#pragma once
#include "include\SFML\Graphics.hpp"
#include "include\SFML\Window.hpp"
#include "Game.h"
#include "Highscore.h"
#include <Windows.h>
using namespace sf;
class Menu
{
public:
	Menu(RenderWindow & window);
	~Menu();
	void draw(RenderWindow & window);
private:
	Vector2u windowSize;

	RectangleShape frame;
	Sprite background, image;
	// textures:
	Texture backgroundTxr, imageTxr;
	// options to choose:
	Text playText, quitText, highscoreText;
	// title of the game:
	Text title;
	// font of text:
	Font font;
	// highscore objects:
	Highscore highscoreGame;
	Text highscore;
	bool canShowHighscore = false;
	// selected option:
	int selected = 0;

	void keyboardInput(RenderWindow & window);
	void incrementSelected();
	void decrementSelected();
	void goToNextState(RenderWindow & window);
	void highlight();

	
};