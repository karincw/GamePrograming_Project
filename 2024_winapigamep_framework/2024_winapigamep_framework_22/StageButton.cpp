#include "pch.h"
#include "StageButton.h"
#include "Animator.h"

StageButton::StageButton()
{
	GetTransform()->SetScale({ 128, 128 });
	AddComponent<Animator>();
	Animator* anim = GetComponent<Animator>();
	anim->CreateTexture(L"Texture\\Stage.bmp", L"stage");
	anim->CreateAnimation(L"Stage1", Vec2(0, 0), Vec2(31, 31), Vec2(31, 0), 1, 0.1f);
	anim->CreateAnimation(L"Stage2", Vec2(31, 0), Vec2(31, 31), Vec2(31, 0), 1, 0.1f);
}

StageButton::~StageButton()
{
}

void StageButton::SelectStageImage(wstring stageName)
{
	Animator* anim = GetComponent<Animator>();
	anim->PlayAnimation(stageName, false);
}

void StageButton::Update()
{
}

void StageButton::Render(HDC _hdc)
{
	ComponentRender(_hdc);
}
