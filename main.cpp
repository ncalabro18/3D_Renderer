#include "graphics/shader.h"
#include "graphics/window.h"
#include "math/vec3.h"

int main(void)
{
	Window window(450, 450, "3D Viewer");
	const char* v = "src/graphics/shaders/vertex.shader";
	const char* f = "src/graphics/shaders/fragment.shader";
	Shader program(v, f);
	glBindFragDataLocation(program.program, 0, "color");
	program.bind();

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	Vec3 tri1[3] = { Vec3( 0.05f, 0.05f,  0.05f),
				     Vec3(-0.05f,-0.05f,  0.05f),
				     Vec3(-0.05f, 0.05f, -0.05f) };

	Vec3 tri2[3] = { Vec3( 0.05f, 0.05f,  0.05f),
				     Vec3(-0.05f,-0.05f,  0.05f),
				     Vec3( 0.05f,-0.05f, -0.05f) };

	Vec3 tri3[3] = { Vec3(-0.05f, 0.05f, -0.05f),
				     Vec3( 0.05f,-0.05f, -0.05f),
				     Vec3( 0.05f, 0.05f,  0.05f) };

	Vec3 tri4[3] = { Vec3(-0.05f, 0.05f, -0.05f),
				     Vec3( 0.05f,-0.05f, -0.05f),
				     Vec3(-0.05f,-0.05f,  0.05f) };

	GLuint vbo;

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	GLuint attrib_pos = glGetAttribLocation(program.program, "position");

	glVertexAttribPointer(attrib_pos, 2, GL_FLOAT, GL_FALSE, 0, 0);
	
	glEnableVertexAttribArray(attrib_pos);
	float vboBuffer[] = { 0.0f,  0.5f,
							0.5f, -0.5f,
						   -0.5f, -0.5f };

	glBufferData(GL_ARRAY_BUFFER, sizeof(vboBuffer), vboBuffer, GL_STATIC_DRAW);

	while (!glfwWindowShouldClose(window.window)) {
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwPollEvents();		
		
		//{tri1[0].x, tri1[0].y, tri1[1].x, tri1[1].y, tri1[2].x, tri1[2].y  {...} };

		glDrawArrays(GL_TRIANGLES, 0, 3);


		glfwSwapBuffers(window.window);
	}

	glDeleteBuffers(1, &vbo);
	glDeleteVertexArrays(1, &vao);
	

	return 0;
}