#pragma once

#include "GameObject.h"
#include <glfw\glfw3.h>


class ObjectEditor
{
public:
	ObjectEditor();
	~ObjectEditor();
	
	void SetObjectToEdit(GameObject *o);
	void ReleaseObjectToEdit();

	//features
	void MoveObject(vec2 position);
	//void ScaleObjectX();
	//void ScaleObjectY();
	

private:
	GameObject *CurrentObject;
	
	vec3 originalColor;
	vec2 OldMousePos;



};