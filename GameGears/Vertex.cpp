#include "Vertex.h"



Vertex::Vertex()
{
}

Vertex::Vertex(glm::vec3 pos) : pos{pos}
{
}

Vertex::Vertex(float x, float y, float z)
{
	pos = glm::vec3(x, y, z);
}


Vertex::~Vertex()
{
}

Vertex * Vertex::setPos(glm::vec3 pos)
{
	Vertex::pos = pos;
	return this;
}

Vertex * Vertex::setNormals(glm::vec3 norm)
{
	Vertex::norm = norm;
	return this;
}

Vertex * Vertex::setTexCoords(glm::vec2 uv)
{
	Vertex::tex_coords = uv;
	return this;
}
