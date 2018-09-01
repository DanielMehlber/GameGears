#include "ShaderPack.h"


ShaderPack::ShaderPack()
{
	id = glCreateProgram();

}

ShaderPack::ShaderPack(Shader * vertex, Shader * fragment) : ShaderPack()
{
	setVertexShader(vertex);
	setFragmentShader(fragment);
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
	if (vertexShader != nullptr) {
		glDetachShader(id, vertexShader->id);
		vertexShader->~Shader();
	}
	if (fragmentShader != nullptr) {
		glDetachShader(id, fragmentShader->id);
		fragmentShader->~Shader();
	}
	if (geometryShader != nullptr) {
		glDetachShader(id, geometryShader->id);
		geometryShader->~Shader();
	}
}

void ShaderPack::setVertexShader(Shader * shader)
{
	checkShader(shader);

	if (!shader->type == Shader::VERTEX_SHADER) {
		Console::err("WRONG_SHADER_TYPE", "The parameter shader is no VERTEX_SHADER");
		Console::leave();
	}

	vertexShader = shader;
	attachShader(shader);
}

void ShaderPack::setFragmentShader(Shader * shader)
{
	checkShader(shader);

	if (!shader->type == Shader::FRAGMENT_SHADER) {
		Console::err("WRONG_SHADER_TYPE", "The parameter shader is no FRAGMENT_SHADER");
		Console::leave();
	}

	fragmentShader = shader;
	attachShader(shader);
}

void ShaderPack::setGeometryShader(Shader * shader)
{
	checkShader(shader);

	if (!shader->type == Shader::GEOMETRY_SHADER) {
		Console::err("WRONG_SHADER_TYPE", "The parameter shader is no GEOMETRY_SHADER");
		Console::leave();
	}

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
		Console::leave();
	}

	//Define Vertex Attribs here
	glBindAttribLocation(id, attribs::vertex_position.getLocation(), attribs::vertex_position.getName());
	glBindAttribLocation(id, attribs::vertex_tex_coords.getLocation(), attribs::vertex_tex_coords.getName());
	//Define Uniform Variables here
}

void ShaderPack::start()
{
	glUseProgram(id);
}

void ShaderPack::stop()
{
	glUseProgram(0);
}

void ShaderPack::attribute(int index, const char * name)
{
	glBindAttribLocation(id, index, name);
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


