#pragma once
class TableOfPositions
{
public:
	TableOfPositions();
	~TableOfPositions();
	// acces to atributes by an array and by these three clear variables:
	float top, middle, bottom;
	float & operator[] (int index);

	void setMid(float mid);
	void setTop(float top);
	void setBot(float bot);
private:
	float tab[3];
};