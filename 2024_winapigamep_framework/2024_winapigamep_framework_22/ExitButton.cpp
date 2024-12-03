#include "pch.h"
#include "ExitButton.h"
#include "SpriteRenderer.h"
#include "Collider.h"

ExitButton::ExitButton()
{
	GetTransform()->SetScale({ 240, 80 });

	AddComponent<SpriteRenderer>();
	SpriteRenderer* spriteRenderer = GetComponent<SpriteRenderer>();
	spriteRenderer->CreateTexture(L"Texture\\Exit.bmp", L"exit");
	GetTransform()->SetPosition({ 250 , 500 });
}

ExitButton::~ExitButton()
{
}

void ExitButton::Update()
{
}

void ExitButton::Render(HDC _hdc)
{
	ComponentRender(_hdc);
}

void ExitButton::EnterCollision(Collider* _other)
{
}

void ExitButton::StayCollision(Collider* _other)
{
}

void ExitButton::ExitCollision(Collider* _other)
{
}
