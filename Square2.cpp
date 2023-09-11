#include "Square2.h"
Square2::Square2()
{
	size = 40;

}
Square2::~Square2()
{

}
void Square2::DisplaySquare2()
{
	DrawSquare(x-6, y-5, size, colors[DARK_ORANGE]);
}
int Square2::getSize() const
{
	return size;
}
void Square2::setSize(int size)
{
	this->size = size;
}
