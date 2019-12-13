#pragma once
#include <olcPixelGameEngine.h>


class Foo {
public:
	Foo(float x = 0, float y = 0, int size = 0, olc::Pixel frameColor = olc::MAGENTA, olc::Pixel fillColor = olc::WHITE);

public:
	void Move(float x, float y);
	void ChangeFrameColor(olc::Pixel newFrameColor);
	void ChangeFillColor(olc::Pixel newFillColor);

public:
	float x;
	float y;
	int size;
	olc::Pixel frameColor;
	olc::Pixel fillColor;


};