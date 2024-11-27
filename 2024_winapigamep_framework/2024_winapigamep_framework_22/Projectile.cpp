#include "pch.h"
#include "Projectile.h"
#include "TimeManager.h"
#include "Texture.h"
#include "ResourceManager.h"
#include "Collider.h"
#include "EventManager.h"
#include "SpriteRenderer.h"

Projectile::Projectile()
	: m_angle(0.f)
	, m_speed(0.f)
	, m_vDir(1.f, 1.f)
{
	AddComponent<SpriteRenderer>();
	AddComponent<Collider>();
}

Projectile::~Projectile()
{
}

void Projectile::Update()
{
	Vec2 vPos = { 0,0 };

	vPos.x = m_vDir.x * m_speed * fDT;
	vPos.y = m_vDir.y * m_speed * fDT;
	GetTransform()->Translate(vPos);

	Vec2 vSize = GetTransform()->GetScale();
	if (vPos.y < -vSize.y)
	{
		GET_SINGLE(EventManager)->DeleteObject(this);
	}
}

void Projectile::Render(HDC _hdc)
{
	ComponentRender(_hdc);
}
