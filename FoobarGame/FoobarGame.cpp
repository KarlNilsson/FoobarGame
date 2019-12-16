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
		int fooSize = 16;
		Foo1 = Foo((ScreenHeight() / 2 - fooSize / 2), (ScreenWidth() / 2 - fooSize / 2), fooSize, 16);
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		Clear(olc::VERY_DARK_GREY);
		DrawRect(0, 0, ScreenHeight(), ScreenWidth(), olc::BLACK);
		DrawRect(1, 1, ScreenHeight() - 2, ScreenWidth() - 2, olc::GREEN);
		DrawRect(2, 2, ScreenHeight() - 4, ScreenWidth() - 4, olc::GREEN);
		DrawRect(3, 3, ScreenHeight() - 6, ScreenWidth() - 6, olc::GREEN);
		DrawFoo(&Foo1);

		if (PixelGameEngine::GetKey(olc::LEFT).bHeld && Foo1.x > 5) {
			Foo1.Move(-200 * fElapsedTime, 0);
		}
		if (PixelGameEngine::GetKey(olc::RIGHT).bHeld && (Foo1.x + Foo1.size) < ScreenWidth() - 4) {
			Foo1.Move(200 * fElapsedTime, 0);
		}
		if (PixelGameEngine::GetKey(olc::UP).bHeld && Foo1.y > 5) {
			Foo1.Move(0, -200 * fElapsedTime);
		}
		if (PixelGameEngine::GetKey(olc::DOWN).bHeld && (Foo1.y + Foo1.size) < ScreenHeight() - 4) {
			Foo1.Move(0, 200 * fElapsedTime);
		}

		return true;
	}

	void DrawFoo(Foo* foo) {
		auto borderSize = 4;
		for (auto i = 0; i < borderSize; i++)
		{
			DrawRect(foo->x + i, foo->y + i, foo->size - (2 * i), foo->size - (2 * i), foo->borderColor);

		}
		FillRect(foo->x + borderSize, foo->y + borderSize, foo->size - borderSize * 2 + 1, foo->size - borderSize * 2 + 1, foo->fillColor);
	}

};

int main() {
	FoobarGame game;
	if (game.Construct(512, 512, 1, 1)) {
		game.Start();
	}
	return 0;
}