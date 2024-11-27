#pragma once
#include "Projectile.h"
class Arrow :
	public Projectile
{
public:
	Arrow();
	~Arrow();
public:
	void Update() override;
	void Render(HDC _hdc) override;
	void EnterCollision(Collider* _other) override;
	void StayCollision(Collider* _other) override;
	void ExitCollision(Collider* _other) override;
public:
};

