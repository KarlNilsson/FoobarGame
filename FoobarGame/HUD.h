#pragma once
#include <olcPixelGameEngine.h>
#include <chrono>
#include <iomanip>
#include <iostream>

struct HUD_clock {
	int min;
	int sec;
	int millisec;

	inline friend std::ostream& operator<<(std::ostream& out, const HUD_clock& h) {
		out << std::setfill('0') << std::setw(2) << h.min % 60
			<< ":" << std::setfill('0') << std::setw(2) << h.sec % 60
			<< ":" << std::setfill('0') << std::setw(3) << h.millisec % 1000;
		return out;
	}

};


class HUD
{
public:
	HUD();

public:
	void ResetClock();
	HUD_clock GetClock();


private:
	std::chrono::steady_clock::time_point StartTime;
	HUD_clock CurrentTime;
};

