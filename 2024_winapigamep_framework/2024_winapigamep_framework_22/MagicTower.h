#pragma once
#include "Object.h"

template<typename T>
class Action;

class MagicTower : public Object
{
public:
	MagicTower(float time, wstring dir);
	~MagicTower();
public:
	void Update() override;
	void Render(HDC _hdc) override;
	void Fire();
private:
	float _timer;
	float _time;
	wstring _dir;
};

