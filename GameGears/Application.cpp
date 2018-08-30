#include "Application.h"



Application::Application()
{
	canvas = new Canvas();
	renderer = canvas->renderer;
	close_app = [=]() {
		//Destroy Loop and return to outside-application
		taskManager->unregister_task(canvas->update_task);
		taskManager->terminate();
		Application::~Application();
	};
	canvas->close_operations.append(&close_app);
	taskManager = new TaskManager();
	taskManager->register_task(canvas->update_task);
}


Application::~Application()
{

}

void Application::start()
{
	taskManager->start(TaskManager::NO_THREAD);
}

void Application::close()
{
	close_app();
}
