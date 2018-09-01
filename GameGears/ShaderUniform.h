#pragma once
#include "GLEW/glew.h"
#include "Console.h"
template <typename type> class ShaderUniform
{
public:
	ShaderUniform(unsigned int programID, const char* name, type default_value);
	~ShaderUniform();
	
	void set(type value);
	int getLocation();
	const char* getName();

private:
	const char* name;
	int location = -1;
	type default_value;
	unsigned int programID;
};

