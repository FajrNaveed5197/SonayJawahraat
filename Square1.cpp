#include "Square1.h"
Square1::Square1()
{
	size = 40;
}
Square1::~Square1()
{

}
void Square1::DisplaySquare1()
{
	DrawSquare(x-6, y-5, size, colors[RED]);
}
int Square1::getSize() const
{
	return size;
}
void Square1::setSize(int size)
{
	this->size = size;
}