#include "pch.h"
#include "FallTileObject.h"
#include "SpriteRenderer.h"
#include "Transform.h"
#include "Collider.h"

FallTileObject::FallTileObject()
{
	GetTransform()->SetScale({ 256,256 });
	AddComponent<SpriteRenderer>();
	GetComponent<SpriteRenderer>()->CreateTexture(L"Texture\\FallTile.bmp", L"falltile");

	AddComponent<Collider>();
	Collider* col = GetComponent<Collider>();
	col->SetSize({ 256,256 });
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
