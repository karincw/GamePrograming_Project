#include "pch.h"
#include "Tile.h"
#include "SpriteRenderer.h"
#include "Transform.h"

Tile::Tile()
{
	AddComponent<SpriteRenderer>();
	SpriteRenderer* sp = GetComponent<SpriteRenderer>();
	sp->CreateTexture(L"Texture\\bishojo.bmp", L"bishojo");

	GetTransform()->SetScale({ 200,200 });
}

Tile::~Tile()
{
}

void Tile::Update()
{
}

void Tile::Render(HDC _hdc)
{
	ComponentRender(_hdc);
}

void Tile::EnterCollision(Collider* _other)
{
}

void Tile::StayCollision(Collider* _other)
{
}

void Tile::ExitCollision(Collider* _other)
{
}
