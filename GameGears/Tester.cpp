#include "Application.h"
#include "Mesh.h"
#include "glm/vec3.hpp"
#include "glm/vec2.hpp"
#include "GLEW/glew.h"
#include "GLFW/glfw3.h"



int main() {

	Application app = Application();

	Shader* vertexShader = Shader::loadShader(Shader::VERTEX_SHADER, "C:/Users/danie/Google Drive/Game Engine/GameGears/res/vertex.txt");
	Shader* fragmentShader = Shader::loadShader(Shader::FRAGMENT_SHADER, "C:/Users/danie/Google Drive/Game Engine/GameGears/res/fragment.txt");
	ShaderPack* shaderpack = new ShaderPack();
	shaderpack->setVertexShader(vertexShader);
	shaderpack->setFragmentShader(fragmentShader);
	shaderpack->pack();
	

	Texture* tex = Texture::loadTexture("C:/Users/danie/Google Drive/CG Textures/Ground/Snow_512_n.jpg");


	Mesh* mesh = new Mesh();
	mesh->setShaderPack(shaderpack);
	mesh->setTexture(tex);
	mesh->pack();

	app.renderer->register_object(mesh);
	app.start();
	
}

