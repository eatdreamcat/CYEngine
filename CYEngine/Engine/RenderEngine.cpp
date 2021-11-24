
#include "RenderEngine.h"

#include<iostream>
using namespace std;
namespace Cherry {
	bool RenderEngine::createWindow(int width, int height, const char* title) {
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLEW_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		window = glfwCreateWindow(width, height, title, NULL, NULL);
		if (window == nullptr) {
			cout << "window == nullptr" << endl;
			glfwTerminate();
			return false;
		}
		glfwMakeContextCurrent(window);
		glewExperimental = true;
		if (glewInit() != GLEW_OK) {
			cout << "glewInit() != GLEW_OK" << endl;
			glfwTerminate();
			return false;
		}

		glViewport(0, 0, width, height);

		return true;
	}


	void  RenderEngine::start() {


		while (!glfwWindowShouldClose(window))
		{
			glfwSwapBuffers(window);
			glfwPollEvents();
		}
		glfwTerminate();
	}


}
