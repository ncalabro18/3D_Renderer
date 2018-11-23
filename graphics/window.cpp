
#include "window.h"


Window::Window(int width, int height, const char* title)
{
	if (!glfwInit()) {
		printf("Failed to initialize GLFW!\n");
		return;
	}
	window = glfwCreateWindow(width, height, title, nullptr, nullptr);
	glfwMakeContextCurrent(window);
	
	glewExperimental = GL_TRUE;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	if (glewInit() != GLEW_OK) {
		printf("Failed to initialize GLEW!\n");
		return;
	}
}


Window::~Window()
{
	glfwTerminate();
}
