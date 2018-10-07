#pragma once
#include "Blueprint.h"
#include <string>
#include <fstream>
#include <sstream>
#include "GearObjects.h"

class GearCompiler
{
public:
	GearCompiler(std::string source);
	~GearCompiler();
	void compile(std::string dest);
private:
	std::string sk;
	GearFile current;
};

