#include "Application.h"
#include "MeshComponent.h"
#include "glm/vec3.hpp"
#include "glm/vec2.hpp"
#include "GLEW/glew.h"
#include "GLFW/glfw3.h"
#include "GameObject.h"




int main() {

	List<GameObject*> ints = List<GameObject*>();
	ints.size();

	Application app = Application();

	Shader* vertexShader = Shader::loadShader(Shader::VERTEX_SHADER, "C:/Users/danie/Google Drive/Game Engine/GameGears/res/vertex.txt");
	Shader* fragmentShader = Shader::loadShader(Shader::FRAGMENT_SHADER, "C:/Users/danie/Google Drive/Game Engine/GameGears/res/fragment.txt");
	
	ShaderComponent* shaderCmp = new ShaderComponent(vertexShader, fragmentShader);
	shaderCmp->pack();

	Texture* tex = Texture::loadTexture("C:/Users/danie/Google Drive/CG Textures/Ground/Snow_512_n.jpg");

	TextureComponent* textureCmp = new TextureComponent();
	textureCmp->setDiffuse(tex);

	MeshComponent* mesh = new MeshComponent();
	mesh->pack();

	GameObject* object = new GameObject();

	object->setComponent<MeshComponent>(mesh);
	object->setComponent<ShaderComponent>(shaderCmp);
	object->setComponent<TextureComponent>(textureCmp);

	app.renderer->register_object(object);
	app.start();
	
}

