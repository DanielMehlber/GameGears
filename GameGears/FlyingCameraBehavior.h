#pragma once
#include "BehaviorComponent.h"
#include "BehaviorComponent.cpp"
#include "Camera.h"
#include "Input.h"
class FlyingCameraBehavior : public BehaviorComponent<Camera>
{
public:
	FlyingCameraBehavior();
	~FlyingCameraBehavior();
	void update(Camera* cam, SyncTask* task) override;
	void start(Camera* cam, SyncTask* task) override;
	void destroy(Camera* cam, SyncTask* task) override;
	void pause(Camera* cam, SyncTask* task) override;
	static void foreward(Camera* cam, float speed);
	static void right(Camera* cam, float speed);
	static void left(Camera* cam, float speed);
	static void backward(Camera* cam, float speed);
	float speed;
};

