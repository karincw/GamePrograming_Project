#include "pch.h"
#include "ConditionTile.h"
#include "Condition.h"

ConditionTile::ConditionTile()
{
	ApplyCondition();
}

ConditionTile::~ConditionTile()
{
}

void ConditionTile::Update()
{
	if (CheckCondiiton() && !flag)
	{
		flag = true;
		ApplyCondition();
	}
}

void ConditionTile::Render(HDC _hdc)
{
	TileObject::ComponentRender(_hdc);
}

void ConditionTile::ApplyCondition()
{
	for (auto com : m_vecComponents)
	{
		com->SetEnable(CheckCondiiton());
	}
}
