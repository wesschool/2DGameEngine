#pragma once
#include "Rect.h"
#include <vector>

using namespace std;

class PhysicsEngine
{
public:
	PhysicsEngine();
	~PhysicsEngine();
	void ApplyPhysics(vector <GameObject*>* GameObjects, GLfloat dt);

private:
	void MoveObject(GameObject* gameObject, GLfloat dt);
	void CheckCollision(GameObject *object1, GameObject *object2);
};

