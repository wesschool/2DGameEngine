#include "WorldManager.h"



WorldManager::WorldManager(InputManager *input)
	:Input(input)
{
}


WorldManager::~WorldManager()
{
	this->CleanUp();
}

void WorldManager::Add(GameObject *o)
{
	GameObjects.push_back(o);
}

void WorldManager::Accept(VisitorOperation *v)
{
	for (auto i : GameObjects)
	{
		i->accept(v);
	}
}

void WorldManager::ApplyPhysics(PhysicsEngine *physics)
{
	//is there a way to do this through visitor?
	//visitor seems to simplistic to run different
	//tests multiple objects then change them
	
	for (auto i : GameObjects)
	{
		physics->SetObject(i);
		physics->MoveObject();
		physics->ReleaseObject();
	}
	for (int i = 0; i < GameObjects.size(); i++)
	{
		physics->SetObject(GameObjects[i]);

		for (int x = 0; x < GameObjects.size(); x++)
		{
			if (x == i)
				continue;

			physics->CheckCollision(GameObjects[x]);

		}

		physics->ReleaseObject();
	}
}

void WorldManager::Editor(ObjectEditor *editor)
{
	//should it really be the responsibility of the
	//worldmanager to determin the object to pass in
	//as the active object for the editor
	
	if (Input->IsClicked(GLFW_MOUSE_BUTTON_1))
	{
		//calculate what object it is hovered over
		//then pass that object to editor->setObjectToEdit()
	}
	if (Input->IsClicked(GLFW_MOUSE_BUTTON_3))
	{
		editor->MoveObject(Input->MousePosition());
	}
}

void WorldManager::CleanUp()
{
	for (auto i : GameObjects)
	{
		delete i;
	}
}