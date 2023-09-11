#include "RoundRec.h"
RoundRec::RoundRec()
{
	width = 50.0;
	height = 25.0;
	radius = 15.0;
	
}
RoundRec::~RoundRec()
{

}
void RoundRec::DisplayRoundRec()
{
	DrawRoundRect(x-5, y+7, width, height, colors[DARK_MAGENTA], radius);
}
float RoundRec::getHeight()const
{
	return height;
}
void RoundRec::setHeight(float height)
{
	this->height = height;
}
float RoundRec::getRadius() const
{
	return radius;
}
float RoundRec::getWidth() const
{
	return width;
}
void RoundRec::setWidth(float width)
{
	this->width = width;
}

