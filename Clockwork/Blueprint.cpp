#include "Blueprint.h"



Blueprint::Blueprint(std::string src_loc)
{
	std::string txt;
	std::ifstream infile;
	infile.open(src_loc);
	if (!infile.is_open()) {
		std::string message = std::string("Cannot open file: ") + std::string(src_loc);
		std::cout << message << std::endl;
		return;
	}
	while (!infile.eof())
	{
		std::string line;
		getline(infile, line);
		txt = txt + "\n" + line;
	}
	infile.close();
	src = txt;
}


Blueprint::~Blueprint()
{
}

std::string Blueprint::getSource()
{
	return src;
}


