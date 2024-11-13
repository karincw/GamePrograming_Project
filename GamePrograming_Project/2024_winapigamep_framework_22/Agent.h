#pragma once
#include "Object.h"
class Agent :
	public Object
{
public:
	Agent();
	virtual ~Agent();
public:
	void Update() override;
	void LateUpdate() override;
	void Render(HDC _hdc) override;
public:
	void EnterCollision(Collider* _other) override;
	void StayCollision(Collider* _other) override;
	void ExitCollision(Collider* _other) override;
};

