#pragma once
#include <glfw\glfw3.h>
#include <glm\glm.hpp>

using namespace glm;

class InputManager
{
public:
	InputManager(GLboolean keys[1024], GLboolean mouse[10], dvec2 *mousePos);
	~InputManager();

	bool IsPressed(int key);
	bool IsClicked(int button);
	dvec2 MousePosition();

private:
	GLboolean *Keys[1024];
	GLboolean *MouseButtons[10];
	dvec2 *MousePos;
};

