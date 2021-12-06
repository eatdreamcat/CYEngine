#pragma once
#define GLEW_STATIC
#include"CObject.h"
#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include"InputSystem.h"

	class RenderEngine:public CObject
	{
	public:
		RenderEngine() :window(nullptr), inputSys(new InputSystem()){};
		virtual ~RenderEngine() {};
		bool createWindow(int width, int height, const char* title = "");
		void start();
	private:
		RenderEngine(RenderEngine& engine) :window(nullptr), inputSys(nullptr) {};
	private:
		GLFWwindow* window;
		InputSystem* inputSys;
	};



