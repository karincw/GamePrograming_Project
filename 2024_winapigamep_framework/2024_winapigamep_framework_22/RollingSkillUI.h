#pragma once
#include "Object.h"


class RollingSkillUI :
    public Object
{
public:
	RollingSkillUI();
	~RollingSkillUI();
public:
	void Update() override;
	void Render(HDC _hdc) override;
	void MoveUI(Vec2 vec);
public:
	void EnterCollision(Collider* _other)override;
	void StayCollision(Collider* _other)override;
	void ExitCollision(Collider* _other)override;
};

