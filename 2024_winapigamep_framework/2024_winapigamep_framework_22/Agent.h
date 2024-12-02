#pragma once
#include "Object.h"
class Camera;
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
public:
	bool isRolling;
	bool canRolling;
	bool isHit;
	bool canHit;
	bool isRun;
	Vec2 prevVec = { 0, 0 };

private:
	bool isRight;
	Vec2 rollingDir;
	Camera* cam;
};
