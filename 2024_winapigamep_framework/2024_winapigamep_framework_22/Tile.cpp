#include "pch.h"
#include "Tile.h"
#include "SpriteRenderer.h"
#include "Transform.h"

Tile::Tile()
{
	GetTransform()->SetScale({ 300,300 });
	AddComponent<SpriteRenderer>();
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
