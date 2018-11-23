#include "shader.h"



Shader::Shader(const char* fileV, const char * fileF)
{
	

	vertex = glCreateShader(GL_VERTEX_SHADER);
	const GLchar* src= getSource(fileV).c_str();
	glShaderSource(vertex, 1, &src, nullptr);
	glCompileShader(vertex);
	

	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	src = getSource(fileF).c_str();
	glShaderSource(fragment, 1, &src, nullptr);
	glCompileShader(fragment);
	

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


std::string Shader::getSource(const char* filePath) 
{
	FILE *srcFile = fopen(filePath, "r");
	if (srcFile == NULL) {
		printf("Failed to open file %s\n", filePath);
		return nullptr;
	}
	unsigned int fileSize = fseek(srcFile,0, SEEK_END);
	GLchar *fileData = new char[fileSize + 1];
	memset(fileData, 0, fileSize + 1);
	fseek(srcFile, 0, SEEK_SET);
	fread(fileData, 1, fileSize, srcFile);

	fclose(srcFile);

	std::string src(fileData);
	delete[] fileData;
	return src;
}