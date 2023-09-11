#pragma once
#include"Sonay_jwahraat.h"
class Square2 : virtual public Sonay_jwahraat
{
protected:
	int size;
public:
	Square2();
	~Square2();
	void DisplaySquare2();
	int getSize() const;
	void setSize(int size);
};

