#pragma once
#include "Object.h"

template<typename T>
class Action;

class Crossbow : public Object
{
public:
	Crossbow(float time);
	~Crossbow();
public:
	void Update() override;
	void Render(HDC _hdc) override;
	void Fire();
private:
	float _timer;
};

