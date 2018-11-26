#pragma once
#define GLEW_STATIC
#include <glew.h>
#include <stdio.h>
#include <string.h>
#include <string>

class Shader
{
public:
	GLuint program;
private:
	GLuint vertex, fragment;
public:
	Shader(const GLchar * fileV, const GLchar *fileF);
	~Shader();
	void bind();
};