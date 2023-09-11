#pragma once
#include"Sonay_jwahraat.h"
class Square1: virtual public Sonay_jwahraat
{
protected: 
	int size;
public:
	Square1();
	~Square1();
	void DisplaySquare1();
	int getSize() const;
	void setSize(int size);
};

