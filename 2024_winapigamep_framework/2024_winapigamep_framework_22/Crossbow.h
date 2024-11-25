#pragma once
#include "Object.h"
class Crossbow :
	public Object
{
public:
	Crossbow();
	virtual ~Crossbow();
public:
	void Update() override;
	void Render(HDC _hdc) override;
};

