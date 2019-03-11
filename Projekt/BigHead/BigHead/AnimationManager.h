#pragma once
#include "Movealbe.h"
#include <vector>
using namespace std;
class AnimationManager
{
public:
	AnimationManager();
	~AnimationManager();
	bool addAnimation(string location);
	Texture & operator[] (int index);
private:
	vector<Texture> texturesVec;
};

