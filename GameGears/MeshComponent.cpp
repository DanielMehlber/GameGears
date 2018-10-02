#include "MeshComponent.h"

//TODO: index buffer: unsigned char* < unsigned short* < unsigned int*: indices size adaption (depends on vertex_count) 


MeshComponent::MeshComponent(RenderComponent* context) : Component(Component::tags::RENDER_RELEVANT), Renderable(context)
{
	//Init Lists
	vertices = List<Vertex*>();
	v_positions = List<float>();
	v_tex_coords = List<float>();
	indices = List<unsigned int>();
	vbos = new unsigned int[buffers::BUFFER_COUNT];

	
	GLCall(glGenVertexArrays(1, &id));
	GLCall(glGenBuffers(buffers::BUFFER_COUNT, vbos));
}


MeshComponent::~MeshComponent()
{
	GLCall(glDeleteVertexArrays(1, &id));
	GLCall(glDeleteBuffers(buffers::BUFFER_COUNT, vbos));
	GLCall(glDisableVertexAttribArray(buffers::POSITIONS));
	GLCall(glDisableVertexAttribArray(buffers::TEX_COORDS));
	GLCall(glDisableVertexAttribArray(buffers::INDICES));
}

void MeshComponent::render() {
	
	//Dont forget to activate !
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
	
}

void MeshComponent::activate()
{
	glBindVertexArray(id);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbos[buffers::INDICES]);
	active = true;
}

void MeshComponent::deactivate()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	active = false;
}

void MeshComponent::pack(Renderable::usage hint)
{
	//Determin DRAW_TYPE based on hint
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

	//Convert the Vertex Array format to the Buffer Array format
	v_positions.clear();
	v_tex_coords.clear();
	for (Vertex* vertex : vertices.getData()) {
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
	
	
	//PREPS MESH DATA
	glBindVertexArray(id);

	v_positions = List<float>(pos, 12);
	glBindBuffer(GL_ARRAY_BUFFER, vbos[buffers::POSITIONS]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * v_positions.size(), v_positions.toArray(), draw_type);
	glVertexAttribPointer(buffers::POSITIONS, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(buffers::POSITIONS);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	

	v_tex_coords = List<float>(t_c, 8);
	glBindBuffer(GL_ARRAY_BUFFER, vbos[buffers::TEX_COORDS]);
	glBufferData(GL_ARRAY_BUFFER, v_tex_coords.size() * sizeof(float), v_tex_coords.toArray(), draw_type);
	glVertexAttribPointer(buffers::TEX_COORDS, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glEnableVertexAttribArray(buffers::TEX_COORDS);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	

	indices = List<unsigned int>(ind, 6);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbos[buffers::INDICES]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indices.size(), indices.toArray(), draw_type);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	

	glBindVertexArray(0);
	
}

void MeshComponent::pack()
{
	pack(STATIC_DRAW);
}

