#pragma once
#include <chrono>
#include <iostream>
class Synchronizer
{
public:
	Synchronizer(unsigned int fps);
	~Synchronizer();
	bool is_update_allowed();
	void setFPS(unsigned int fps);
private:
	unsigned int ups;
	long delay_time;
	std::chrono::time_point<std::chrono::system_clock> last_update_time;
};


