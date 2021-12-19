#pragma once
#include"EngineMacros.h"
#include"OpenGLMacros.h"
#include"CObject.h"
#include"Camera.h"
#include "Vec2.h"
#include<iostream>
class InputSystem : public CObject
{
private:
	InputSystem() {};
	InputSystem(InputSystem& input) {};
	void _initCursorEvent();
	static void _cursorPosCallback(GLFWwindow* window, double xpos, double ypos);
	GLFWwindow* _window = nullptr;
	Vec2 _lastCursorPos = Vec2(800.0f/2.0f,600.0f/2.0f);
	static void (*_releaseInstance)();
public:
	Camera* camera = nullptr;
	InputSystem(GLFWwindow* window):_window(window) {
	
		
	};
	void bindWindow(GLFWwindow* window) {
		_window = window;
		_initCursorEvent();
	}
	
	static InputSystem* GetInstance() {
		static InputSystem* _instance;
		if (_instance == nullptr) {
			_instance = new InputSystem();
			
		}
		return _instance;
	}

	static void ReleaseInstance() {
		// TODO 
	}

	virtual ~InputSystem() {};

	void ProcessInput();
	
};


