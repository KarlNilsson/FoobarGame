#define OLC_PGE_APPLICATION
#include <olcPixelGameEngine.h>

class FoobarGame : public olc::PixelGameEngine
{
public:
	FoobarGame() {
		sAppName = "FoobarGame";
	}

public:
	bool OnUserCreate() override
	{
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		for (auto x = 0; x < ScreenHeight(); x++) {
			for (auto y = 0; y < ScreenWidth(); y++) {
				Draw(x, y, olc::Pixel(rand() % 255, rand() % 255, rand() % 255));
			}
		}
		return true;
	}

};

int main() {
	FoobarGame game;
	if (game.Construct(64, 64, 4, 4)) {
		game.Start();
	}
	return 0;
}