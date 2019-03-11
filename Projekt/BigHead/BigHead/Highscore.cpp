#include "Highscore.h"

Highscore::Highscore()
{
	ifstream file;
	file.open("data/highscore.txt");
	file >> highscoreInt;
	file.close();
	highscore << highscoreInt;
}

Highscore::~Highscore()
{
}

string Highscore::getHighscore()
{
	return highscore.str();
}

int Highscore::getHighscoreInt()
{
	return highscoreInt;
}

void Highscore::setHighscore(int score)
{
	ofstream file("data/highscore.txt", ios::trunc);
	if (!file.is_open()) throw invalid_argument("no data files");
	file << score;
	file.close();
	highscore << score;
}
