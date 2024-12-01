#include "pch.h"
#include "MagicTower.h"
#include "SpriteRenderer.h"
#include "Arrow.h"
#include "TimeManager.h"
#include "Collider.h"
#include "Action.h"
#include "SceneManager.h"
#include "Scene.h"


MagicTower::MagicTower(float time)
	:_timer(0)
{
	_time = time;

	GetTransform()->SetScale({ 64,64 });

	AddComponent<SpriteRenderer>();
	SpriteRenderer* sp = GetComponent<SpriteRenderer>();
	sp->SetOwner(this);

	sp->CreateTexture(L"Texture\\MagicTower.bmp", L"MagicTower");

}

MagicTower::~MagicTower()
{

}

void MagicTower::Update()
{
	_timer += fDT;
	if (_timer >= _time)
	{
		Fire();
		_timer = 0;
	}
}

void MagicTower::Render(HDC _hdc)
{
	ComponentRender(_hdc);
}

void MagicTower::Fire()
{
	Arrow* arrow = new Arrow();
	Transform* trm = arrow->GetTransform();
	trm->SetScale(Vec2(22, 22));
	trm->SetPosition(GetTransform()->GetPosition() + Vec2(0, -16));
	arrow->GetComponent<SpriteRenderer>()->CreateTexture(L"Texture\\Bullet.bmp", L"Bullet");
	arrow->GetComponent<Collider>()->SetSize(Vec2(32, 32));
	Vec2 dirVec = { 0.f, 0.f };

	Object* pPlayer = nullptr;
	auto players = GET_SINGLE(SceneManager)->GetCurrentScene()->GetLayerObjects(LAYER::PLAYER);
	for (auto p : players)
	{
		if (p->GetName() == L"Player")
			pPlayer = p;
	}
	dirVec = pPlayer->GetTransform()->GetPosition() - GetTransform()->GetPosition();

	arrow->SetDir(dirVec);
	arrow->SetSpeed(750);
	arrow->SetName(L"Arrow");

	GET_SINGLE(SceneManager)->GetCurrentScene()->AddObject(arrow, LAYER::PROJECTILE);
}
