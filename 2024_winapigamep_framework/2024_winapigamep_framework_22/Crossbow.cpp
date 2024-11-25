#include "pch.h"
#include "Crossbow.h"
#include "SpriteRenderer.h"
#include "Transform.h"

Crossbow::Crossbow()
{
	GetTransform()->SetScale({ 64,64 });

	AddComponent<SpriteRenderer>();
	SpriteRenderer* sp = GetComponent<SpriteRenderer>();
	sp->SetOwner(this);

	sp->CreateTexture(L"Texture\\CrossBow.bmp", L"Crossbow");

}

Crossbow::~Crossbow()
{

}

void Crossbow::Update()
{

}

void Crossbow::Render(HDC _hdc)
{
	ComponentRender(_hdc);
}
