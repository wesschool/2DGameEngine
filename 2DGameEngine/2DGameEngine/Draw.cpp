#include "Draw.h"
#include "ResourceManager.h"

Draw::Draw()
{
	renderer = new SpriteRenderer(ResourceManager::GetShader("sprite"));
}


Draw::~Draw()
{
}


void Draw::visit(Rect *rect)
{
	renderer->DrawSprite(rect->getTexture(), rect->getPosition(), rect->getSize(), 
		rect->getRotation(), rect->getColor());
}