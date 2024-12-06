#include "pch.h"
#include "Button.h"
#include "Animator.h"
#include "Collider.h"

Button::Button()
{
	GetTransform()->SetScale({ 256,256 });

	AddComponent<Animator>();
	Animator* animator = GetComponent<Animator>();
	animator->CreateTexture(L"Texture\\Button.bmp", L"button_sheet");
	animator->CreateAnimation(L"Button_Idle", Vec2(0, 0), Vec2(32, 32), Vec2(32, 0), 1, 0.1f);
	animator->CreateAnimation(L"Button_Press", Vec2(32, 0), Vec2(32, 32), Vec2(32, 0), 1, 0.1f);

	AddComponent<Collider>();
	Collider* collider = GetComponent<Collider>();
	collider->SetSize({ 256, 256 });

	SetName(L"Button");
	animator->PlayAnimation(L"Button_Idle", false);
}

Button::~Button()
{
}

void Button::Update()
{
}

void Button::Render(HDC _hdc)
{
	ComponentRender(_hdc);
}

void Button::EnterCollision(Collider* _other)
{
	if (_other->GetOwner()->GetName() == L"Player") {
		std::cout << "Press\n";
		Animator* animator = GetComponent<Animator>();
		animator->PlayAnimation(L"Button_Press", false);
	}
}

void Button::StayCollision(Collider* _other)
{
}

void Button::ExitCollision(Collider* _other)
{
}
