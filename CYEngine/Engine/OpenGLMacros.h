
#ifndef __OPENGL_MACROS__
#define __OPENGL_MACROS__


#define GLEW_STATIC
#include "EngineMacros.h"
#include<GL/glew.h>
#include<GLFW/glfw3.h>

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

/*��ⴰ���Ƿ񱻹ر�*/
inline int GlfwWindowShouldClose(GLFWwindow* window) {
	return glfwWindowShouldClose(window);
}

/*������������ɫ*/
inline void GlClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) {
	glClearColor(red, green, blue, alpha);
}

/*ָ�����λ*/
inline void GlClear(GLbitfield mask) {
	glClear(mask);
}

/*��ȡʱ�䣨�룩*/
inline double GlfwGetTime() {
	return glfwGetTime();
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

/*��shader������ 1 int ���� uniform*/
inline void GlUniform(GLint location, GLint v0) {
	glUniform1i(location, v0);
}

/*��shader������ 2 int ���� uniform*/
inline void GlUniform(GLint location, GLint v0, GLint v1) {
	glUniform2i(location, v0,v1);
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


/*ͨ�����������ķ�ʽ����
*  @param mode ����ģʽ
*  @param count  ��������
*  @param type  ������������
*  @param indices  ��������
*/
inline void GlDrawElements(GLenum mode, GLsizei count, GLenum type, const void* indices) {
	glDrawElements(mode, count, type, indices);
}

/* Swaps the front and back buffers of the specified window. 
*  ����ǰ�˻������ͺ�̨������������
*/
inline void GlfwSwapBuffers(GLFWwindow* window) {
	glfwSwapBuffers(window);
}


inline void GlfwPollEvents() {
	glfwPollEvents();
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


#endif // !__OPENGL_MACROS__