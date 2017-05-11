#pragma once
class Rect;

class VisitorOperation
{
public:
	VisitorOperation() {};
	~VisitorOperation() {};

	virtual void visit(Rect *rect) = 0;
};

