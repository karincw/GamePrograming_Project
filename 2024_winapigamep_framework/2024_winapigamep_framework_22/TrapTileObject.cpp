#include "pch.h"
#include "TrapTileObject.h"
#include "SpriteRenderer.h"
#include "Transform.h"

TrapTileObject::TrapTileObject()
{
	GetTransform()->SetScale({ 256,256 });
	AddComponent<SpriteRenderer>();
	GetComponent<SpriteRenderer>()->CreateTexture(L"Texture\\TrapTile.bmp", L"traptile");
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
}

void TrapTileObject::StayCollision(Collider* _other)
{
}

void TrapTileObject::ExitCollision(Collider* _other)
{
}
