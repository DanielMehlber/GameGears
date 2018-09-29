#include "Application.h"
#include "MeshComponent.h"
#include "glm/vec3.hpp"
#include "glm/vec2.hpp"
#include "GLEW/glew.h"
#include "GLFW/glfw3.h"
#include "GameObject.h"
#include "ObjectBehaviorExample.h"
#include "Loader.h"


int main() {

	List<GameObject*> ints = List<GameObject*>();
	ints.size();

	Application app = Application();

	Shader* vertexShader = Loader::loadShader(Shader::VERTEX_SHADER, "C:/Users/danie/Google Drive/Game Engine/GameGears/res/vertex.txt");
	Shader* fragmentShader = Loader::loadShader(Shader::FRAGMENT_SHADER, "C:/Users/danie/Google Drive/Game Engine/GameGears/res/fragment.txt");
	
	ShaderComponent* shaderCmp = new ShaderComponent(vertexShader, fragmentShader);
	shaderCmp->pack();

	Texture* tex = new Texture(Loader::loadImage("C:/Users/danie/Google Drive/CG Textures/Ground/BrokenGround.jpg"));

	TextureComponent* textureCmp = new TextureComponent();
	textureCmp->setDiffuse(tex);

	MeshComponent* mesh = new MeshComponent(app.renderer);
	mesh->pack();

	GameObject* object = new GameObject(app.renderer);

	ObjectBehaviorExample* game_object_behavior = new ObjectBehaviorExample();

	object->set<MeshComponent>(mesh);
	object->set<TextureComponent>(textureCmp);
	object->set<ShaderComponent>(shaderCmp);
	object->set<BehaviorComponent<GameObject>>(game_object_behavior);
	for (int i = 0; i < 1; i++)
		object->instance()->setRot(10 * i, 10 * i, 10 * i);

	app.taskManager->register_task(game_object_behavior);

	app.renderer->register_object(object);
	app.start();
	
}

