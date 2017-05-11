#include "Rect.h"

Rect::Rect(vec2 pos, vec2 size, Texture2D sprite, vec3 color, vec2 velocity)
{
	setPosition(pos);
	setSize(size);
	setTexture(sprite);
	setColor(color);
	setVelocity(velocity);
	setRotation(0);
	setSolid(true);
	setDynamic(false);
}
Rect::~Rect()
{

}

void Rect::accept(VisitorOperation *v)
{
	v->visit(this);
}

void Rect::setPosition(vec2 position)
{
	Position = position;
}

void Rect::setSize(vec2 size)
{
	Size = size;
}

void Rect::setRotation(GLfloat rotation)
{
	Rotation = rotation;
}

void Rect::setVelocity(vec2 velocity)
{
	Velocity = velocity;
}

void Rect::setColor(vec3 color)
{
	Color = color;
}

void Rect::setSolid(GLboolean solid)
{
	Solid = solid;
}

void Rect::setDynamic(GLboolean state)
{
	Dynamic = state;
}

void Rect::setTexture(Texture2D sprite)
{
	Sprite = sprite;
}

vec2 Rect::getPosition()
{
	return Position;
}

vec2 Rect::getSize()
{
	return Size;
}

GLfloat Rect::getRotation()
{
	return Rotation;
}

vec2 Rect::getVelocity()
{
	return Velocity;
}

vec3 Rect::getColor()
{
	return Color;
}

GLboolean Rect::isSolid()
{
	return Solid;
}

GLboolean Rect::isDynamic()
{
	return Dynamic;
}

Texture2D Rect::getTexture()
{
	return Sprite;
}