#include "pch.h"
#include "Condition.h"
#include "Conditionable.h"

Conditionable::Conditionable()
	: conditions{}
{
}

Conditionable::~Conditionable()
{
	for (auto c : conditions)
	{
		delete c;
	}
	conditions.clear();
}


bool Conditionable::CheckCondiiton()
{
	bool state = true;
	for (auto c : conditions)
	{
		if (c->condition == false)
			state = false;
	}
	return state;
}

void Conditionable::AddCondiiton(Condition* c)
{
	conditions.push_back(c);
}
