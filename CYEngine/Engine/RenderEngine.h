#pragma once
#define GLEW_STATIC
#include<GL/glew.h>
#include<GLFW/glfw3.h>
namespace Cherry {
	class RenderEngine
	{
	public:
		RenderEngine() :window(nullptr) {};
		virtual ~RenderEngine() {};
		bool createWindow(int width, int height, const char* title = "");
		void start();
	private:
		RenderEngine(RenderEngine& engine) :window(nullptr) {};
	private:
		GLFWwindow* window;
	};
};

