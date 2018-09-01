#include "ShaderAttrib.h"



ShaderAttrib::ShaderAttrib(int location, const char * name)
{
	ShaderAttrib::location = location;
	ShaderAttrib::name = name;
}

ShaderAttrib::~ShaderAttrib()
{
}

int ShaderAttrib::getLocation()
{
	return location;
}

const char * ShaderAttrib::getName()
{
	return name;
}
