#pragma once
#include "Canvas.h"
#include "TaskManager.h"
#include <thread>
class Application
{
public:
	Application();
	~Application();
	Canvas* canvas;
	RenderComponent* renderer;
	TaskManager* taskManager;
	void start();
	void close();

private:
	std::function<void()> close_app;
};

