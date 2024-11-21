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
	Vec2 GetRollingDir() { return RollingDir; }
public:
	bool isRolling;
	bool canRolling;

private:
	bool isRun;
	bool isRight;
	Vec2 RollingDir;
	Camera* cam;
};
void PlayRun(Object* owner);
