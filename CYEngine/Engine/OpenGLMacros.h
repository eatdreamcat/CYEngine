
#ifndef __OPENGL_MACROS__
#define __OPENGL_MACROS__
#define STB_IMAGE_IMPLEMENTATION

#define GLEW_STATIC
#include "EngineMacros.h"
#include<GL/glew.h>
#include<GLFW/glfw3.h>
//#include <stb_image.h>

/**
*
*
*
*
* **************************** ��ʼ�����api
*
*
*
*
*/

/* ��ʼ��GLFW �ڵ�������glfw����֮ǰ*/
inline int GlfwInit() {
	glewExperimental = true;
	return glfwInit();
}

/* ���ô����hint */
inline void GlfwWindowHint(int hint, int value) {
	glfwWindowHint(hint, value);
}

/* ����һ������ */
inline GLFWwindow* GlfwCreateWindow(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share) {
	return glfwCreateWindow(width, height, title, monitor, share);
}

/* ֹͣ���д��ڲ��ͷ����������Դ */
inline void GlfwTerminate() {
	glfwTerminate();
}

/* ���ô��������ģ�һ��������ֻ��ͬʱ��һ���߳� */
inline void GlfwMakeContextCurrent(GLFWwindow* window) {
	glfwMakeContextCurrent(window);
}

/*�жϳ�ʼ��*/
inline GLenum GlewInit() {
	return glewInit();
}

/* ����ɻ��ƴ������� */
inline void GlViewport(GLint x, GLint y, GLsizei width, GLsizei height) {
	glViewport(x, y, width, height);
}

/*��ⴰ���Ƿ񱻹ر�*/
inline int GlfwWindowShouldClose(GLFWwindow* window) {
	return glfwWindowShouldClose(window);
}

/*��ȡʱ�䣨�룩*/
inline double GlfwGetTime() {
	return glfwGetTime();
}

inline void GlfwPollEvents() {
	glfwPollEvents();
}









/**
*
*
*
*
* **************************** �������api
*
*
*
*
*/


/* �������� */
inline void GlEnable(GLenum cap) {
	glEnable(cap);
}

/* �޳��� */
inline void GlCullFace(GLenum mode) {
	glCullFace(mode);
}

/* �����ģʽ���� */
inline void GlPolygonMode(GLenum face, GLenum mode) {
	glPolygonMode(face, mode);
}

/*������������ɫ*/
inline void GlClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) {
	glClearColor(red, green, blue, alpha);
}

/*ָ�����λ*/
inline void GlClear(GLbitfield mask) {
	glClear(mask);
}

/*ͨ�����������ķ�ʽ����
*  @param mode ����ģʽ
*  @param count  ��������
*  @param type  ������������
*  @param indices  ��������
*/
inline void GlDrawElements(GLenum mode, GLsizei count, GLenum type, const void* indices) {
	glDrawElements(mode, count, type, indices);
}

inline void GlDrawArrays(GLenum mode,GLint first, GLsizei count) {
	glDrawArrays(mode, first, count);
}

/* Swaps the front and back buffers of the specified window.
*  ����ǰ�˻������ͺ�̨������������
*/
inline void GlfwSwapBuffers(GLFWwindow* window) {
	glfwSwapBuffers(window);
}











/**
*
*
*
*
* **************************** �����������api
*
*
*
*
*/


/* ���� VAO�ռ� */
inline void GlGenVertexArrays(GLsizei n, GLuint* arrays) {
	glGenVertexArrays(n, arrays);
}

/* �󶨵�ǰҪ�õ�VAO id*/
inline void GlBindVertexArray(GLuint array) {
	glBindVertexArray(array);
}

/* ����Buffer */
inline void GlGenBuffers(GLsizei n, GLuint* buffers) {
	glGenBuffers(n, buffers);
}

/* ��bufferĿ��*/
inline void GlBindBuffer(GLenum target, GLuint buffer) {
	glBindBuffer(target, buffer);
}

/* ��buffer��������*/
inline void GlBufferData(GLenum target, GLsizeiptr size, const void* data, GLenum usage) {
	glBufferData(target, size, data, usage);
}

/*** ����VAO��ȡ��ʽ
*  @param index ͨ��ID ��0-15��
*  @param size  ÿ�����ݴ�С
*  @param type  ��������
*  @param normalized  �Ƿ��׼��
*  @param stride  ÿ�����ݵĲ���
*  @param pointer  ��ʼλ��
*/
inline void GlVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer) {
	glVertexAttribPointer(index, size, type, normalized, stride, pointer);
}

/*����VAOͨ��*/
inline void GlEnableVertexAttribArray(GLuint index) {
	glEnableVertexAttribArray(index);
}











/**
*
*
*
*
* **************************** ��ɫ�����api
*
*
*
*
*/


/*����shader*/
inline GLuint GlCreateShader(GLenum type) {
	return glCreateShader(type);
}

/*��shaderԴ����*/
inline void GlShaderSource(GLuint shader, GLsizei count, const GLchar* const* string, const GLint* length) {
	glShaderSource(shader, count, string, length);
}

/*����shader����*/
inline void GlCompileShader(GLuint shader) {
	glCompileShader(shader);
}

/*����һ��shader����*/
inline GLuint GlCreateProgram() {
	return glCreateProgram();
}

/*��shader��shader������*/
inline void GlAttachShader(GLuint program, GLuint shader) {
	glAttachShader(program, shader);
}

/*����shader����*/
inline void GlLinkProgram(GLuint program) {
	glLinkProgram(program);
}




/*��ȡuniform������λ��*/
inline GLint GlGetUniformLocation(GLuint program, const GLchar* name) {
	return glGetUniformLocation(program, name);
}

/*ָ����ǰҪ�õ�shader����*/
inline void GlUseProgram(GLuint program) {
	glUseProgram(program);
}

/*��shader������ n float ���� uniform*/
inline void GlUniform(GLint location, GLsizei count, const GLfloat* value) {
	switch (count)
	{
	case 1:
		glUniform1fv(location, count, value);
		break;
	case 2:
		glUniform2fv(location, count, value);
		break;
	case 3:
		glUniform3fv(location, count, value);
		break;
	case 4:
		glUniform4fv(location, count, value);
		break;
	default:
		break;
	}
}

/*��shader������ n int ���� uniform*/
inline void GlUniform(GLint location, GLsizei count, const GLint* value) {
	switch (count)
	{
	case 1:
		glUniform1iv(location, count, value);
		break;
	case 2:
		glUniform2iv(location, count, value);
		break;
	case 3:
		glUniform3iv(location, count, value);
		break;
	case 4:
		glUniform4iv(location, count, value);
		break;
	default:
		break;
	}
}

/*��shader������ 4x4 ����*/
inline void  GlUniformMatrix4v(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) {
	glUniformMatrix4fv(location, count, transpose, value);
}



/*��shader������ 1 int ���� uniform*/
inline void GlUniform(GLint location, GLint v0) {
	glUniform1i(location, v0);
}

/*��shader������ 2 int ���� uniform*/
inline void GlUniform(GLint location, GLint v0, GLint v1) {
	glUniform2i(location, v0, v1);
}

/*��shader������ 3 int ���� uniform*/
inline void GlUniform(GLint location, GLint v0, GLint v1, GLint v2) {
	glUniform3i(location, v0, v1, v2);
}

/*��shader������ 4 int ���� uniform*/
inline void GlUniform(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) {
	glUniform4i(location, v0, v1, v2, v3);
}


/*��shader������ 1 float ���� uniform*/
inline void GlUniform(GLint location, GLfloat v0) {
	glUniform1f(location, v0);
}

/*��shader������ 2 float ���� uniform*/
inline void GlUniform(GLint location, GLfloat v0, GLfloat v1) {
	glUniform2f(location, v0, v1);

}

/*��shader������ 3 float ���� uniform*/
inline void GlUniform(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) {
	glUniform3f(location, v0, v1, v2);
}

/*��shader������ 4 float ���� uniform*/
inline void GlUniform(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) {
	glUniform4f(location, v0, v1, v2, v3);
}

/*��ȡshader������*/
inline void GlGetShaderiv(GLuint shader, GLenum pname, GLint* param) {
	glGetShaderiv(shader, pname, param);
}

/*��ȡ�����־*/
inline void GlGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog) {
	glGetShaderInfoLog(shader, bufSize, length, infoLog);
}


/*ɾ��shader*/
inline void GlDeleteShader(GLuint shader) {
	glDeleteShader(shader);
}












/**
* 
* 
* 
* 
* **************************** �������api
* 
* 
* 
* 
*/

/*��������*/
inline void GlGenTextures(GLsizei n, GLuint* textures) {
	glGenTextures(n, textures);
}

/*������*/
inline void GlBindTexture(GLenum target, GLuint texture) {
	glBindTexture(target, texture);
}

/*��������Ԫ*/
inline void GlActiveTexture(GLenum target) {
	glActiveTexture(target);
}

/*Ϊ��ǰ�󶨵�����������ɶ༶��Զ*/
inline void GlGenerateMipmap(GLenum target) {
	glGenerateMipmap(target);
}


/**������������
* @param target ����Ŀ�꣨GL_TEXTURE_1D | GL_TEXTURE_2D | GL_TEXTURE_3D��
* @param level ����༶��Զ�ļ���
* @param internalformat ����洢�ĸ�ʽ RGB RGBA
* @param width ���
* @param height �߶�
* @param format Դ���ݵĸ�ʽ
* @param type Դ���ݵĴ洢����
* @param Դͼ������
* @param isMipmap �Ƿ����ɶ༶��Զ���� Ĭ��Ϊ��
*/
inline void GlTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels, bool isMipmap = true) {
	glTexImage2D(target, level, internalformat, width, height, 0, format, type, pixels);
	if (isMipmap) {
		GlGenerateMipmap(target);
	}
}

/*����������� float*/
inline void GlTexParameterf(GLenum target, GLenum pname, GLfloat param) {
	glTexParameterf(target, pname, param);
}

/*����������� float[]*/
inline void GlTexParameterfv(GLenum target, GLenum pname, GLfloat* param) {
	glTexParameterfv(target, pname, param);
}

/*����������� int */
inline void GlTexParameteri(GLenum target, GLenum pname, GLint param) {
	glTexParameteri(target, pname, param);
}

/*����������� int[]*/
inline void GlTexParameteriv(GLenum target, GLenum pname, GLint* param) {
	glTexParameteriv(target, pname, param);
}



#endif // !__OPENGL_MACROS__