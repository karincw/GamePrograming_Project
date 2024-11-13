#pragma once
#include "Object.h"
class BackGroundObject :
	public Object
{
public:
	BackGroundObject();
	~BackGroundObject();
public:
	void Update() override;
	void LateUpdate() override;
	void Render(HDC _hdc) override;
	void EnterCollision(Collider* _other) override;
	void StayCollision(Collider* _other) override;
	void ExitCollision(Collider* _other) override;
};

