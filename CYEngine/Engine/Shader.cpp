#include "Shader.h"
#include<fstream>
#include<iostream>
#include<sstream>

USING_STD
Shader::Shader(const char* vertexPath, const char* fragmentPath):ID(-1) {

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

		
		vertexSource[1] = vertexSStream.str();
		vertexSource[1].replace(0, string("#version 330 core").size(), "");

		fragmentSource[1] = fragmentSStream.str();
		fragmentSource[1].replace(0, string("#version 330 core").size(), "");
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}
/*
* TODO  不能返回局部变量，将引起shader编译错误
*/
const char* const* Shader::GetVertexSource()
{   
	const char* source[2] = { vertexSource[0].c_str(), vertexSource[1].c_str() };
	return source;
}

const char* const* Shader::GetFragmentSource()
{
	const char* source[2] = { fragmentSource[0].c_str(), fragmentSource[1].c_str() };
	return source;
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

void Shader::setIntArray(const string& name, int count, const int* array, bool isArray) const
{
	GlUniform(GlGetUniformLocation(ID, name.c_str()), count, array, isArray);
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

void Shader::setFloatArray(const string& name, int count, const float* array, bool isArray) const
{
	GlUniform(GlGetUniformLocation(ID, name.c_str()), count, array, isArray);
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

void Shader::setTexture(const string& name, int textureSlot) const
{
	GlUniform(GlGetUniformLocation(ID, name.c_str()), textureSlot);
}

void Shader::define(const string& name, const string& value)
{
	vertexSource[0] += "#define " + name + " " + value + "\n";
	fragmentSource[0] += "#define " + name + " " + value + "\n";
}

void Shader::setMatrix4x4(const string& name, GLsizei count, GLboolean transpose, const GLfloat* value, bool isArray) const
{
	GlUniformMatrix4v(GlGetUniformLocation(ID, name.c_str()), count, transpose, value, isArray);
}

bool Shader::compile()
{
	unsigned int vertex, fragment;
	
	// 编译顶点着色器
	vertex = GlCreateShader(GL_VERTEX_SHADER);
	const char* source1[2] = { vertexSource[0].c_str(), vertexSource[1].c_str() };
	int len1[2] = { vertexSource[0].size(), vertexSource[1].size() };
	
	GlShaderSource(vertex, 2, source1, len1);
	GlCompileShader(vertex);
	if (!checkCompileResult(vertex, GL_COMPILE_STATUS, "Vertex")) {
		return false;
	}

	// 编译片元着色器
	fragment = GlCreateShader(GL_FRAGMENT_SHADER);
	const char* source2[2] = { fragmentSource[0].c_str(), fragmentSource[1].c_str() };
	int len2[2] = { fragmentSource[0].size(), fragmentSource[1].size() };
	GlShaderSource(fragment, 2, source2, len2);
	GlCompileShader(fragment);
	if (!checkCompileResult(fragment, GL_COMPILE_STATUS, "Fragment")) {
		return false;
	}

	// link
	ID = GlCreateProgram();
	GlAttachShader(ID, vertex);
	GlAttachShader(ID, fragment);
	GlLinkProgram(ID);
	if (!checkCompileResult(ID, GL_LINK_STATUS, "Linker")) {
		return false;
	}


	GlDeleteShader(vertex);
	GlDeleteShader(fragment);

	return true;
}
bool Shader::checkCompileResult(GLuint shader, GLenum pname, const string& name)
{
	char infoLog[512];
	int success;
	GlGetShaderiv(shader, pname, &success);
	if (!success) {
		GlGetShaderInfoLog(shader, 512, NULL, infoLog);
		cout << "ERROR::SHADER::"<< name <<"::COMPILE ERROR : " << infoLog << endl;
		return false;
	}
	return true;
}



