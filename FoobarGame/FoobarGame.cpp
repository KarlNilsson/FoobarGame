#define OLC_PGE_APPLICATION
#include <olcPixelGameEngine.h>
#include "Foo.h"
using namespace olc;

class FoobarGame : public PixelGameEngine
{
public:
	FoobarGame() {
		sAppName = "FoobarGame";
	}

private:
	Foo Foo1;

public:
	bool OnUserCreate() override
	{
		int fooSize = 4;
		Foo1 = Foo((ScreenHeight() / 2 - fooSize / 2), (ScreenWidth() / 2 - fooSize / 2), fooSize);
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		Clear(olc::VERY_DARK_GREY);
		DrawFoo(&Foo1);

		if (PixelGameEngine::GetKey(olc::LEFT).bHeld) {
			Foo1.Move(-45 * fElapsedTime, 0);
		}
		if (PixelGameEngine::GetKey(olc::RIGHT).bHeld) {
			Foo1.Move(45 * fElapsedTime, 0);
		}
		if (PixelGameEngine::GetKey(olc::UP).bHeld) {
			Foo1.Move(0, -45 * fElapsedTime);
		}
		if (PixelGameEngine::GetKey(olc::DOWN).bHeld) {
			Foo1.Move(0, 45 * fElapsedTime);
		}

		return true;
	}

	void DrawFoo(Foo* foo) {
		DrawRect(foo->x, foo->y, foo->size, foo->size, foo->frameColor);
		FillRect(foo->x + 1, foo->y + 1, foo->size - 1, foo->size - 1, foo->fillColor);
	}

};

int main() {
	FoobarGame game;
	if (game.Construct(128, 128, 4, 4)) {
		game.Start();
	}
	return 0;
}