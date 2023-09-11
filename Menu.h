#pragma once
#include"Sonay_jwahraat.h"
#include"util.h"

class Menu
{
	static bool startmenu;
	static bool stop;
	static bool weee;

public:
	void startup_menu();
	void setStartup_menu(bool b);
	bool getStartup_menu();
	void setStop(bool b);
	bool getStop();
	void endmenu();
};

