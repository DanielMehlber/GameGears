#pragma once
#include "Renderable.h"
#include "List.h"
#include "List.cpp"
#include "Vertex.h"
#include "GLEW/glew.h"
#include "ShaderComponent.h"
#include "Component.h"
#include "Instance.h"

class MeshComponent : public Renderable, public OGLObject, public Component
{
public:
	MeshComponent();
	~MeshComponent();
	void render() override;
	void activate() override;
	void deactivate() override;
	List<Vertex*> vertices;
	List<unsigned int> indices;
	void pack(Renderable::usage hint);
	void pack();

private:
	unsigned int* vbos; 
	enum buffers {
		POSITIONS,
		TEX_COORDS,
		INDICES,
		BUFFER_COUNT
	};

	List<float> v_positions;
	List<float> v_tex_coords;
};

