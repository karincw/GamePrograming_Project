#include "pch.h"
#include "Explosion.h"
#include "Animator.h"

Explosion::Explosion()
{
	AddComponent<Animator>();
	Animator* animator = GetComponent<Animator>();
	animator->CreateTexture(L"Texture\\Explosion.bmp", L"Explosion_Sheet");
	animator->CreateAnimation(L"Explosion", Vec2(0, 0), Vec2(166, 166), Vec2(166, 0), 8, 0.05f);
	animator->PlayAnimation(L"Explosion", false);
}

Explosion::~Explosion()
{
}

void Explosion::Update()
{
}

void Explosion::Render(HDC _hdc)
{
	ComponentRender(_hdc);
}

void Explosion::EnterCollision(Collider* _other)
{
}

void Explosion::StayCollision(Collider* _other)
{
}

void Explosion::ExitCollision(Collider* _other)
{
}
