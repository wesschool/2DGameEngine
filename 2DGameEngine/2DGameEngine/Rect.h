#pragma once

#include "GameObject.h"

using namespace glm;

class VisitorOperation;

class Rect : public GameObject
{
public:
	Rect(vec2 pos, vec2 size, Texture2D sprite, vec3 color = vec3(1.0f), vec2 velocity = vec2(0.0f, 0.0f));
	~Rect();

	void accept(VisitorOperation *v);

	void setPosition(vec2 position);
	void setSize(vec2 size);
	void setRotation(GLfloat rotation);
	void setVelocity(vec2 velocity);
	void setColor(vec3 color);
	void setSolid(GLboolean solid);
	void setDynamic(GLboolean state);
	void setTexture(Texture2D sprite);

	vec2 getPosition();
	vec2 getSize();
	GLfloat getRotation();
	vec2 getVelocity();
	vec3 getColor();
	GLboolean isSolid();
	GLboolean isDynamic();
	Texture2D getTexture();
	
};