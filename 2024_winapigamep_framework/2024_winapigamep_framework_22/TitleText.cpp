#include "pch.h"
#include "TitleText.h"
#include "SpriteRenderer.h"

TitleText::TitleText()
{
	GetTransform()->SetScale({ 500,250 });
	AddComponent<SpriteRenderer>();
	SpriteRenderer* spriteRenderer = GetComponent<SpriteRenderer>();
	spriteRenderer->CreateTexture(L"Texture\\TitleText.bmp", L"TitleText");
	GetTransform()->SetPosition({ 350 , SCREEN_HEIGHT / 4 });
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
