#include <math.h>
#include "graphics/shader.h"
#include "graphics/window.h"
#include "math/vec3.h"
#include "math/triangle.h"
#include "math/mat3.h"

const GLchar *vertex_src = R"glsl(
#version 330 core

layout(location = 0) in vec2 position;

void main() {
	gl_Position = vec4(position, 0.0, 1.0);
}
)glsl";

const GLchar *fragment_src = R"glsl(
#version 330 core

layout(location = 0) out vec4 color;

void main() {
	color = vec4(1.0, 1.0, 1.0, 1.0);
}
)glsl";

int main(void)
{
	Window window(450, 450, "3D Viewer");
	Shader program(vertex_src, fragment_src);
	glBindFragDataLocation(program.program, 0, "color");
	program.bind();

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	Triangle triangles[4] = {
		Triangle(
			Vec3(0.5f, 0.5f,  0.5f),
			Vec3(-0.5f,-0.5f,  0.5f),
			Vec3(-0.5f, 0.5f, -0.5f)),
		Triangle(
			Vec3(0.5f, 0.5f,  0.5f),
			Vec3(-0.5f,-0.5f,  0.5f),
			Vec3(0.5f,-0.5f, -0.5f)),
		Triangle(
			Vec3(-0.5f, 0.5f, -0.5f),
			Vec3(0.5f,-0.5f, -0.5f),
			Vec3(0.5f, 0.5f,  0.5f)),
		Triangle(
			Vec3(-0.5f, 0.5f, -0.5f),
			Vec3(0.5f,-0.5f, -0.5f),
			Vec3(-0.5f,-0.5f,  0.5f))
	};


	GLuint vbo;

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	GLuint attrib_pos = glGetAttribLocation(program.program, "position");

	glVertexAttribPointer(attrib_pos, 2, GL_FLOAT, GL_FALSE, 0, 0);

	glEnableVertexAttribArray(attrib_pos);

	double heading = 0.0, pitch = 0.0;

	while (!glfwWindowShouldClose(window.window)) {
		pitch += .00007;
		heading -= .00007;
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwPollEvents();
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

		double hvals[] = 
		{
			cos(heading), 0.0, sin(heading),
			0.0, 1.0, 0.0,
			-sin(heading), 0.0, cos(heading)
		};
		Mat3 ht(hvals);

		double pvals[] =
		{
			1.0, 0.0, 0.0,
			0.0, cos(pitch), sin(pitch),
			0.0, -sin(pitch), cos(pitch)
		};
		Mat3 pt(pvals);

		Mat3 transform = pt * ht;
		float vboBuffer[24];
		for (int i = 0; i < 4; i++) {
			Vec3 v_1 = transform.transform(triangles[i].x);
			Vec3 v_2 = transform.transform(triangles[i].y);
			Vec3 v_3 = transform.transform(triangles[i].z);
		
			vboBuffer[i * 6 + 0] = v_1.x;
			vboBuffer[i * 6 + 1] = v_1.y;
			vboBuffer[i * 6 + 2] = v_2.x;
			vboBuffer[i * 6 + 3] = v_2.y;
			vboBuffer[i * 6 + 4] = v_3.x;
			vboBuffer[i * 6 + 5] = v_3.y;
		}

		glBufferData(GL_ARRAY_BUFFER, 24 * sizeof(float), vboBuffer, GL_STATIC_DRAW);
		glDrawArrays(GL_TRIANGLES, 0, 24 / 3 + 1);

		glfwSwapBuffers(window.window);
	}

	glDeleteBuffers(1, &vbo);
	glDeleteVertexArrays(1, &vao);


	return 0;
}