#pragma once
#include <string>
#include <iostream>
class GearOut
{
public:
	GearOut();
	~GearOut();
	static void err(int line, std::string err);
};

