#include "ObjectManager.h"

ObjectManager::ObjectManager()
{
	
}


ObjectManager::~ObjectManager()
{
	this->CleanUp();
}


void ObjectManager::add(GameObject* object)
{
	this->Objects.push_back(object);
}

void ObjectManager::draw(SpriteRenderer* Renderer)
{
	for (auto i : Objects)
	{
		i->Draw(Renderer);
	}
}

void ObjectManager::CleanUp()
{
	for (auto i : this->Objects)
	{
		delete i;
	}
}