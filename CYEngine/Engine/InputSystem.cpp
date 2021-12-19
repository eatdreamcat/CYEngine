#include "InputSystem.h"
#include<functional>
void InputSystem::_initCursorEvent()
{
	GlfwSetCursorPosCallback(_window, &InputSystem::_cursorPosCallback);
}

bool isFirstEnter = true;
 void InputSystem::_cursorPosCallback(GLFWwindow* window, double xpos, double ypos)
{
	 auto inputSys = GetInstance();
	 if (isFirstEnter) {
		 inputSys->_lastCursorPos.x = (float)xpos;
		 inputSys->_lastCursorPos.y = (float)ypos;
		 isFirstEnter = false;
	 }
	 Vec2 delta(xpos-inputSys->_lastCursorPos.x, ypos-inputSys->_lastCursorPos.y);
	 inputSys->_lastCursorPos.x = (float)xpos;
	 inputSys->_lastCursorPos.y = (float)ypos;
	 inputSys->camera->processMouseInput(delta.x, delta.y);
}

void InputSystem::ProcessInput() {
	
	if (glfwGetKey(_window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(_window, true);
	}
	else
	{
		if (glfwGetKey(_window, GLFW_KEY_W) == GLFW_PRESS) {
			GetInstance()->camera->move(0.0f, 0.0f, 1.0f);
		}

		if (glfwGetKey(_window, GLFW_KEY_S) == GLFW_PRESS) {
			GetInstance()->camera->move(0.0f, 0.0f, -1.0f);
		}

		if (glfwGetKey(_window, GLFW_KEY_A) == GLFW_PRESS) {
			GetInstance()->camera->move(-1.0f, 0.0f, 0.0f);
		}

		if (glfwGetKey(_window, GLFW_KEY_D) == GLFW_PRESS) {
			GetInstance()->camera->move(1.0f, 0.0f, 0.0f);
		}

		if (glfwGetKey(_window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
			GetInstance()->camera->move(0.0f, 1.0f, 0.0f);
		}

		if (glfwGetKey(_window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS) {
			GetInstance()->camera->move(0.0f, -1.0f, 0.0f);
		}
	}
};
