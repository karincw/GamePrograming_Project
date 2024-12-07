#include "pch.h"
#include "TitleText.h"
#include "SpriteRenderer.h"

TitleText::TitleText()
{
	GetTransform()->SetScale({ 660,128 });
	AddComponent<SpriteRenderer>();
	SpriteRenderer* spriteRenderer = GetComponent<SpriteRenderer>();
	spriteRenderer->CreateTexture(L"Texture\\GameTitle.bmp", L"TitleText");
	GetTransform()->SetPosition({ 350 , 100});
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
