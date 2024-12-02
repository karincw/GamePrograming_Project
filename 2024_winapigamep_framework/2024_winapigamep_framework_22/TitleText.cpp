#include "pch.h"
#include "TitleText.h"
#include "SpriteRenderer.h"

TitleText::TitleText()
{
	GetTransform()->SetScale({ 600,300 });
	AddComponent<SpriteRenderer>();
	SpriteRenderer* spriteRenderer = GetComponent<SpriteRenderer>();
	spriteRenderer->CreateTexture(L"Texture\\TitleText.bmp", L"TitleText");
}

TitleText::~TitleText()
{
}

void TitleText::Update()
{
}

void TitleText::Render(HDC _hdc)
{
	ComponentRender(_hdc);
}

void TitleText::EnterCollision(Collider* _other)
{
}

void TitleText::StayCollision(Collider* _other)
{
}

void TitleText::ExitCollision(Collider* _other)
{
}
