#include "pch.h"
#include "FallTileObject.h"
#include "SpriteRenderer.h"
#include "Transform.h"
#include "Collider.h"
#include "Animator.h"
#include "TimeManager.h"

void FallTile(Object* owner) {
	auto func = [](Object* obj) {
		FallTileObject* tile = dynamic_cast<FallTileObject*>(obj);
		tile->isEnter = false;
	};

	GET_SINGLE(TimeManager)->DelayRun(1.0f, func, owner);
}

FallTileObject::FallTileObject()
{
	GetTransform()->SetScale({ 256,256 });

	AddComponent<Animator>();
	Animator* animator = GetComponent<Animator>();
	animator->CreateTexture(L"Texture\\FallTile.bmp", L"fallTile_Sheet");
	animator->CreateAnimation(L"FallTile_Idle", Vec2(0, 0), Vec2(32, 32), Vec2(32, 0), 1, 0.1f);
	animator->CreateAnimation(L"FallTile_Warning", Vec2(0, 0), Vec2(32, 32), Vec2(32, 0), 2, 0.2f);
	
	animator->PlayAnimation(L"FallTile_Idle", false);

	AddComponent<Collider>();
	Collider* col = GetComponent<Collider>();
	col->SetSize({ 256,256 });
	SetName(L"Tile");
}

FallTileObject::~FallTileObject()
{
}

void FallTileObject::Update()
{
}

void FallTileObject::Render(HDC _hdc)
{
	ComponentRender(_hdc);
}

void FallTileObject::EnterCollision(Collider* _other)
{
	if (_other->GetOwner()->GetName() == L"Player" && !isEnter) {
		isEnter = true;
		Animator* ani = GetComponent<Animator>();
		ani->StopAnimation();
		ani->PlayAnimation(L"FallTile_Warning", true);
	}
}

void FallTileObject::StayCollision(Collider* _other)
{
}

void FallTileObject::ExitCollision(Collider* _other)
{
}
