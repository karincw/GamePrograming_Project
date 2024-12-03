#pragma once
#include "Object.h"
class Lazer;
class StarLazer : public Object
{
public:
	StarLazer(Vec2 position);
	virtual ~StarLazer();
public:
	virtual void Update() override;
	virtual void Render(HDC _hdc) override;
public:
	void EnterCollision(Collider* _other)override;
	void StayCollision(Collider* _other)override;
	void ExitCollision(Collider* _other)override;

private:
	Lazer* lazers[4];
};

