#pragma once
#include "VisitorOperation.h"
#include "SpriteRenderer.h"
#include "Rect.h"
//type class rename better
class Draw :
	public VisitorOperation
{
public:
	Draw();
	~Draw();
	
	void visit(Rect *rect);

private:
	SpriteRenderer *renderer;
};

