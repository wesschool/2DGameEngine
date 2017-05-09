#include "ObjectEditor.h"

ObjectEditor::ObjectEditor(ObjectManager *gameObjects, GLboolean keys[], GLboolean mouse[])
	:GameObjects{ gameObjects }, Keys{ keys }, Mouse{ mouse }, MousePos {
	glm::vec2(0, 0)
}
{
	
}


ObjectEditor::~ObjectEditor()
{
}

void ObjectEditor::Update(glm::vec2 mouseCord)
{
	this->MousePos = mouseCord;
	
	if (this->Enabled)
	{
		if (*(Mouse[0] + GLFW_MOUSE_BUTTON_1))
			this->SetObjectToEdit();

		if (*(Mouse[0] + GLFW_MOUSE_BUTTON_2))
		{
			this->ScaleObjectX();
			this->ScaleObjectY();
			
		}
		this->OldMousePos = this->MousePos;
	

		if (*(Mouse[0] + GLFW_MOUSE_BUTTON_3))
			this->MoveObject();

		if (*(Keys[0] + GLFW_KEY_2))
			this->AddObject();
	}
	else
	{
		if(this->CurrentObject != nullptr)
			this->CurrentObject->Color = this->originalColor;
	}
	
	
}

void ObjectEditor::SetObjectToEdit()
{
	this->ClearObjectToEdit();
	
	for (int i = 0; i < this->GameObjects->Objects.size(); i++)
	{
		GameObject* tempObject = this->GameObjects->Objects[i];
		int xRange[2], yRange[2];
		xRange[0] = tempObject->Position.x;
		xRange[1] = tempObject->Position.x + tempObject->Size.x;

		yRange[0] = tempObject->Position.y;
		yRange[1] = tempObject->Position.y + tempObject->Size.y;

		if (MousePos.x > xRange[0] && MousePos.x < xRange[1])
		{
			if (MousePos.y > yRange[0] && MousePos.y < yRange[1])
			{
				this->originalColor = tempObject->Color;
				this->CurrentObject = tempObject;
				this->CurrentObject->Color = glm::vec3(1, 0, 0);

				return;
			}
		}

	}

	this->CurrentObject = nullptr;
}


void ObjectEditor::ClearObjectToEdit()
{
	if (this->CurrentObject != nullptr)
	{
		this->CurrentObject->Color = this->originalColor;
		this->CurrentObject = nullptr;
	}
}


void ObjectEditor::MoveObject()
{
	if (this->CurrentObject == nullptr)
		return;

	//static camera so we don't want objects to exist off screen
	if ((this->MousePos.x < 0 || MousePos.x > 1920) ||
		(this->MousePos.y < 0 || MousePos.y > 1080))
	{
		return;
	}

	CurrentObject->Center(this->MousePos);
}


void ObjectEditor::ScaleObjectX()
{
	this->CurrentObject->Size.x += (MousePos.x - OldMousePos.x) * .2;
}

void ObjectEditor::ScaleObjectY()
{
	this->CurrentObject->Size.y += (MousePos.y - OldMousePos.y) * .2;
}

void ObjectEditor::AddObject()
{
	this->GameObjects->add(new Rect(this->MousePos, glm::vec2(50, 50),
		ResourceManager::GetTexture("container"), glm::vec3(1, 1, 1), glm::vec2(0, 0)));
}