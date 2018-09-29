#include "Canvas.h"



Canvas::Canvas(int width, int height, const char* title)
{

	update_func = [=](SyncTask* task) {return update(task); };
	update_task = new SyncTask("canvas-update", &update_func, 60);

	close_operations = List<std::function<void()>*>();

	if (!glfwInit()) {
		Console::err("INIT-ERROR", "Failed to init GLFW library");
		Console::leave();
	}

	window = glfwCreateWindow(width, height, title, NULL, NULL);
	glfwSetFramebufferSizeCallback(window, this->on_resize);

	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK) {
		Console::err("INIT-ERROR", "Failed to init GLEW library");
		glfwTerminate();
		Console::leave();
	}

	glViewport(0, 0, width, height);
	glClearColor(0.0, 0.1, 0.3, 1);

	renderer = new RenderComponent(new Camera(this));
}

Canvas::Canvas(int width, int height):Canvas(width, height, "GameGear - Powered by NEON-Graphics")
{
}

Canvas::Canvas() : Canvas(1280, 720)
{
}


Canvas::~Canvas()
{
}

int Canvas::update(SyncTask* task)
{
	if (glfwWindowShouldClose(window)) {
		task->terminate();
		close();
	}

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	renderer->render();

	glfwSwapBuffers(window);

	glfwPollEvents();

	return Task::CONTINUE;
}

void Canvas::close()
{
	glfwDestroyWindow(window);
	glfwTerminate();

	//Execute all additional Close Operations
	for (std::function<void()>* co : *close_operations.getData()) {
		std::cout << "close operation found" << std::endl;
		(*co)();
	}

	Canvas::~Canvas();
	
}

void Canvas::on_resize(GLFWwindow * window, int width, int height)
{
	glViewport(0, 0, width, height);
}

float Canvas::getWidth()
{
	glfwGetWindowSize(window, &width, &height);
	return width;
}

float Canvas::getHeight()
{
	glfwGetWindowSize(window, &width, &height);
	return height;
}

float Canvas::getAspectRatio()
{
	glfwGetWindowSize(window, &width, &height);
	return ((float)width) / ((float)height);
}

