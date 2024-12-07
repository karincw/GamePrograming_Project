#include "pch.h"
#include "StageText.h"
#include "SpriteRenderer.h"

StageText::StageText()
{
	GetTransform()->SetScale({ 262.5f ,120.0f });
	AddComponent<SpriteRenderer>();
	SpriteRenderer* spriteRenderer = GetComponent<SpriteRenderer>();
	spriteRenderer->CreateTexture(L"Texture\\StageText.bmp", L"StageText");
	GetTransform()->SetPosition({140, 70});
}

StageText::~StageText()
{
}

void StageText::Update()
{
}

void StageText::Render(HDC _hdc)
{
	ComponentRender(_hdc);
}
