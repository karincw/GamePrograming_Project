#include "pch.h"
#include "ConditionTile.h"
#include "Condition.h"

ConditionTile::ConditionTile()
	: conditions{}
{
	for (auto com : m_vecComponents)
	{
		com->SetEnable(false);
	}
}

ConditionTile::~ConditionTile()
{
	for (auto c : conditions)
	{
		delete c;
	}
	conditions.clear();
}

void ConditionTile::Update()
{
	if (CheckCondiiton() && !flag)
	{
		flag = true;
		ApplyEnable();
	}
}

bool ConditionTile::CheckCondiiton()
{
	bool state = true;
	for (auto c : conditions)
	{
		if (c->condition == false)
			state = false;
	}
	return state;
}

void ConditionTile::AddCondiiton(Condition* c)
{
	conditions.push_back(c);
}

void ConditionTile::ApplyEnable()
{
	for (auto com : m_vecComponents)
	{
		com->SetEnable(true);
	}
}
