#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "Texture.h"
#include "SpriteRenderer.h"


class GameObject
{
public:
	GameObject() {};
	virtual ~GameObject() {};
	
	//object state
	glm::vec2   Position, Size, Velocity;
	glm::vec3   Color;
	GLfloat     Rotation;
	GLboolean   IsSolid;
	
	//render state
	Texture2D   Sprite;
	
	//center the object around specified coordinates
	virtual void Center(glm::vec2 centroid) = 0;

	//render object to screen
	virtual void Draw(SpriteRenderer *renderer) = 0;
	
};