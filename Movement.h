#pragma once
#include"util.h"
#include<iostream>
using namespace std;
class Movement
{
private:
	static int a1, b1, a2, b2;
	static int Ginti;
public:
	void seta1(int a);
	void setb1(int a);
	void seta2(int a);
	void setb2(int a);
	void setGinti(int a);

	int geta1();
	int getb1();
	int geta2();
	int getb2();
	int getGinti();

};

