#include "shader.h"





Shader::Shader(const GLchar *vertex_src, const GLchar *fragment_src)
{
	

	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vertex_src, nullptr);
	glCompileShader(vertex);
	
	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fragment_src, nullptr);
	glCompileShader(fragment);

	printf("GL_TRUE: %d\n", GL_TRUE);
	GLint status;
	glGetShaderiv(vertex, GL_COMPILE_STATUS, &status);
	printf("Vertex Status: %d\n", status);
	glGetShaderiv(fragment, GL_COMPILE_STATUS, &status);
	printf("Fragment Status: %d\n", status);

	program = glCreateProgram();
	glAttachShader(program, vertex);
	glAttachShader(program, fragment);
	glLinkProgram(program);
	glValidateProgram(program);
	glDetachShader(program, vertex);
	glDetachShader(program, fragment);
	glDeleteShader(vertex);
	glDeleteShader(fragment);
}


Shader::~Shader()
{
	glDeleteProgram(program);
}

void Shader::bind() {
	glUseProgram(program);
}
