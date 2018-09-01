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
	ShaderPack* default_shaders;

	Mesh();
	~Mesh();
	void render() override;
	List<Vertex*> vertices;
	List<unsigned int> indices;
	void pack(Renderable::usage hint);
	void pack();
	void setTexture(Texture* tex);
	void setShaderPack(ShaderPack* pack);

private:
	ShaderPack* shaderPack;
	unsigned int* vbos;
	enum buffers {
		POSITIONS,
		TEX_COORDS,
		INDICES,
		BUFFER_COUNT
	};
	Texture* texture;

	List<float> v_positions;
	List<float> v_tex_coords;
};

