#pragma once
#include "Object.h"
class StageButton :
    public Object
{
public:
	StageButton();
	~StageButton();
public:
	void SelectStageImage(wstring stageName);
	void Update() override;
	void Render(HDC _hdc) override;
};

