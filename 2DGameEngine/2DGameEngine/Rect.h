#pragma once

#include "GameObject.h"

class Rect : public GameObject
{
public:
	Rect();
	Rect(glm::vec2 pos, glm::vec2 size, Texture2D sprite, glm::vec3 color = glm::vec3(1.0f), glm::vec2 velocity = glm::vec2(0.0f, 0.0f));
	~Rect();

	virtual void Center(glm::vec2 centroid);
	virtual void Draw(SpriteRenderer *renderer);
	
};