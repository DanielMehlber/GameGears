#pragma once

#include "RenderComponent.h"
#include "GLEW/glew.h"
#include "GLFW/glfw3.h"
#include "List.h"
#include "List.cpp"
#include "SyncTask.h"
class Canvas
{
public:
	Canvas(int width, int height, const char* title);
	Canvas(int width, int height);
	Canvas();
	~Canvas();
	int update(SyncTask* task);
	void close();
	static void on_resize(GLFWwindow* window, int width, int height);
	RenderComponent* renderer;
	GLFWwindow* window;
	SyncTask* update_task;
	List<std::function<void()>*> close_operations;
	std::function<int(SyncTask* task)> update_func;
};

