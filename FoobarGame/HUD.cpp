#include "HUD.h"

HUD::HUD()
{
	ResetClock();
}

HUD_clock HUD::GetClock()
{	
	auto elapsed = std::chrono::steady_clock::now() - StartTime;
	CurrentTime.millisec = elapsed.count() / 1000000;
	CurrentTime.sec = CurrentTime.millisec / 1000;
	CurrentTime.min = CurrentTime.sec / 60;
	return CurrentTime;
}

void HUD::ResetClock()
{
	StartTime = std::chrono::steady_clock::now();
	CurrentTime = HUD_clock{ 0, 0, 0 };
}
