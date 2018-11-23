#include "graphics/window.h"
#include "graphics/shader.h"

int main(void)
{

	Window window(450, 450, "3D Viewer");
	const char* v = "graphics/shaders/vertex.shader";
	const char* f = "graphcis/shaders/fragment.shader";
	Shader program(v, f);
	program.bind();

	while (!glfwWindowShouldClose(window.window)) {
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window.window);
		glfwPollEvents();

		

	}

	return 0;
}