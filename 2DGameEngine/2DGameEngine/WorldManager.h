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
#include "InputManager.h"

using namespace std;

class WorldManager
{
public:
	WorldManager(InputManager *input);
	~WorldManager();
	
	
	void Add(GameObject *o);
	void Accept(VisitorOperation *v);
	void ApplyPhysics(PhysicsEngine *physics);
	void Editor(ObjectEditor *editor);

private:
	InputManager *Input;

	vector <GameObject*> GameObjects;
	


	void CleanUp();
};

