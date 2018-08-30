#pragma once
#include "List.h"
#include "Shader.h"
class ShaderPack
{
public:
	ShaderPack();
	ShaderPack(Shader* vertex, Shader* fragment, Shader* geometry);
	~ShaderPack();
	void setVertexShader(Shader* shader);
	void setFragmentShader(Shader* shader);
	void setGeometryShader(Shader* shader);
	Shader* getShader(Shader::TYPES type);
	unsigned int id;
	void pack();
	void use();
	
private:
	Shader* vertexShader;
	Shader* fragmentShader;
	Shader* geometryShader;
	void attachShader(Shader* shader);
	void checkShader(Shader* shader);
};

