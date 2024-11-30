#include "pch.h"
#include "FallTileObject.h"
#include "SpriteRenderer.h"
#include "Transform.h"

FallTileObject::FallTileObject()
{
	GetTransform()->SetScale({ 256,256 });
	AddComponent<SpriteRenderer>();
	GetComponent<SpriteRenderer>()->CreateTexture(L"Texture\\FallTile.bmp", L"falltile");
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
}

void FallTileObject::StayCollision(Collider* _other)
{
}

void FallTileObject::ExitCollision(Collider* _other)
{
}
