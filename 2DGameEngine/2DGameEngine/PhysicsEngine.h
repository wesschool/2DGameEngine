#pragma once
#include "Rect.h"
class PhysicsEngine
{
public:
	PhysicsEngine();
	~PhysicsEngine();

	void MoveObject();
	void CheckCollision(GameObject *o);
	void SetObject(GameObject *o);
	void ReleaseObject();
	

private:
	GameObject* CurrentObject;
};

