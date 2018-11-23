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
	Shader(const char * fileV, const char *fileF);
	~Shader();
	void bind();
private:
	std::string getSource(const char *filePath);
};