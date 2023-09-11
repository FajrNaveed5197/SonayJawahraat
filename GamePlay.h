#pragma once
#include"Square1.h"
#include"Square2.h"
#include"Triangle1.h"
#include"Triangle2.h"
#include"RoundRec.h"
#include"Menu.h"
#include"Movement.h"
class GamePlay : virtual public Square1, virtual public Square2, virtual public Triangle1, virtual public Triangle2, virtual public RoundRec, virtual public Menu 
{
protected: 
	static int A[6][6];
	 bool pausehi;
	 static int score;
	 static int timelimit;
public:
	GamePlay();
	~GamePlay();
	void Random();
	void DisplayRand();
	void LinesDraw();
	void setpausehi(bool x);
	int getpausehi();
	void Disapear();
	void setscore(int a);
	int getscore();
	void Drop();
	void Slide(int a1, int b1, int a2, int b2);
	void TimeLimit();
	void setlimit(int a);
	int getlimit();
};

