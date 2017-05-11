#include "PhysicsEngine.h"



PhysicsEngine::PhysicsEngine()
{
}


PhysicsEngine::~PhysicsEngine()
{
}

void PhysicsEngine::MoveObject()
{
	if (CurrentObject == nullptr)
		return;

	CurrentObject->setPosition(CurrentObject->getPosition() + CurrentObject->getVelocity());
}

void PhysicsEngine::CheckCollision(GameObject *o)
{
	if (!CurrentObject->isSolid() || !o->isSolid())
		return;
	
	bool xOverlap = false;
	bool yOverlap = false;
	
	if ((CurrentObject->getPosition().x + CurrentObject->getSize().x >= o->getPosition().x) &&
		(o->getPosition().x + o->getSize().x >= CurrentObject->getPosition().x))
	{
		xOverlap = true;
	}

	if ((CurrentObject->getPosition().y + CurrentObject->getSize().y >= o->getPosition().y) &&
		(o->getPosition().y + o->getSize().y >= CurrentObject->getPosition().y))
	{
		yOverlap = true;
	}

	if (xOverlap == true && yOverlap == true)
	{
		vec2 velocity = CurrentObject->getVelocity();
		velocity.x *= -1;
		velocity.y *= -1;
		CurrentObject->setVelocity(velocity);
	}

}

void PhysicsEngine::SetObject(GameObject *o)
{
	CurrentObject = o;
}

void PhysicsEngine::ReleaseObject()
{
	CurrentObject = nullptr;
}