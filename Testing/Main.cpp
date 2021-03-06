#include "Application.h"
#include "MeshComponent.h"
#include "glm/vec3.hpp"
#include "glm/vec2.hpp"
#include "GLEW/glew.h"
#include "GLFW/glfw3.h"
#include "GameObject.h"
#include "ObjectBehaviorExample.h"
#include "Loader.h"
#include "Input.h"
#include "FlyingCameraBehavior.h"
#include "BehaviorComponent.h"
#include "Camera.h"


int main() {

	Application* app = new Application();
	Camera* cam = app->renderer->getCamera();
	cam->setTarget(cam->getPos() + cam->foreward);

	FlyingCameraBehavior* camCntr = new FlyingCameraBehavior();
	cam->set<BehaviorComponent<Camera>>(camCntr);
	app->taskManager->register_task(camCntr);

	Shader* vertexShader = Loader::loadShader("C:/Users/danie/Google Drive/Game Engine/GameGears/res/vertex.txt", Shader::VERTEX_SHADER);
	Shader* fragmentShader = Loader::loadShader("C:/Users/danie/Google Drive/Game Engine/GameGears/res/fragment.txt", Shader::FRAGMENT_SHADER);

	ShaderComponent* shaderCmp = new ShaderComponent(vertexShader, fragmentShader);
	shaderCmp->pack();

	Texture* tex = new Texture(Loader::loadImage("C:/Users/danie/Google Drive/CG Textures/Ground/BrokenGround.jpg"));

	TextureComponent* textureCmp = new TextureComponent();
	textureCmp->setDiffuse(tex);

	MeshComponent* mesh = new MeshComponent(app->renderer);
	mesh->pack();

	GameObject* object = new GameObject(app->renderer);

	ObjectBehaviorExample* game_object_behavior = new ObjectBehaviorExample();

	object->set<MeshComponent>(mesh);
	object->set<TextureComponent>(textureCmp);
	object->set<ShaderComponent>(shaderCmp);
	object->set<BehaviorComponent<GameObject>>(game_object_behavior);

	for (int i = 0; i < 1; i++)
		object->instance()->setRot(10 * i, 10 * i, 10 * i);

	app->taskManager->register_task(game_object_behavior);

	Input* esc = new Input("escape", GLFW_KEY_ESCAPE, app->canvas);
	esc->mode = Input::InputMode::IMPULS;
	esc->call = [=](Canvas* canvas) {app->close(); };
	app->taskManager->register_task(esc);

	app->renderer->register_object(object);
	app->start();

}

