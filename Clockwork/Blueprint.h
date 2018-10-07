#pragma once
#include <string>
#include <iostream>
#include <fstream>
class Blueprint
{
public:
	Blueprint(std::string src);
	~Blueprint();
	std::string getSource();

private:
	std::string src;
};



