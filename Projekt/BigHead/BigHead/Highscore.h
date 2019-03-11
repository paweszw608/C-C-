#pragma once
#include "include\SFML\Graphics.hpp"
#include <fstream>
#include <sstream>
using namespace sf;
using namespace std;
class Highscore
{
public:
	Highscore();
	~Highscore();
	string getHighscore();
	int getHighscoreInt();
	void setHighscore(int score);
private:
	ostringstream highscore;
	int highscoreInt;
	
};