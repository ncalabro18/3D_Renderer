#pragma once
#include <glew.h>
#include <stdio.h>
#include <string.h>

class Shader
{
private:
	GLuint program;
	GLuint vertex, fragment;
public:
	Shader(const char * fileV, const char *fileF);
	~Shader();
	void bind();
private:
	GLchar* getSource(const char *filePath);
};