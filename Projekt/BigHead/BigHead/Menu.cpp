#include "Menu.h"

Menu::Menu(RenderWindow & window)
{
	windowSize = window.getSize();
	// calculating size and position of objects:
	if (!imageTxr.loadFromFile("images/player/mainMenuImage.png")) 
		throw invalid_argument("no image files!");
	image.setTexture(imageTxr);
	image.setPosition({ (float)windowSize.x * 750.0f / 1366,(float)windowSize.y * 50.0f / 768 });
	image.setScale({ (float)windowSize.x / 1366, (float)windowSize.y / 768 });

	if(!backgroundTxr.loadFromFile("images/background.png"))
		throw invalid_argument("no image files!");
	background.setTexture(backgroundTxr);
	background.setPosition({ 1,1 });
	background.setScale({ 1,1 });
	
	if(!font.loadFromFile("fonts/AmericanCaptain.ttf"))
		throw invalid_argument("no font files!");

	frame.setFillColor(Color::Black);
	frame.setSize({ 400, 400 });
	frame.setPosition({ (float)(windowSize.x / 2.0f - frame.getGlobalBounds().width / 2.0f), (float)windowSize.y * 200.0f / 768.0f });
	frame.setOutlineThickness(5);
	frame.setOutlineColor(Color::White);

	float posXTmp = (float)(windowSize.x / 2.0f - frame.getGlobalBounds().width / 2.0f);

	title.setFont(font);
	title.setCharacterSize(100);
	title.setPosition({ posXTmp + 5, (float)windowSize.y * 90.0f/768.0f });
	title.setFillColor(Color(255, 204, 102));
	title.setString("PLUTO");
	
	playText.setFont(font);
	playText.setCharacterSize(70);
	playText.setPosition({ posXTmp + 10, (float)windowSize.y * 250.0f / 768.0f });
	playText.setString("play");

	highscoreText.setFont(font);
	highscoreText.setCharacterSize(70);
	highscoreText.setPosition({ posXTmp + 10, (float)windowSize.y * 350.0f / 768.0f });
	highscoreText.setString("highscore");

	quitText.setFont(font);
	quitText.setCharacterSize(70);
	quitText.setPosition({ posXTmp + 10,  (float)windowSize.y * 450.0f / 768.0f });
	quitText.setString("quit");

	highscore.setPosition({ posXTmp + 10, 10 + frame.getGlobalBounds().top + frame.getGlobalBounds().height});
	highscore.setFont(font);
	highscore.setCharacterSize(30);
	highscore.setString("highscore: " + highscoreGame.getHighscore());

}

Menu::~Menu()
{}

void Menu::draw(RenderWindow & window)
{
	
	selected = 0; // set on "play" button
	while (true)
	{
		window.clear();
		window.draw(background);
		highlight();
		window.draw(frame);
		window.draw(title);
		window.draw(playText);
		window.draw(highscoreText);
		window.draw(quitText);
		window.draw(image);
		
		
		if (canShowHighscore) window.draw(highscore);
		
		keyboardInput(window);
		window.display();

	}
}


void Menu::keyboardInput(RenderWindow & window)
{
	if (GetAsyncKeyState(VK_UP) == -32767)
	{
		canShowHighscore = false;
		decrementSelected();
	}
	else if (GetAsyncKeyState(VK_DOWN) == -32767)
	{
		canShowHighscore = false;
		incrementSelected();
		
	}
	else if (GetAsyncKeyState(VK_RETURN) == -32767) goToNextState(window);
}
void Menu::incrementSelected()
{
	if(selected != 2) selected++;
}

void Menu::decrementSelected()
{
	if (selected != 0) selected--;
}


void Menu::goToNextState(RenderWindow & window)
{
	switch (selected) {
	case 0:
	{
	// game object to runned:
	Game game1(window);
	game1.run(window);
	break; 
	}
	case 1:
	{
		canShowHighscore = true;
		break;
	}
	case 2:
	{
		window.close();
		break;
	}
	default:
		break;
	}
}

void Menu::highlight()
{
	switch (selected)
	{
	case 0:
		playText.setFillColor(Color(100, 100, 100));
		highscoreText.setFillColor(Color::White);
		quitText.setFillColor(Color::White);
		break;
	case 1:
		playText.setFillColor(Color::White);
		highscoreText.setFillColor(Color(100, 100, 100));
		quitText.setFillColor(Color::White);
		break;
	case 2:
		playText.setFillColor(Color::White);
		highscoreText.setFillColor(Color::White);
		quitText.setFillColor(Color(100, 100, 100));
		break;
	default:
		break;
	}
}
