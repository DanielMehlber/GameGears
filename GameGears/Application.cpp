#include "Application.h"



Application::Application()
{
	canvas = new Canvas();
	renderer = canvas->renderer;
	close_app = [=]() {
		//Destroy Loop and return to outside-application
		renderManager->terminate();
		taskManager->terminate();
		Application::~Application();
	};
	canvas->close_operations.append(&close_app);
	renderManager = new TaskManager();
	taskManager = new TaskManager(1);
	renderManager->register_task(canvas->update_task);
}


Application::~Application()
{

}

void Application::start()
{
	taskManager->start(TaskManager::NEW_THREAD);
	renderManager->start(TaskManager::NO_THREAD);
}

void Application::close()
{
	close_app();
}
