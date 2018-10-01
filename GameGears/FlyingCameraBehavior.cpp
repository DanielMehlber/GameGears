#include "FlyingCameraBehavior.h"



FlyingCameraBehavior::FlyingCameraBehavior() : BehaviorComponent<Camera>("flying_camera_behavior")
{
	speed = -0.1f;
}


FlyingCameraBehavior::~FlyingCameraBehavior()
{
}

void FlyingCameraBehavior::update(Camera * cam, SyncTask * task)
{


	if (Input::is_pressed(cam->getCanvas(), GLFW_KEY_W)) {
		foreward(cam, speed);
	}

	if (Input::is_pressed(cam->getCanvas(), GLFW_KEY_A)) {
		left(cam, speed);
	}

	if (Input::is_pressed(cam->getCanvas(), GLFW_KEY_D)) {
		right(cam, speed);
	}

	if (Input::is_pressed(cam->getCanvas(), GLFW_KEY_S)) {
		backward(cam, speed);
	}


}

void FlyingCameraBehavior::start(Camera * cam, SyncTask * task)
{
}

void FlyingCameraBehavior::destroy(Camera * cam, SyncTask * task)
{
}

void FlyingCameraBehavior::pause(Camera * cam, SyncTask * task)
{
}

void FlyingCameraBehavior::foreward(Camera* cam, float speed) {
	cam->move(0,0,-speed);
}

void FlyingCameraBehavior::left(Camera* cam, float speed) {
	cam->move(speed, 0.0f, 0.0f);
}

void FlyingCameraBehavior::right(Camera* cam, float speed) {
	cam->move(-speed, 0.0f, 0.0f);
}

void FlyingCameraBehavior::backward(Camera* cam, float speed) {
	cam->move(0, 0, speed);
}