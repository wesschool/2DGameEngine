#include "ObjectEditor.h"

ObjectEditor::ObjectEditor()
{
}
	


ObjectEditor::~ObjectEditor()
{
}



void ObjectEditor::SetObjectToEdit(GameObject *o)
{
	CurrentObject = o;
}

void ObjectEditor::ReleaseObjectToEdit()
{
	CurrentObject = nullptr;
}

void ObjectEditor::setOriginalColor(vec3 color)
{
	originalColor = color;
}

vec3 ObjectEditor::getOriginalColor()
{
	return originalColor;
}

void ObjectEditor::MoveObject(vec2 position)
{
	if(CurrentObject != nullptr)
		CurrentObject->setPosition(position);
}