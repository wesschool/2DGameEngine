#pragma once
#include <vector>
#include <glm\glm.hpp>
#include "SpriteRenderer.h"
#include "ResourceManager.h"
#include "VisitorOperation.h"
#include "GameObject.h"
#include "Rect.h"
#include "PhysicsEngine.h"
#include "ObjectEditor.h"


using namespace std;

class WorldManager
{
public:
	WorldManager();
	~WorldManager();
	
	void UpdateWorld();
	void Accept(VisitorOperation *v);

	void Add(GameObject *o);
	void Delete(GameObject *o);
	GameObject* GetObject(vec2 position);

private:
	PhysicsEngine physics;
	vector <GameObject*> GameObjects;
	
};