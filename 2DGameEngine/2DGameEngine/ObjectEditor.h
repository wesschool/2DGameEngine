#pragma once

#include "GameObject.h"
#include "Rect.h"
#include "ObjectManager.h"
#include <glfw\glfw3.h>

class ObjectEditor
{
public:
	ObjectEditor(ObjectManager *gameObjects, GLboolean keys[], GLboolean mouse[]);
	~ObjectEditor();
	bool Enabled{ false };
	void Update(glm::vec2 mouseCord);
	

private:
	//members needed for editor to function
	GLboolean *Keys[1024];
	GLboolean *Mouse[10];
	ObjectManager *GameObjects;
	glm::vec2 MousePos, OldMousePos;
	
	//current object to edit
	GameObject* CurrentObject = nullptr;
	void SetObjectToEdit();

	glm::vec3 originalColor;

	void ClearObjectToEdit();
	
	//features
	void AddObject();
	void MoveObject();
	void ScaleObjectX();
	void ScaleObjectY();
};