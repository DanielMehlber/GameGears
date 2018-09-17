#include "Synchronizer.h"



Synchronizer::Synchronizer(unsigned int ups) : ups{ ups }
{
	Synchronizer::last_update_time = std::chrono::system_clock::now();
	setFPS(ups);
}


Synchronizer::~Synchronizer()
{
}

bool Synchronizer::is_update_allowed()
{
	if (ups == 0)
		return true;

	auto now = std::chrono::system_clock::now();

	long now_ms = now.time_since_epoch().count();
	long last_ms = last_update_time.time_since_epoch().count();
	long time_passed = now_ms - last_ms;

	if (time_passed > delay_time) {
		Synchronizer::last_update_time = std::chrono::system_clock::now();
		return true;
	}
	return false;
}

void Synchronizer::setFPS(unsigned int fps)
{
	Synchronizer::ups = fps;
	if (ups != 0) {
		Synchronizer::delay_time = 10000000 / fps;
	}
	else {
		Synchronizer::delay_time = 0;
	}
}

