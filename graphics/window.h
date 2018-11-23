#pragma once
#include <glfw3.h>
#include <stdio.h>

class Window
{
public:
	GLFWwindow *window;
public:
	Window(int width, int height, const char* title);
	~Window();
};

