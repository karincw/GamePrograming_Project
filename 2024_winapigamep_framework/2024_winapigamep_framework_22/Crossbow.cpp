#include "pch.h"
#include "Crossbow.h"
#include "SpriteRenderer.h"
#include "Arrow.h"
#include "SceneManager.h"
#include "TimeManager.h"
#include "Scene.h"
#include "Collider.h"
#include "Action.h"


Crossbow::Crossbow(float time, wstring dir)
	:_timer(0)
{
	_dir = dir;
	_time = time;

	GetTransform()->SetScale({ 64,64 });

	AddComponent<SpriteRenderer>();
	SpriteRenderer* sp = GetComponent<SpriteRenderer>();
	sp->SetOwner(this);

	sp->CreateTexture(L"Texture\\CrossBow_" + dir + L".bmp", L"Crossbow" + dir);

}

Crossbow::~Crossbow()
{

}

void Crossbow::Update()
{
	_timer += fDT;
	if (_timer >= _time)
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
	Transform* trm = arrow->GetTransform();
	trm->SetScale(Vec2(48, 32));
	trm->SetPosition(GetTransform()->GetPosition());
	arrow->GetComponent<SpriteRenderer>()->CreateTexture(L"Texture\\arrow_" + _dir + L".bmp", L"Arrow" + _dir);
	arrow->GetComponent<Collider>()->SetSize(Vec2(48, 32));
	Vec2 dirVec = { 0.f, 0.f };

	if (_dir == L"Left")
	{
		dirVec = { -1.f, 0.f };
	}
	else if (_dir == L"Right")
	{
		dirVec = { 1.f, 0.f };
	}
	else if (_dir == L"Down")
	{
		dirVec = { 0.f, 1.f };
	}
	else if (_dir == L"Up")
	{
		dirVec = { 0.f, -1.f };
	}

	arrow->SetDir(dirVec);
	arrow->SetSpeed(750);
	arrow->SetName(L"Arrow");

	GET_SINGLE(SceneManager)->GetCurrentScene()->AddObject(arrow, LAYER::PROJECTILE);
}
