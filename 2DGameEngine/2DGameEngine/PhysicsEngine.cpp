#include "PhysicsEngine.h"



PhysicsEngine::PhysicsEngine()
{
}


PhysicsEngine::~PhysicsEngine()
{
}

void PhysicsEngine::ApplyPhysics(vector <GameObject*>* GameObjects)
{
	for (auto i : *GameObjects)
	{
		MoveObject(i);
	}

	for (int i = 0; i < GameObjects->size(); i++)
	{
		for (int x = 0; x < GameObjects->size(); x++)
		{
			if (x == i)
				continue;

			CheckCollision((*GameObjects)[i], (*GameObjects)[x]);

		}
	}
}

void PhysicsEngine::MoveObject(GameObject* gameObject)
{
	vec2 position, velocity;
	position = gameObject->getPosition();
	velocity = gameObject->getVelocity();

	gameObject->setPosition(position + velocity);
}

void PhysicsEngine::CheckCollision(GameObject *object1, GameObject *object2)
{
	if (!object1->isSolid() || !object2->isSolid())
		return;
	
	bool xOverlap = false;
	bool yOverlap = false;
	
	if ((object1->getPosition().x + object1->getSize().x >= object2->getPosition().x) &&
		(object2->getPosition().x + object2->getSize().x >= object1->getPosition().x))
	{
		xOverlap = true;
	}

	if ((object1->getPosition().y + object1->getSize().y >= object2->getPosition().y) &&
		(object2->getPosition().y + object2->getSize().y >= object1->getPosition().y))
	{
		yOverlap = true;
	}

	if (xOverlap == true && yOverlap == true)
	{
		vec2 velocity = object1->getVelocity();
		velocity.x *= -1;
		velocity.y *= -1;
		object1->setVelocity(velocity);
	}

}