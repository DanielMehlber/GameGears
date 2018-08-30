#pragma once
#include "Renderable.h"
#include "List.h"
#include "List.cpp"
#include "Vertex.h"
#include "GLEW/glew.h"
#include "ShaderPack.h"

class Mesh : public Renderable
{
public:
	Mesh();
	~Mesh();
	void render() override;
	List<Vertex*> vertices;
	void pack(Renderable::usage hint);
	void pack();
	ShaderPack* shaders;
	ShaderPack* default_shaders;

	enum buffers {
		POSITIONS,
		BUFFER_COUNT
	};
	unsigned int vaoID;
	unsigned int* vbos;

private:
	List<float> v_positions;
};

