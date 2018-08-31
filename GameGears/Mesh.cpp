#include "Mesh.h"

//TODO: index buffer: unsigned char* < unsigned short* < unsigned int*: indices size adaption (depends on vertex_count) 

Mesh::Mesh()
{
	//Init Lists
	vertices = List<Vertex*>();
	v_positions = List<float>();
	v_tex_coords = List<float>();
	indices = List<unsigned int>();
	vbos = new unsigned int[vertex_buffers::BUFFER_COUNT];

	//Default shader
	/*
	Shader* default_vs = Shader::loadShader(Shader::VERTEX_SHADER, "./res/default_vs.txt");
	Shader* default_fs = Shader::loadShader(Shader::FRAGMENT_SHADER, "./res/default_fs.txt");
	default_shaders = new ShaderPack();
	default_shaders->setVertexShader(default_vs);
	default_shaders->setFragmentShader(default_fs);
	default_shaders->pack();
	shaders = default_shaders;
	*/
	GLCall(glGenVertexArrays(1, &id));
	GLCall(glGenBuffers(vertex_buffers::BUFFER_COUNT, vbos));
}


Mesh::~Mesh()
{
	GLCall(glDeleteVertexArrays(1, &id));
	GLCall(glDeleteBuffers(vertex_buffers::BUFFER_COUNT, vbos));
	GLCall(glDisableVertexAttribArray(vertex_buffers::POSITIONS));
	GLCall(glDisableVertexAttribArray(vertex_buffers::TEX_COORDS));
	GLCall(glDisableVertexAttribArray(vertex_buffers::INDICES));
}

void Mesh::render() {
	if (shaders == nullptr)
		shaders = default_shaders;
	shaders->use();
	if (diffuseTexture) {
		diffuseTexture->use(0);
	}
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbos[vertex_buffers::INDICES]))
	GLCall(glBindVertexArray(id));
	GLCall(glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0));	

	GLCall(glUseProgram(0));
	GLCall(glBindTexture(GL_TEXTURE_2D, 0));
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
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
	v_tex_coords.clear();
	for (Vertex* vertex : *vertices.getData()) {
		//Positions from vec3 to Array
		v_positions.append(vertex->pos.x);
		v_positions.append(vertex->pos.y);
		v_positions.append(vertex->pos.z);
		//texcoords from vec2 to Array
		v_tex_coords.append(vertex->tex_coords.x);
		v_tex_coords.append(vertex->tex_coords.y);
	}

	float pos[12] = {
		-0.5, -0.5, 0,
		0.5, -0.5, 0,
		0.5, 0.5, 0,
		-0.5, 0.5, 0
	};

	unsigned int ind[6] = {
		0,1,2,
		2,3,0
	};

	float t_c[8] = {
		0,0,1,0,1,1,0,1
	};

	v_positions = List<float>(pos, 12);
	v_tex_coords = List<float>(t_c, 8);
	indices = List<unsigned int>(ind, 6);

	GLCall(glBindVertexArray(id));

	GLCall(glBindBuffer(GL_ARRAY_BUFFER, vbos[vertex_buffers::POSITIONS]));
	GLCall(glBufferData(GL_ARRAY_BUFFER, sizeof(float) * v_positions.size(), v_positions.toArray(), draw_type)); 
	GLCall(glVertexAttribPointer(vertex_buffers::POSITIONS, 3, GL_FLOAT, GL_FALSE, 0, (void*)0));
	GLCall(glEnableVertexAttribArray(vertex_buffers::POSITIONS));

	GLCall(glBindBuffer(GL_ARRAY_BUFFER, vbos[vertex_buffers::TEX_COORDS]));
	GLCall(glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 8, v_tex_coords.toArray(), draw_type));
	GLCall(glVertexAttribPointer(vertex_buffers::TEX_COORDS, 2, GL_FLOAT, GL_FALSE, 0, (void*)0));
	GLCall(glEnableVertexAttribArray(vertex_buffers::TEX_COORDS));

	GLCall(glBindVertexArray(0));

	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbos[vertex_buffers::INDICES]));
	GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indices.size(), indices.toArray(), draw_type));

	GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
	

}

void Mesh::pack()
{
	pack(STATIC_DRAW);
}

