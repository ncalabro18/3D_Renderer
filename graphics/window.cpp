#include "window.h"


Window::Window(int width, int height, const char* title)
{
	if (!glfwInit()) {
		printf("Failed to initialize GLFW!\n");
		return;
	}
	window = glfwCreateWindow(width, height, title, nullptr, nullptr);
	glfwMakeContextCurrent(window);
	
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);


}


Window::~Window()
{
	glfwTerminate();
}
