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


	try{ 
		_set(value);
	} catch(const std::exception) {
		std::string message = std::string("The type ") + std::string(typeid(value).name()) + std::string("is not a suported uniform value in Gear");
		Console::err("INVALID_VALUE_EXCEPTION", message.c_str());
	}

}

template<typename type>
int ShaderUniform<type>::getLocation()
{
	location = glGetUniformLocation(programID, name);
	if (location == -1) {
		std::string message = std::string("This is just a warning: The Uniformvariable ") + std::string(name) + std::string(" cannot be found.");
		Console::err("UNIFORM_VAR_WARNING", message.c_str());
	}
	return location;
}

template<typename type>
const char * ShaderUniform<type>::getName()
{
	return name;
}

template<typename type>
void ShaderUniform<type>::_set(int value)
{
	glUniform1i(location, value);
}

template<typename type>
void ShaderUniform<type>::_set(float value)
{
	glUniform1f(location, value);
}

template<typename type>
void ShaderUniform<type>::_set(glm::vec2 value)
{
	glUniform2f(location, value.x, value.y);
}

template<typename type>
void ShaderUniform<type>::_set(glm::vec3 value)
{
	glUniform3f(location, value.x, value.y, value.z);
}

template<typename type>
void ShaderUniform<type>::_set(glm::vec4 value)
{
	glUniform4f(location, value.x, value.y, value.z, value.w);
}


template<typename type>
void ShaderUniform<type>::_set(glm::mat4 value)
{
	glUniformMatrix4fv(location, 1, GL_FALSE, &value[0][0]);
}

template<typename type>
void ShaderUniform<type>::_set(glm::mat3x3 value)
{
	glUniformMatrix3fv(location, 1, GL_FALSE, &value[0][0]);
}

template<typename type>
void ShaderUniform<type>::_set(glm::mat2x2 value)
{
	glUniformMatrix2fv(location, 1, GL_FALSE, &value[0][0]);
}

template<typename type>
void ShaderUniform<type>::_set(glm::mat3x4 value)
{
	glUniformMatrix3x4fv(location, 1, GL_FALSE, &value[0][0]);
}

template<typename type>
void ShaderUniform<type>::_set(glm::mat4x3 value)
{
	glUniformMatrix4x3fv(location, 1, GL_FALSE, &value[0][0]);
}
