#include "pch.h"
#include "Arrow.h"
#include "Collider.h"

Arrow::Arrow()
{
}

Arrow::~Arrow()
{
}

void Arrow::Update()
{
	Projectile::Update();
}

void Arrow::Render(HDC _hdc)
{
	ComponentRender(_hdc);
}

void Arrow::EnterCollision(Collider* _other)
{
	Object* pOtherObj = _other->GetOwner();
	if (pOtherObj->GetName() == L"Player")
	{
		std::cout << "PlayerHit\n";
	}
}

void Arrow::StayCollision(Collider* _other)
{
}

void Arrow::ExitCollision(Collider* _other)
{
}
