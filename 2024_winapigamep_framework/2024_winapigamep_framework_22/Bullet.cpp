#include "pch.h"
#include "Bullet.h"
#include "Collider.h"

Bullet::Bullet()
{
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
	Projectile::Update();
}

void Bullet::Render(HDC _hdc)
{
	ComponentRender(_hdc);
}

void Bullet::EnterCollision(Collider* _other)
{

}

void Bullet::StayCollision(Collider* _other)
{
}

void Bullet::ExitCollision(Collider* _other)
{
}
