#pragma once
#include"EngineMacros.h"
#include"CObject.h"
#include<GLFW/glfw3.h>
NS_CY_BEGIN
class InputSystem : public CObject
{
private:
	InputSystem(InputSystem& input) {};
public:
	InputSystem() {};
	virtual ~InputSystem() {};
	void ProcessInput(GLFWwindow* window);
};
NS_CY_END

