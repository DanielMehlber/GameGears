#include "Shader.h"




Shader::Shader(const char* src, TYPES type)
{
	init(type);
	GLCall(glShaderSource(id, 1, &src, NULL));
	GLCall(glCompileShader(id));
	checkCompileStatus();
}


Shader::~Shader()
{
	glDeleteShader(id);
}


void Shader::init(TYPES type)
{
	Shader::type = type;
	GLuint gl_type;
	switch (type)
	{
	case Shader::VERTEX_SHADER:
		gl_type = GL_VERTEX_SHADER;
		break;
	case Shader::FRAGMENT_SHADER:
		gl_type = GL_FRAGMENT_SHADER;
		break;
	case Shader::GEOMETRY_SHADER:
		gl_type = GL_GEOMETRY_SHADER;
		break;
	default:
		Console::err("UNKNOWN_SHADER_TYPE", "Unknown Shader Type index " + type);
		Console::leave();
		break;
	}

	GLCall(id = glCreateShader(gl_type));



}

void Shader::checkCompileStatus()
{
	int no_errors;
	char error_message[512];
	glGetShaderiv(id, GL_COMPILE_STATUS, &no_errors);
	if (!no_errors) {
		status = STATUS::COMPILATION_FAILED;
		glGetShaderInfoLog(id, 512, NULL, error_message);
		Console::err("SHADER_COMPILE_ERROR", error_message);
		Console::leave();
	}
	else {
		status = STATUS::OK;
	}
}
