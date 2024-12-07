#include "pch.h"
#include "Gold.h"
#include "SpriteRenderer.h"
#include "CircleCollider.h"

Gold::Gold()
{
	GetTransform()->SetScale({ 32,32 });

	AddComponent<SpriteRenderer>();
	SpriteRenderer* sp = GetComponent<SpriteRenderer>();
	//sp->CreateTexture(L"", L"");

	AddComponent<CircleCollider>();
	CircleCollider* cc = GetComponent<CircleCollider>();
	cc->SetRadius(48);

}

Gold::~Gold()
{
}

void Gold::Update()
{

}

void Gold::Render(HDC _hdc)
{
	ComponentRender(_hdc);
}

void Gold::EnterCollision(Collider* _other)
{
	if (_other->GetOwner()->GetName() == L"Player")
	{
		std::cout << "°ÔÀÓ ³¡";
	}
}
