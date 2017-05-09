#pragma once

#include <vector>
#include <glm\glm.hpp>
#include "SpriteRenderer.h"
#include "ResourceManager.h"
#include "GameObject.h"

class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();
	//currently needs to be accessed through pointer to ObjectManager class
	std::vector <GameObject*> Objects;
	
	//add object to the manager
	void add(GameObject* object);
	
	//draw every object to screen
	void draw(SpriteRenderer* Renderer);


private:	
	SpriteRenderer* Renderer;

	//delete all objects stored in manager
	void CleanUp();

};