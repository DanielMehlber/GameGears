#include "Application.h"
#include "Mesh.h"
#include "glm/vec3.hpp"
#include "glm/vec2.hpp"

int main() {

	Application app = Application();
	
	

	Shader* vertexShader = Shader::loadShader(Shader::VERTEX_SHADER, "C:/Users/danie/Google Drive/Game Engine/GameGears/res/vertex.txt");
	Shader* fragmentShader = Shader::loadShader(Shader::FRAGMENT_SHADER, "C:/Users/danie/Google Drive/Game Engine/GameGears/res/fragment.txt");
	ShaderPack* shaderpack = new ShaderPack();
	shaderpack->setVertexShader(vertexShader);
	shaderpack->setFragmentShader(fragmentShader);
	shaderpack->pack();
	


	

	Vertex* v1 = new Vertex(-1.0f, -1.0f, 0.0f);
	v1->setTexCoords(glm::vec2(0, 0));
	Vertex* v2 = new Vertex(1.0f, -1.0f, 0.0f);
	v2->setTexCoords(glm::vec2(1, 0));
	Vertex* v3 = new Vertex(0, 1, 0);
	v3->setTexCoords(glm::vec2(0.5, 1)); 

	Texture* tex = Texture::loadTexture("C:/Users/danie/Google Drive/CG Textures/Ground/Snow_512_n.jpg");


	Mesh* mesh = new Mesh();
	mesh->vertices.append(v1);
	mesh->vertices.append(v2);
	mesh->vertices.append(v3);
	mesh->indices.append((unsigned int)0);
	mesh->indices.append(1);
	mesh->indices.append(2);
	mesh->shaders = shaderpack;
	mesh->diffuseTexture = tex;
	mesh->pack();

	app.renderer->register_object(mesh);
	app.start();
	
}