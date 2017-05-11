#pragma once
class GameObject;

class VisitorOperation
{
public:
	VisitorOperation() {};
	~VisitorOperation() {};

	virtual void visit(GameObject *gameObject) = 0;
};

