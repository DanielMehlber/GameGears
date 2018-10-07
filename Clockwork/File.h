#pragma once
#include <string>
#include <fstream>
#include <iostream>
class File
{
public:
	File();
	~File();
	static std::string loadFile(const char* loc);
};

