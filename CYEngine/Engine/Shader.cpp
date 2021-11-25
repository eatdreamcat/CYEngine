#include "Shader.h"
#include<fstream>
#include<iostream>
#include<sstream>
#include "OpenGLMacros.h"
USING_STD
NS_CY_BEGIN
Shader::Shader(const char* vertexPath, const char* fragmentPath):vertexSource(nullptr),fragmentSource(nullptr),ID(-1){

	ifstream vertexFile;
	ifstream fragmentFile;
	

	vertexFile.exceptions ( ifstream::failbit | ifstream::badbit );
	fragmentFile.exceptions (ifstream::failbit | ifstream::badbit);
	try
	{

		vertexFile.open(vertexPath);
		fragmentFile.open(fragmentPath);
		
		if (!vertexFile.is_open() || !fragmentFile.is_open()) {
			throw exception("shader file open failed.");
		}
		stringstream vertexSStream;
		stringstream fragmentSStream;
		vertexSStream << vertexFile.rdbuf();
		fragmentSStream << fragmentFile.rdbuf();

		vertexFile.close();
		fragmentFile.close();

		vertexString = vertexSStream.str();
		fragmentString = fragmentSStream.str();

		vertexSource = vertexString.c_str();
		fragmentSource = fragmentString.c_str();

		if (!compile()) {
			throw exception("shader compile failed.");
		}
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}
void Shader::use()
{
	if (ID == -1) {


		cout << " PROGRAM not compile." << endl;
		return;
	}

	GlUseProgram(ID);
}

void Shader::setBool(const string& name, bool value) const
{
}

void Shader::setInt(const string& name, int value) const
{
}

void Shader::setFloat(const string& name, float value) const
{
}

bool Shader::compile()
{
	unsigned int vertex, fragment;
	
	char infoLog[512];
	int success;

	vertex = GlCreateShader(GL_VERTEX_SHADER);
	GlShaderSource(vertex, 1, GetVertexSource(), NULL);

	GlCompileShader(vertex);
	GlGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
	if (!success) {
		GlGetShaderInfoLog(vertex, 512, NULL, infoLog);
		cout << "ERROR::SHADER::VERTEX::COMPILE ERROR:" << infoLog << endl;
		return false;
	}

	fragment = GlCreateShader(GL_FRAGMENT_SHADER);
	GlShaderSource(fragment, 1, GetFragmentSource(), NULL);

	GlCompileShader(fragment);
	GlGetShaderiv(fragment, GL_COMPILE_STATUS, &success);

	if (!success) {
		GlGetShaderInfoLog(fragment, 512, NULL, infoLog);
		cout << "ERROR::SHADER::FRAGMENT::COMPILE ERROR:" << infoLog << endl;
		return false;
	}

	ID = GlCreateProgram();
	GlAttachShader(ID, vertex);
	GlAttachShader(ID, fragment);
	GlLinkProgram(ID);
	GlGetShaderiv(ID, GL_LINK_STATUS, &success);
	if (!success) {
		GlGetShaderInfoLog(ID, 512, NULL, infoLog);
		cout << "ERROR::SHADER::LINK ERROR:" << infoLog << endl;
		return false;
	}

	GlDeleteShader(vertex);
	GlDeleteShader(fragment);

	return true;
}
NS_CY_END


