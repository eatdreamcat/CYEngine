#include "Shader.h"
#include<fstream>
#include<iostream>
#include<sstream>

USING_STD
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
	
	GlUniform(GlGetUniformLocation(ID, name.c_str()), (int)value);
}

void Shader::setInt(const string& name, int value) const
{
	GlUniform(GlGetUniformLocation(ID, name.c_str()), value);
}

void Shader::setIntArray(const string& name, int count, int* array) const
{
	GlUniform(GlGetUniformLocation(ID, name.c_str()), count, array);
}

void Shader::setInt(const string& name, int value0, int value1) const
{
	GlUniform(GlGetUniformLocation(ID, name.c_str()), value0, value1);
}

void Shader::setInt(const string& name, int value0, int value1, int value2) const
{
	GlUniform(GlGetUniformLocation(ID, name.c_str()), value0, value1, value2);
}

void Shader::setInt(const string& name, int value0, int value1, int value2, int value3) const
{
	GlUniform(GlGetUniformLocation(ID, name.c_str()), value0, value1,value2,value3);
}

void Shader::setFloat(const string& name, float value) const
{
	GlUniform(GlGetUniformLocation(ID, name.c_str()), value);
}

void Shader::setFloatArray(const string& name, int count, float* array) const
{
	GlUniform(GlGetUniformLocation(ID, name.c_str()), count, array);
}

void Shader::setFloat(const string& name, float value0, float value1) const
{
	GlUniform(GlGetUniformLocation(ID, name.c_str()), value0, value1);
}

void Shader::setFloat(const string& name, float value0, float value1, float value2) const
{
	GlUniform(GlGetUniformLocation(ID, name.c_str()), value0, value1, value2);
}

void Shader::setFloat(const string& name, float value0, float value1, float value2, float value3) const
{
	GlUniform(GlGetUniformLocation(ID, name.c_str()), value0, value1, value2, value3);
}

void Shader::setMatrix4x4(const string& name, GLsizei count, GLboolean transpose, const GLfloat* value) const
{
	GlUniformMatrix4v(GlGetUniformLocation(ID, name.c_str()), count, transpose, value);
}

bool Shader::compile()
{
	unsigned int vertex, fragment;
	
	// 编译顶点着色器
	vertex = GlCreateShader(GL_VERTEX_SHADER);
	GlShaderSource(vertex, 1, GetVertexSource(), NULL);
	GlCompileShader(vertex);
	if (!checkCompileResult(vertex, GL_COMPILE_STATUS)) {
		return false;
	}

	// 编译片元着色器
	fragment = GlCreateShader(GL_FRAGMENT_SHADER);
	GlShaderSource(fragment, 1, GetFragmentSource(), NULL);
	GlCompileShader(fragment);
	if (!checkCompileResult(fragment, GL_COMPILE_STATUS)) {
		return false;
	}

	// link
	ID = GlCreateProgram();
	GlAttachShader(ID, vertex);
	GlAttachShader(ID, fragment);
	GlLinkProgram(ID);
	if (!checkCompileResult(ID, GL_LINK_STATUS)) {
		return false;
	}


	GlDeleteShader(vertex);
	GlDeleteShader(fragment);

	return true;
}
bool Shader::checkCompileResult(GLuint shader, GLenum pname)
{
	char infoLog[512];
	int success;
	GlGetShaderiv(shader, pname, &success);
	if (!success) {
		GlGetShaderInfoLog(shader, 512, NULL, infoLog);
		cout << "ERROR::SHADER::COMPILE ERROR:" << infoLog << endl;
		return false;
	}
	return true;
}



