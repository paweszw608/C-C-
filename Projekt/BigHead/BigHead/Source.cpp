#include "Menu.h"

void make()
{
	RenderWindow window;
	window.create(VideoMode(1092, 614), "Pluto", Style::Titlebar);
	try {
		Menu menu(window);
		menu.draw(window);
	}	
	catch (invalid_argument ia) {
		ia.what();
	}


}

int main()
{
	srand(time(NULL));
	make();
	return 0;

}