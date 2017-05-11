#include "WorldManager.h"



WorldManager::WorldManager()
{
}


WorldManager::~WorldManager()
{
	for (auto i : GameObjects)
	{
		delete i;
	}
}

void WorldManager::UpdateWorld(GLfloat dt)
{
	physics.ApplyPhysics(&GameObjects, dt);
}

void WorldManager::Accept(VisitorOperation *v)
{
	for (auto i : GameObjects)
	{
		i->accept(v);
	}
}

void WorldManager::Add(GameObject *o)
{
	GameObjects.push_back(o);
}

void WorldManager::Delete(GameObject *o)
{
	for (auto i : GameObjects)
	{
		if (i == o)
		{
			delete i;
			return;
		}
	}
}

GameObject* WorldManager::GetObject(vec2 position)
{
	for (auto i : GameObjects)
	{
		float xRange[2], yRange[2];
		xRange[0] = i->getPosition().x;
		xRange[1] = i->getPosition().x +i->getSize().x;

		yRange[0] = i->getPosition().y;
		yRange[1] = i->getPosition().y + i->getSize().y;

		if (position.x >= xRange[0] && position.x <= xRange[1])
		{
			if (position.y >= yRange[0] && position.y <= yRange[1])
			{
				return i;
			}
		}
	}

	return nullptr;
}