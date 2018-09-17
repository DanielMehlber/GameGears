#include "ShaderComponent.h"


ShaderComponent::ShaderComponent() : Component(Component::tags::RENDER_RELEVANT)
{
	id = glCreateProgram();

}

ShaderComponent::ShaderComponent(Shader * vertex, Shader * fragment) : ShaderComponent()
{
	setVertexShader(vertex);
	setFragmentShader(fragment);
}

ShaderComponent::ShaderComponent(Shader * vertex, Shader * fragment, Shader * geometry) : ShaderComponent()
{
	setVertexShader(vertex); 
	setFragmentShader(fragment); 
	setGeometryShader(geometry);
}


ShaderComponent::~ShaderComponent()
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

void ShaderComponent::setVertexShader(Shader * shader)
{
	checkShader(shader);

	if (!shader->type == Shader::VERTEX_SHADER) {
		Console::err("WRONG_SHADER_TYPE", "The parameter shader is no VERTEX_SHADER");
		Console::leave();
	}

	vertexShader = shader;
	attachShader(shader);
}

void ShaderComponent::setFragmentShader(Shader * shader)
{
	checkShader(shader);

	if (!shader->type == Shader::FRAGMENT_SHADER) {
		Console::err("WRONG_SHADER_TYPE", "The parameter shader is no FRAGMENT_SHADER");
		Console::leave();
	}

	fragmentShader = shader;
	attachShader(shader);
}

void ShaderComponent::setGeometryShader(Shader * shader)
{
	checkShader(shader);

	if (shader->type != Shader::GEOMETRY_SHADER) {
		Console::err("WRONG_SHADER_TYPE", "The parameter shader is no GEOMETRY_SHADER");
		Console::leave();
	}

	geometryShader = shader;
	attachShader(shader);
}

Shader * ShaderComponent::getShader(Shader::TYPES type)
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

void ShaderComponent::pack()
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
	uniform_transformation_matrix = new ShaderUniform<glm::mat4>(id, "trans", glm::mat4());
}

void ShaderComponent::activate()
{
	glUseProgram(id);
}

void ShaderComponent::deactivate()
{
	glUseProgram(0);
}

void ShaderComponent::attribute(int index, const char * name)
{
	glBindAttribLocation(id, index, name);
}


ShaderComponent * ShaderComponent::genDefaultShader()
{
	const char* default_vertex_loc = "./res/default_vs.txt";
	const char* default_fragment_loc = "./res/default_fs.txt";

	Shader* default_vertex_shader = Shader::loadShader(Shader::VERTEX_SHADER, default_vertex_loc);
	Shader* default_fragment_shader = Shader::loadShader(Shader::FRAGMENT_SHADER, default_fragment_loc);

	ShaderComponent* defaultShader = new ShaderComponent(default_vertex_shader, default_fragment_shader);
	return defaultShader;
}

void ShaderComponent::attachShader(Shader * shader)
{
	glAttachShader(id, shader->id);
}

void ShaderComponent::checkShader(Shader * shader)
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


