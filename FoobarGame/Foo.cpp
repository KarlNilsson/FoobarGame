#include "Foo.h"

Foo::Foo(float x, float y, int size, int border, olc::Pixel frameColor, olc::Pixel fillColor)
{
	this->x = x;
	this->y = y;
	this->size = size;
	this->borderColor = frameColor;
	this->fillColor = fillColor;
	this->border = border;
}

void Foo::Move(float x, float y)
{
	this->x += x;
	this->y += y;
}

void Foo::ChangeBorderColor(olc::Pixel newBorderColor)
{
	borderColor = newBorderColor;
}

void Foo::ChangeFillColor(olc::Pixel newFillColor)
{
	fillColor = newFillColor;
}
