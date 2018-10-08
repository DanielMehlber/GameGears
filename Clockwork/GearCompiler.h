#pragma once
#include "Blueprint.h"
#include <string>
#include <fstream>
#include <sstream>
#include "GearObjects.h"
#include "GearOut.h"

class GearCompiler
{
public:

	GearCompiler(std::string source);
	~GearCompiler();
	int compile(std::string dest);
private:
	std::string sk;
	GearFile current;
};

