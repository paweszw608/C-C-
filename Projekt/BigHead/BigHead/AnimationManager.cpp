#include "AnimationManager.h"

AnimationManager::AnimationManager()
{
}

AnimationManager::~AnimationManager()
{
}

bool AnimationManager::addAnimation(string location)
{
	Texture tmp;
	if (tmp.loadFromFile(location))
	{
		texturesVec.push_back(tmp);
		return true;
	}
	else return false;
}

Texture & AnimationManager::operator[](int index)
{
	return texturesVec[index];
}