#pragma once
#include "Renderable.h"
#include "List.h"
#include "List.cpp"
#include "Vertex.h"
#include "GLEW/glew.h"
#include "ShaderPack.h"
#include "Texture.h"

class Mesh : public Renderable, public OGLObject
{
public:
	Mesh();
	~Mesh();
	void render() override;
	List<Vertex*> vertices;
	List<unsigned int> indices;
	void pack(Renderable::usage hint);
	void pack();
	ShaderPack* shaders;
	ShaderPack* default_shaders;

	enum vertex_buffers {
		POSITIONS,
		INDICES,
		TEX_COORDS,
		BUFFER_COUNT
	};


	unsigned int* vbos;

	//
	Texture* diffuseTexture;

private:
	List<float> v_positions;
	List<float> v_tex_coords;
};

