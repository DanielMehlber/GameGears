#pragma once
#include "ShaderUniform.h"
#include <iostream>


template<typename type>
ShaderUniform<type>::ShaderUniform(unsigned int programID, const char * name, type default_value)
{
	ShaderUniform::name = name;
	ShaderUniform::programID = programID;
	ShaderUniform::default_value = default_value;
	ShaderUniform::location = -1;
	set(default_value);
}

template<typename type>
ShaderUniform<type>::~ShaderUniform()
{
}

template < typename type > void ShaderUniform<type>::set(type value)
{
	if (location == -1) {
		location = getLocation();
		return;
	}
	if (typeid(value) == typeid(int)) {
		glUniform1i(location, value);
	}
}

template<typename type>
int ShaderUniform<type>::getLocation()
{
	location = glGetUniformLocation(programID, name);
	if (location == -1) {
		std::string message = std::string("This is just a warning: The Uniformvariable ")+std::string(name)+std::string(" cannot be found.")
		Console::err("UNIFORM_VAR_WARNING", "This is just a warning: The Uniformvariable")
	}
	
}

template<typename type>
const char * ShaderUniform<type>::getName()
{
	return name;
}
