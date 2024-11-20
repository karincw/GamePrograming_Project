#pragma once
#include "Object.h"
class Agent :
	public Object
{
public:
	Agent();
	~Agent();
public:
	void Update() override;
	void Render(HDC _hdc) override;
public:
	void EnterCollision(Collider* _other)override;
	void StayCollision(Collider* _other)override;
	void ExitCollision(Collider* _other)override;
	Vec2 GetRollingDir() { return RollingDir; }
public:
	bool isRolling;

private:
	bool isRun;
	bool isRight;
	Vec2 RollingDir;
};
void PlayRun(Object* owner);
