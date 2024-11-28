#pragma once
#include "Object.h"
class TrapTileObject :
    public Object
{
public:
	TrapTileObject();
	~TrapTileObject();
public:
	void Update() override;
	void Render(HDC _hdc) override;
public:
	void EnterCollision(Collider* _other)override;
	void StayCollision(Collider* _other)override;
	void ExitCollision(Collider* _other)override;
};

