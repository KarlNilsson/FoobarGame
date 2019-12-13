#include "Foo.h"

Foo::Foo(float x, float y, int size, olc::Pixel frameColor, olc::Pixel fillColor)
{
	this->x = x;
	this->y = y;
	this->size = size;
	this->frameColor = frameColor;
	this->fillColor = fillColor;
}

void Foo::Move(float x, float y)
{
	this->x += x;
	this->y += y;
}

void Foo::ChangeFrameColor(olc::Pixel newFrameColor)
{
	frameColor = newFrameColor;
}

void Foo::ChangeFillColor(olc::Pixel newFillColor)
{
	fillColor = newFillColor;
}
