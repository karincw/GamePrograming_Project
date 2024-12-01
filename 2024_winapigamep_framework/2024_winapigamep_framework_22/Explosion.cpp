#include "pch.h"
#include "Explosion.h"
#include "Animator.h"
#include "Collider.h"

Explosion::Explosion()
{
	GetTransform()->SetScale({ 1000,1000 });

	AddComponent<Animator>();
	Animator* animator = GetComponent<Animator>();
	animator->CreateTexture(L"Texture\\Explosion.bmp", L"Explosion_Sheet");
	animator->CreateAnimation(L"Explosion", Vec2(0, 0), Vec2(166, 166), Vec2(166, 0), 8, 0.1f);
	animator->PlayAnimation(L"Explosion", false);

	AddComponent<Collider>();
	Collider* col = GetComponent<Collider>();
	col->SetSize({ 166,166 });
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
