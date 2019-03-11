#pragma once
#include "Movealbe.h"
#include <vector>
using namespace std;
class TexturesManager
{
public:
	TexturesManager();
	~TexturesManager();	
	void addAnimation(string location);
	Texture & operator[] (int index);
private:
	vector<Texture> animations;
};
enum lol
{
	redeye = 0,
	blackaye
};