#include "ObjectEditor.h"

ObjectEditor::ObjectEditor()
{
}
	


ObjectEditor::~ObjectEditor()
{
}



void ObjectEditor::SetObjectToEdit(GameObject *o)
{
	if (CurrentObject != nullptr)
	{
		CurrentObject->setColor(CurrentObject->getOriginalColor());
	}

	if (o != nullptr)
	{
		CurrentObject = o;
		CurrentObject->setOriginalColor();
		CurrentObject->setColor(vec3(1, 0, 0));
	}
	else
	{
		CurrentObject = nullptr;
	}
}

void ObjectEditor::ReleaseObjectToEdit()
{
	CurrentObject = nullptr;
}


void ObjectEditor::MoveObject(vec2 position)
{
	if (CurrentObject != nullptr)
	{	
		vec2 pos = position;
		pos.x -= CurrentObject->getSize().x / 2;
		pos.y -= CurrentObject->getSize().y / 2;

		CurrentObject->setPosition(pos);
	}
}