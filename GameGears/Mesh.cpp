#include "Mesh.h"



Mesh::Mesh()
{
	//Init Lists
	vertices = List<Vertex*>();
	v_positions = List<float>();
	vbos = new unsigned int[buffers::BUFFER_COUNT];

	//Default shader
	
	Shader* default_vs = Shader::loadShader(Shader::VERTEX_SHADER, "./res/default_vs.txt");
	Shader* default_fs = Shader::loadShader(Shader::FRAGMENT_SHADER, "./res/default_fs.txt");
	default_shaders = new ShaderPack();
	default_shaders->setVertexShader(default_vs);
	default_shaders->setFragmentShader(default_fs);
	default_shaders->pack();
	shaders = default_shaders;

	GLCall(glGenVertexArrays(1, &vaoID));
	GLCall(glGenBuffers(buffers::BUFFER_COUNT, vbos));
}


Mesh::~Mesh()
{
	GLCall(glDeleteVertexArrays(1, &vaoID));
	GLCall(glDeleteBuffers(buffers::BUFFER_COUNT, vbos));
	GLCall(glDisableVertexAttribArray(buffers::POSITIONS));
}

void Mesh::render() {
	GLCall(glBindVertexArray(vaoID));
	if (shaders == nullptr)
		shaders = default_shaders;
	GLCall(glUseProgram(shaders->id));
	GLCall(glDrawArrays(GL_TRIANGLES, 0, 3));
	GLCall(glUseProgram(0));
	GLCall(glBindVertexArray(0));
}

void Mesh::pack(Renderable::usage hint)
{
	GLuint draw_type;
	switch (hint)
	{
	case Renderable::STATIC_DRAW:
		draw_type = GL_STATIC_DRAW;
		break;
	case Renderable::DYNAMIC_DRAW:
		draw_type = GL_DYNAMIC_DRAW;
		break;
	case Renderable::STREAM_DRAW:
		draw_type = GL_STREAM_DRAW;
		break;
	default:
		break;
	}

	v_positions.clear();
	for (Vertex* vertex : *vertices.getData()) {
		v_positions.append(vertex->pos.x);
		v_positions.append(vertex->pos.y);
		v_positions.append(vertex->pos.z);
	}


	GLCall(glBindVertexArray(vaoID));
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, vbos[buffers::POSITIONS]));
	GLCall(glBufferData(GL_ARRAY_BUFFER, sizeof(float) * v_positions.size(), v_positions.toArray(), draw_type));
	GLCall(glVertexAttribPointer(buffers::POSITIONS, 3, GL_FLOAT, GL_FALSE, 0, (void*)0));
	GLCall(glEnableVertexAttribArray(buffers::POSITIONS));
	GLCall(glBindVertexArray(0));

}

void Mesh::pack()
{
	pack(STATIC_DRAW);
}

