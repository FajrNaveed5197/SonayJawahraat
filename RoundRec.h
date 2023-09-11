#pragma once
#include"Sonay_jwahraat.h"

class RoundRec:virtual public Sonay_jwahraat
{
protected:
	float radius;
	float width;
	float height;

public:
	RoundRec();
	~RoundRec();
	void DisplayRoundRec();
	float getHeight()const;
	void setHeight(float height);
	float getRadius() const;
	float getWidth() const;
	void setWidth(float width);

};

