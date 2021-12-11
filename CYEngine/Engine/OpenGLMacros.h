
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
* **************************** 初始化相关api
*
*
*
*
*/

/* 初始化GLFW 在调用所有glfw方法之前*/
inline int GlfwInit() {
	glewExperimental = true;
	return glfwInit();
}

/* 设置窗体的hint */
inline void GlfwWindowHint(int hint, int value) {
	glfwWindowHint(hint, value);
}

/* 创建一个窗口 */
inline GLFWwindow* GlfwCreateWindow(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share) {
	return glfwCreateWindow(width, height, title, monitor, share);
}

/* 停止所有窗口并释放所有相关资源 */
inline void GlfwTerminate() {
	glfwTerminate();
}

/* 设置窗体上下文，一个上下文只能同时在一个线程 */
inline void GlfwMakeContextCurrent(GLFWwindow* window) {
	glfwMakeContextCurrent(window);
}

/*判断初始化*/
inline GLenum GlewInit() {
	return glewInit();
}

/* 定义可绘制窗口区域 */
inline void GlViewport(GLint x, GLint y, GLsizei width, GLsizei height) {
	glViewport(x, y, width, height);
}

/*检测窗体是否被关闭*/
inline int GlfwWindowShouldClose(GLFWwindow* window) {
	return glfwWindowShouldClose(window);
}

/*获取时间（秒）*/
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
* **************************** 绘制相关api
*
*
*
*
*/


/* 开启功能 */
inline void GlEnable(GLenum cap) {
	glEnable(cap);
}

/* 剔除面 */
inline void GlCullFace(GLenum mode) {
	glCullFace(mode);
}

/* 多边形模式绘制 */
inline void GlPolygonMode(GLenum face, GLenum mode) {
	glPolygonMode(face, mode);
}

/*设置清屏的颜色*/
inline void GlClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) {
	glClearColor(red, green, blue, alpha);
}

/*指定清除位*/
inline void GlClear(GLbitfield mask) {
	glClear(mask);
}

/*通过顶点索引的方式绘制
*  @param mode 绘制模式
*  @param count  顶点数量
*  @param type  索引数据类型
*  @param indices  索引数组
*/
inline void GlDrawElements(GLenum mode, GLsizei count, GLenum type, const void* indices) {
	glDrawElements(mode, count, type, indices);
}

inline void GlDrawArrays(GLenum mode,GLint first, GLsizei count) {
	glDrawArrays(mode, first, count);
}

/* Swaps the front and back buffers of the specified window.
*  交换前端缓冲区和后台缓冲区的数据
*/
inline void GlfwSwapBuffers(GLFWwindow* window) {
	glfwSwapBuffers(window);
}











/**
*
*
*
*
* **************************** 顶点数据相关api
*
*
*
*
*/


/* 申请 VAO空间 */
inline void GlGenVertexArrays(GLsizei n, GLuint* arrays) {
	glGenVertexArrays(n, arrays);
}

/* 绑定当前要用的VAO id*/
inline void GlBindVertexArray(GLuint array) {
	glBindVertexArray(array);
}

/* 申请Buffer */
inline void GlGenBuffers(GLsizei n, GLuint* buffers) {
	glGenBuffers(n, buffers);
}

/* 绑定buffer目标*/
inline void GlBindBuffer(GLenum target, GLuint buffer) {
	glBindBuffer(target, buffer);
}

/* 给buffer传递数据*/
inline void GlBufferData(GLenum target, GLsizeiptr size, const void* data, GLenum usage) {
	glBufferData(target, size, data, usage);
}

/*** 定义VAO读取格式
*  @param index 通道ID （0-15）
*  @param size  每组数据大小
*  @param type  数据类型
*  @param normalized  是否标准化
*  @param stride  每组数据的步长
*  @param pointer  起始位置
*/
inline void GlVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer) {
	glVertexAttribPointer(index, size, type, normalized, stride, pointer);
}

/*激活VAO通道*/
inline void GlEnableVertexAttribArray(GLuint index) {
	glEnableVertexAttribArray(index);
}











/**
*
*
*
*
* **************************** 着色器相关api
*
*
*
*
*/


/*创建shader*/
inline GLuint GlCreateShader(GLenum type) {
	return glCreateShader(type);
}

/*绑定shader源代码*/
inline void GlShaderSource(GLuint shader, GLsizei count, const GLchar* const* string, const GLint* length) {
	glShaderSource(shader, count, string, length);
}

/*编译shader代码*/
inline void GlCompileShader(GLuint shader) {
	glCompileShader(shader);
}

/*创建一个shader程序*/
inline GLuint GlCreateProgram() {
	return glCreateProgram();
}

/*绑定shader到shader程序上*/
inline void GlAttachShader(GLuint program, GLuint shader) {
	glAttachShader(program, shader);
}

/*链接shader程序*/
inline void GlLinkProgram(GLuint program) {
	glLinkProgram(program);
}




/*获取uniform变量的位置*/
inline GLint GlGetUniformLocation(GLuint program, const GLchar* name) {
	return glGetUniformLocation(program, name);
}

/*指定当前要用的shader程序*/
inline void GlUseProgram(GLuint program) {
	glUseProgram(program);
}

/*给shader程序传送 n float 数组 uniform*/
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

/*给shader程序传送 n int 数组 uniform*/
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

/*给shader程序传送 4x4 矩阵*/
inline void  GlUniformMatrix4v(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) {
	glUniformMatrix4fv(location, count, transpose, value);
}



/*给shader程序传送 1 int 分量 uniform*/
inline void GlUniform(GLint location, GLint v0) {
	glUniform1i(location, v0);
}

/*给shader程序传送 2 int 分量 uniform*/
inline void GlUniform(GLint location, GLint v0, GLint v1) {
	glUniform2i(location, v0, v1);
}

/*给shader程序传送 3 int 分量 uniform*/
inline void GlUniform(GLint location, GLint v0, GLint v1, GLint v2) {
	glUniform3i(location, v0, v1, v2);
}

/*给shader程序传送 4 int 分量 uniform*/
inline void GlUniform(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) {
	glUniform4i(location, v0, v1, v2, v3);
}


/*给shader程序传送 1 float 分量 uniform*/
inline void GlUniform(GLint location, GLfloat v0) {
	glUniform1f(location, v0);
}

/*给shader程序传送 2 float 分量 uniform*/
inline void GlUniform(GLint location, GLfloat v0, GLfloat v1) {
	glUniform2f(location, v0, v1);

}

/*给shader程序传送 3 float 分量 uniform*/
inline void GlUniform(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) {
	glUniform3f(location, v0, v1, v2);
}

/*给shader程序传送 4 float 分量 uniform*/
inline void GlUniform(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) {
	glUniform4f(location, v0, v1, v2, v3);
}

/*获取shader编译结果*/
inline void GlGetShaderiv(GLuint shader, GLenum pname, GLint* param) {
	glGetShaderiv(shader, pname, param);
}

/*获取结果日志*/
inline void GlGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog) {
	glGetShaderInfoLog(shader, bufSize, length, infoLog);
}


/*删除shader*/
inline void GlDeleteShader(GLuint shader) {
	glDeleteShader(shader);
}












/**
* 
* 
* 
* 
* **************************** 纹理相关api
* 
* 
* 
* 
*/

/*生成纹理*/
inline void GlGenTextures(GLsizei n, GLuint* textures) {
	glGenTextures(n, textures);
}

/*绑定纹理*/
inline void GlBindTexture(GLenum target, GLuint texture) {
	glBindTexture(target, texture);
}

/*激活纹理单元*/
inline void GlActiveTexture(GLenum target) {
	glActiveTexture(target);
}

/*为当前绑定的纹理对象生成多级渐远*/
inline void GlGenerateMipmap(GLenum target) {
	glGenerateMipmap(target);
}


/**传入纹理数据
* @param target 纹理目标（GL_TEXTURE_1D | GL_TEXTURE_2D | GL_TEXTURE_3D）
* @param level 纹理多级渐远的级别
* @param internalformat 纹理存储的格式 RGB RGBA
* @param width 宽度
* @param height 高度
* @param format 源数据的格式
* @param type 源数据的存储类型
* @param 源图像数据
* @param isMipmap 是否生成多级渐远纹理 默认为是
*/
inline void GlTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels, bool isMipmap = true) {
	glTexImage2D(target, level, internalformat, width, height, 0, format, type, pixels);
	if (isMipmap) {
		GlGenerateMipmap(target);
	}
}

/*设置纹理参数 float*/
inline void GlTexParameterf(GLenum target, GLenum pname, GLfloat param) {
	glTexParameterf(target, pname, param);
}

/*设置纹理参数 float[]*/
inline void GlTexParameterfv(GLenum target, GLenum pname, GLfloat* param) {
	glTexParameterfv(target, pname, param);
}

/*设置纹理参数 int */
inline void GlTexParameteri(GLenum target, GLenum pname, GLint param) {
	glTexParameteri(target, pname, param);
}

/*设置纹理参数 int[]*/
inline void GlTexParameteriv(GLenum target, GLenum pname, GLint* param) {
	glTexParameteriv(target, pname, param);
}



#endif // !__OPENGL_MACROS__