#pragma once
#include "Object.h"
class StarLazer : public Object
{
public:
	StarLazer();
	virtual ~StarLazer();
public:
	virtual void Update() abstract;
	virtual void Render(HDC _hdc) abstract;
public:
	void EnterCollision(Collider* _other)override;
	void StayCollision(Collider* _other)override;
	void ExitCollision(Collider* _other)override;
};

