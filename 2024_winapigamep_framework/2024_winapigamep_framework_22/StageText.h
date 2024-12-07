#pragma once
#include "Object.h"
class StageText :
    public Object
{
public:
	StageText();
	~StageText();
public:
	void Update() override;
	void Render(HDC _hdc) override;
};

