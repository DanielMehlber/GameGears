#pragma once
#include "List.h"
#include "Shader.h"
#include "ShaderAttrib.h"
#include "ShaderUniform.h"
#include "ShaderUniform.cpp"
#include "glm/vec2.hpp"

namespace attribs {
	static ShaderAttrib vertex_position = ShaderAttrib(0, "vertex_position");
	static ShaderAttrib vertex_tex_coords = ShaderAttrib(1, "vertex_tex_coords");
};


class ShaderPack
{
public:

	ShaderPack();
	ShaderPack(Shader* vertex, Shader* fragment);
	ShaderPack(Shader* vertex, Shader* fragment, Shader* geometry);
	~ShaderPack();


	void setVertexShader(Shader* shader);
	void setFragmentShader(Shader* shader);
	void setGeometryShader(Shader* shader);
	Shader* getShader(Shader::TYPES type);
	unsigned int id;
	void pack();
	void start();
	void stop();
	void attribute(int index, const char* name);
	
private:
	Shader* vertexShader;
	Shader* fragmentShader;
	Shader* geometryShader;
	void attachShader(Shader* shader);
	void checkShader(Shader* shader);
};

