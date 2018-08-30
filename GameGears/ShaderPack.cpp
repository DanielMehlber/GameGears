#include "ShaderPack.h"



ShaderPack::ShaderPack()
{
	id = glCreateProgram();

}

ShaderPack::ShaderPack(Shader * vertex, Shader * fragment, Shader * geometry) : ShaderPack()
{
	setVertexShader(vertex); 
	setFragmentShader(fragment); 
	setGeometryShader(geometry);
}


ShaderPack::~ShaderPack()
{
	glDeleteProgram(id);
	if (vertexShader != nullptr)
		vertexShader->~Shader();
	if (fragmentShader != nullptr)
		fragmentShader->~Shader();
	if (geometryShader != nullptr)
		geometryShader->~Shader();
}

void ShaderPack::setVertexShader(Shader * shader)
{


	if (!shader->type == Shader::VERTEX_SHADER) {
		Console::err("WRONG_SHADER_TYPE", "The parameter shader is no VERTEX_SHADER");
		Console::leave();
	}

	checkShader(shader);

	vertexShader = shader;
	attachShader(shader);
}

void ShaderPack::setFragmentShader(Shader * shader)
{
	if (!shader->type == Shader::FRAGMENT_SHADER) {
		Console::err("WRONG_SHADER_TYPE", "The parameter shader is no FRAGMENT_SHADER");
		Console::leave();
	}

	checkShader(shader);

	fragmentShader = shader;
	attachShader(shader);
}

void ShaderPack::setGeometryShader(Shader * shader)
{
	if (!shader->type == Shader::GEOMETRY_SHADER) {
		Console::err("WRONG_SHADER_TYPE", "The parameter shader is no GEOMETRY_SHADER");
		Console::leave();
	}

	checkShader(shader);

	geometryShader = shader;
	attachShader(shader);
}

Shader * ShaderPack::getShader(Shader::TYPES type)
{
	switch (type)
	{
	case Shader::VERTEX_SHADER:
		return vertexShader;
		break;
	case Shader::FRAGMENT_SHADER:
		return fragmentShader;
		break;
	case Shader::GEOMETRY_SHADER:
		return geometryShader;
		break;
	default:
		return nullptr;
		break;
	}
}

void ShaderPack::pack()
{
	glLinkProgram(id);
	int success;
	char infoLog[512];
	glGetProgramiv(id, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(id, 512, NULL, infoLog);
		Console::err("SHADER_PACK_LINK_ERROR", infoLog);
	}
}

void ShaderPack::use()
{
	glUseProgram(id);
}

void ShaderPack::attachShader(Shader * shader)
{
	glAttachShader(id, shader->id);
}

void ShaderPack::checkShader(Shader * shader)
{
	if (shader == nullptr) {
		Console::err("INVALID_SHADER", "Shader is nullptr in ShaderPack: "+id);
		Console::leave();
	}

	if (shader->status == Shader::STATUS::COMPILATION_FAILED) {
		Console::err("INVALID_SHADER", "Compilation failed shader " + shader->id);
		Console::leave();
	}
}


