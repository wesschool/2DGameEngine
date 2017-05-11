#include "InputManager.h"



InputManager::InputManager(GLboolean keys[1024], GLboolean mouse[10], dvec2 *mousePos)
	:Keys{ keys }, MouseButtons{ mouse }, MousePos{ mousePos }
{
}


InputManager::~InputManager()
{
}

bool InputManager::IsPressed(int key)
{
	return Keys[key];
}

bool InputManager::IsClicked(int button)
{
	return MouseButtons[button];
}

dvec2 InputManager::MousePosition()
{
	return *MousePos;
}
