#pragma once
#include "Rect.h"
#include <vector>

using namespace std;

class PhysicsEngine
{
public:
	PhysicsEngine();
	~PhysicsEngine();
	void ApplyPhysics(vector <GameObject*>* GameObjects);

private:
	void MoveObject(GameObject* gameObject);
	void CheckCollision(GameObject *object1, GameObject *object2);
};

