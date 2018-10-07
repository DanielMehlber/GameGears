#include "File.h"



File::File()
{
}


File::~File()
{
}

std::string File::loadFile(const char * location)
{
	std::string txt;
	std::ifstream infile;
	infile.open(location);
	if (!infile.is_open()) {
		std::string message = std::string("Cannot open file: ") + std::string(location);
		std::cerr << message << std::endl;
		return NULL;
	}
	while (!infile.eof())
	{
		std::string line;
		getline(infile, line);
		txt = txt + "\n" + line;
	}
	infile.close();
	return txt;
}

