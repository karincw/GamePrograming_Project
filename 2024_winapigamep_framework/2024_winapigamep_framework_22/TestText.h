#pragma once
#include "Object.h"
class TestText :
    public Object
{
public:
	TestText();
	~TestText();
public:
	void Update() override;
	void Render(HDC _hdc) override;
public:
	void EnterCollision(Collider* _other)override;
	void StayCollision(Collider* _other)override;
	void ExitCollision(Collider* _other)override;

public:
	void SetText(const std::wstring& titleText) {
		text = titleText;
	}
private:
	std::wstring text;
};

