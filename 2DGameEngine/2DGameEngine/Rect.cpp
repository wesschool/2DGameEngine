#include "Rect.h"



Rect::Rect()
{
	Position = { 0, 0 };
	Size = { 1,1 };
	Velocity = { 0.0f, 0.0f };
	Color = { 1.0f, 1.0f, 1.0f };
	Rotation = 0.0f;
	IsSolid = false;
}


Rect::Rect(glm::vec2 pos, glm::vec2 size, Texture2D sprite, glm::vec3 color, glm::vec2 velocity)
{
	Position = pos;
	Size = size;
	Sprite = sprite;
	Velocity = velocity;
	Color = color;
	Rotation = 0.0f;
	IsSolid = false;
}


Rect::~Rect()
{
}


void Rect::Draw(SpriteRenderer *renderer)
{
	renderer->DrawSprite(this->Sprite, this->Position, this->Size, this->Rotation, this->Color);
}


void Rect::Center(glm::vec2 centroid)
{
	Position.x = centroid.x - (Size.x / 2);
	Position.y = centroid.y - (Size.y / 2);
}