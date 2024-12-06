#include "pch.h"
#include "Explosion.h"
#include "Animator.h"
#include "Animation.h"
#include "Collider.h"
#include "Action.h"
#include "EventManager.h"

void EndExplosion(Object* owner)
{
	Explosion* ex = dynamic_cast<Explosion*>(owner);
	GET_SINGLE(EventManager)->DeleteObject(owner);
}

Explosion::Explosion()
{
	GetTransform()->SetScale({ 400,400 });

	AddComponent<Animator>();
	Animator* animator = GetComponent<Animator>();
	animator->CreateTexture(L"Texture\\Explosion.bmp", L"Explosion_Sheet");

	animator->CreateAnimation(L"Explosion", Vec2(0, 0), Vec2(128, 144), Vec2(128, 0), 11, 0.07f);
	animator->PlayAnimation(L"Explosion", false);
	animator->FindAnimation(L"Explosion")->animationEndEvent->Insert(EndExplosion);
	AddComponent<Collider>();
	Collider* col = GetComponent<Collider>();
	col->SetOffSetPos(Vec2(-30, -20));
	col->SetSize({ 256, 256});

	SetName(L"Explosion");
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
