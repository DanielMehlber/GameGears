#include "GearOut.h"



GearOut::GearOut()
{
}


GearOut::~GearOut()
{
}

void GearOut::err(int line, std::string err)
{
	std::cerr << "Error in Line " << line << ": " << err << std::endl;
}
