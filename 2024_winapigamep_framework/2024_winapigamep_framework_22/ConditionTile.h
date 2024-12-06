#pragma once
#include "TileObject.h"
class Condition;
class ConditionTile :
	public TileObject
{
	ConditionTile();
	~ConditionTile();
public:
	void Update() override;
	bool CheckCondiiton();
	void AddCondiiton(Condition* c);
	void ApplyEnable();
private:
	vector<Condition*> conditions;
	bool flag = false;
};

