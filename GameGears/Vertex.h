#pragma once
#include "glm/vec2.hpp"
#include "glm/vec3.hpp"
class Vertex
{
public:
	Vertex();
	Vertex(glm::vec3 pos);
	Vertex(float x, float y, float z);
	~Vertex();
	glm::vec3 pos;
	glm::vec3 norm;
	glm::vec2 tex_coords;
	Vertex* setPos(glm::vec3 pos);
	Vertex* setNormals(glm::vec3 norm);
	Vertex* setTexCoords(glm::vec2 uv);
};

