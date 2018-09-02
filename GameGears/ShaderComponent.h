#pragma once
#include "List.h"
#include "Shader.h"
#include "ShaderAttrib.h"
#include "ShaderUniform.h"
#include "ShaderUniform.cpp"
#include "glm/vec2.hpp"
#include "Component.h"

namespace attribs {
	static ShaderAttrib vertex_position = ShaderAttrib(0, "vertex_position");
	static ShaderAttrib vertex_tex_coords = ShaderAttrib(1, "vertex_tex_coords");
};


class ShaderComponent : public Component, public OGLObject
{
public:

	ShaderComponent();
	ShaderComponent(Shader* vertex, Shader* fragment);
	ShaderComponent(Shader* vertex, Shader* fragment, Shader* geometry);
	~ShaderComponent();


	void setVertexShader(Shader* shader);
	void setFragmentShader(Shader* shader);
	void setGeometryShader(Shader* shader);
	Shader* getShader(Shader::TYPES type);
	void pack();
	void activate();
	void deactivate();
	void attribute(int index, const char* name);

	//static const char*  default_vertex_loc;
	//static const char*  default_fragment_loc;

	//static Shader* default_vertex_shader;
	//static Shader* default_fragment_shader;

	//static ShaderComponent* defaultShader;
	static ShaderComponent* genDefaultShader();
	
private:
	Shader* vertexShader;
	Shader* fragmentShader;
	Shader* geometryShader;
	void attachShader(Shader* shader);
	void checkShader(Shader* shader);
};

