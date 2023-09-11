#include "Menu.h"
void Menu::startup_menu()
{
	DrawSquare(0, 0, 1500, colors[BLACK]);
	DrawString(300, 900, "<<<<<<<<<<<<<<Sonay Jawahraat>>>>>>>>>>>>", colors[rand() % 50]);
	DrawString(450, 600, "Start Game", colors[rand() % 50]);
	DrawString(450, 500, "Highscore", colors[rand() % 50]);
	DrawString(450, 400, " Press Esc to Exit", colors[rand() % 50]);
}
void Menu::setStartup_menu(bool b)
{
	startmenu = b;
}
bool Menu::getStartup_menu()
{
	return startmenu;
}
void Menu::setStop(bool b)
{
	stop= b;
}
bool Menu::getStop()
{
	return stop;
}
void Menu::endmenu()
{
	DrawSquare(0, 0, 1500, colors[BLACK]);
	DrawString(300, 900, "<<<<<<<<<<<<<<Sonay Jawahraat>>>>>>>>>>>>", colors[rand() % 50]);
	DrawString(450, 600, "Start Game", colors[rand() % 50]);
	DrawString(450, 500, "Highscore = 503", colors[rand() % 50]);
	DrawString(450, 400, " Press Esc to Exit", colors[rand() % 50]);
}

