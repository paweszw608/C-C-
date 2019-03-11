#include "TexturesManager.h"

TexturesManager::TexturesManager()
{
}

TexturesManager::~TexturesManager()
{
}

void TexturesManager::addAnimation(string location)
{
	Texture tmp;
	tmp.loadFromFile(location);
	animations.push_back(tmp);
}

Texture & TexturesManager::operator[](int index)
{
	return animations[index];
}
