#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "Texture.h"
#include "SpriteRenderer.h"
#include "VisitorOperation.h"

using namespace glm;

class VisitorOperation;


class GameObject
{
public:
	GameObject() {};
	virtual ~GameObject() {};
	
	virtual void accept(VisitorOperation *v) = 0;

	virtual void setPosition(vec2 position) = 0;
	virtual void setSize(vec2 size) = 0;
	virtual void setRotation(GLfloat rotation) = 0;
	virtual void setVelocity(vec2 velocity) = 0;
	virtual void setColor(vec3 color) = 0;
	virtual void setSolid(GLboolean solid) = 0;
	virtual void setDynamic(GLboolean state) = 0;
	virtual void setTexture(Texture2D sprite) = 0;

	virtual vec2 getPosition() = 0;
	virtual vec2 getSize() = 0;
	virtual GLfloat getRotation() = 0;
	virtual vec2 getVelocity() = 0;
	virtual vec3 getColor() = 0;
	virtual GLboolean isSolid() = 0;
	virtual GLboolean isDynamic() = 0;
	virtual Texture2D getTexture() = 0;

protected:
	//object state
	glm::vec2   Position, Size, Velocity;
	glm::vec3   Color;
	GLfloat     Rotation;
	//solid = can be hit, dynamic = physics effect the object
	GLboolean   Solid, Dynamic;

	//texture used on object
	Texture2D   Sprite;
	
};