#pragma once
#define GLEW_STATIC

#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include"CObject.h"
#include"InputSystem.h"
#include<iostream>
#include "OpenGLMacros.h"
#include"Camera.h"
#include "Material.h"
#include "Pass.h"


	class RenderEngine:public CObject
	{
	public:
		RenderEngine() :window(nullptr){};
		virtual ~RenderEngine() {};
		bool createWindow(int width, int height, const char* title = "");
		void start();
	private:
		RenderEngine(RenderEngine& engine) :window(nullptr) {};
	private:
		GLFWwindow* window;
		CVector<Pass> m_passQueue;
	};



