#pragma once
#include "Object.h"

#define maxSpeed 400
#define AccelationSpeed 2
#define DecelationSpeed -0.5f;
#define MaxAccelableDir 0.025f

class FollowTrap : public Object
{
public:
	FollowTrap();
	~FollowTrap();
public:
	void Update() override;
	void Render(HDC _hdc) override;
public:
	void Accel();
	void Accelation();
	void Deceleration();
	Object* currentTarget;
private:
	float speed;
	Vec2 moveDir;
};

