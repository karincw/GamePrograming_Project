#pragma once
#include "Object.h"
class Collider;
class Gold : public Object
{
public:
	Gold();
	~Gold();
public:
	void Update() override;
	void Render(HDC _hdc) override;
	void EnterCollision(Collider* _other) override;
};

