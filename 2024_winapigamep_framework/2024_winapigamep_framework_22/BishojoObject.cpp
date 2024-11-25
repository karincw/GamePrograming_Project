#include "pch.h"
#include "BishojoObject.h"
#include "SpriteRenderer.h"
#include "Transform.h"

BishojoObject::BishojoObject()
{
	GetTransform()->SetScale({ 500,700 });
	AddComponent<SpriteRenderer>();
}

BishojoObject::~BishojoObject()
{
}

void BishojoObject::Update()
{
}

void BishojoObject::Render(HDC _hdc)
{
	ComponentRender(_hdc);
}

void BishojoObject::EnterCollision(Collider* _other)
{
}

void BishojoObject::StayCollision(Collider* _other)
{
}

void BishojoObject::ExitCollision(Collider* _other)
{
}
