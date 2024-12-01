#include "pch.h"
#include "TrapTileObject.h"
#include "SpriteRenderer.h"
#include "Transform.h"
#include "Collider.h"
#include "Animator.h"
#include "TimeManager.h"

void TrapTileObject::ExplosionTile(Object* owner) {
	auto func = [](Object* obj) {
		TrapTileObject* tile = dynamic_cast<TrapTileObject*>(obj);
		Animator* ani = tile->GetComponent<Animator>();
		ani->StopAnimation();
		ani->PlayAnimation(L"TrapTile_Idle", true);
		tile->isEnter = false;
		};

	GET_SINGLE(TimeManager)->DelayRun(1.0f, func, owner);
}

TrapTileObject::TrapTileObject()
{
	GetTransform()->SetScale({ 256,256 });

	AddComponent<Animator>();
	Animator* animator = GetComponent<Animator>();
	animator->CreateTexture(L"Texture\\TrapTile.bmp", L"TrapTile_Sheet");
	animator->CreateAnimation(L"TrapTile_Idle", Vec2(0, 0), Vec2(32, 32), Vec2(32, 0), 1, 0.1f);
	animator->CreateTexture(L"Texture\\BoomTrapTile.bmp", L"BoomTrapTile_Sheet");
	animator->CreateAnimation(L"TrapTile_Warning", Vec2(0, 0), Vec2(32, 32), Vec2(32, 0), 2, 0.2f);

	animator->PlayAnimation(L"TrapTile_Idle", false);

	AddComponent<Collider>();
	Collider* col = GetComponent<Collider>();
	col->SetSize({ 256,256 });
}

TrapTileObject::~TrapTileObject()
{
}

void TrapTileObject::Update()
{
}

void TrapTileObject::Render(HDC _hdc)
{
	ComponentRender(_hdc);
}

void TrapTileObject::EnterCollision(Collider* _other)
{
	if (_other->GetOwner()->GetName() == L"Player" && !isEnter) {
		isEnter = true;
		Animator* ani = GetComponent<Animator>();
		ani->StopAnimation();
		ani->PlayAnimation(L"TrapTile_Warning", true);
		ExplosionTile(this);
	}
}

void TrapTileObject::StayCollision(Collider* _other)
{
}

void TrapTileObject::ExitCollision(Collider* _other)
{
}
