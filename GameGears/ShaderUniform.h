#pragma once
#include "GLEW/glew.h"
#include "Console.h"
#include "glm/vec2.hpp"
#include "glm/vec3.hpp"
#include "glm/glm.hpp"
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
	void _set(int value);
	void _set(float value);
	void _set(glm::vec2 value);
	void _set(glm::vec3 value);
	void _set(glm::vec4 value);
	void _set(glm::mat4 value);
	void _set(glm::mat3x3 value);
	void _set(glm::mat2x2 value);
	void _set(glm::mat3x4 value);
	void _set(glm::mat4x3 value);
};

