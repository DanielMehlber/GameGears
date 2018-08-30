#include "Application.h"
#include "Mesh.h"

int main() {

	Application app = Application();

	Mesh* mesh = new Mesh();
	//append Vertex
	mesh->vertices.append(new Vertex(-1.0f, -1.0f, 0.0f)->setTexCoords(glm::vec2(0,0)));
	mesh->vertices.append(new Vertex(1.0f, -1.0f, 0.0f)->setTexCoords(glm::vec2(1, 0)));
	mesh->vertices.append(new Vertex(0.0f, 1.0f, 0.0f)->setTexCoords(glm::vec2(0.5, 1)));
	//Pack the vertices
	mesh->pack();

	app.renderer->register_object(mesh);
	app.start();
	
}