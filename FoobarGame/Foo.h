#pragma once
#include <olcPixelGameEngine.h>


class Foo {
public:
	Foo(float x = 0, float y = 0, int size = 0, int border = 0, olc::Pixel frameColor = olc::MAGENTA, olc::Pixel fillColor = olc::WHITE);

public:
	void Move(float x, float y);
	void ChangeBorderColor(olc::Pixel newFrameColor);
	void ChangeFillColor(olc::Pixel newFillColor);

public:
	float x;
	float y;
	int size;
	int border;
	olc::Pixel borderColor;
	olc::Pixel fillColor;


};