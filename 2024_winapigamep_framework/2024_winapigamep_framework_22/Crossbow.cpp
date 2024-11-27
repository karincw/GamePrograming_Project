#include "pch.h"
#include "Crossbow.h"
#include "SpriteRenderer.h"

#include "Arrow.h"
#include "SceneManager.h"
#include "TimeManager.h"
#include "Scene.h"
#include "Collider.h"
#include "Action.h"


Crossbow::Crossbow(float time)
	:_timer(0)
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
	_timer += fDT;
	if (_timer >= 1)
	{
		Fire();
		_timer = 0;
	}
}

void Crossbow::Render(HDC _hdc)
{
	ComponentRender(_hdc);
}

void Crossbow::Fire()
{
	Arrow* arrow = new Arrow();
	arrow->GetTransform()->SetScale(Vec2(48, 32));
	arrow->GetComponent<SpriteRenderer>()->CreateTexture(L"Texture\\arrow.bmp", L"Arrow");
	arrow->GetComponent<Collider>()->SetSize(Vec2(48, 32));

	arrow->SetDir({ -1.f, 0.f });
	arrow->SetSpeed(250);
	arrow->SetName(L"Arrow");

	GET_SINGLE(SceneManager)->GetCurrentScene()->AddObject(arrow, LAYER::PROJECTILE);
}
