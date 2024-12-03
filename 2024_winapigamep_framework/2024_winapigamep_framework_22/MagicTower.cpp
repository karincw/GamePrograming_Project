#include "pch.h"
#include "MagicTower.h"
#include "SpriteRenderer.h"
#include "TimeManager.h"
#include "Collider.h"
#include "Action.h"
#include "SceneManager.h"
#include "Scene.h"
#include "Bullet.h"


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
	Bullet* bullet = new Bullet();
	Transform* trm = bullet->GetTransform();
	trm->SetScale(Vec2(22, 22));
	trm->SetPosition(GetTransform()->GetPosition() + Vec2(0, -16));
	bullet->GetComponent<SpriteRenderer>()->CreateTexture(L"Texture\\Bullet_Red.bmp", L"Bullet_Red");
	bullet->GetComponent<Collider>()->SetSize(Vec2(32, 32));
	Vec2 dirVec = { 0.f, 0.f };

	Object* pPlayer = nullptr;
	auto players = GET_SINGLE(SceneManager)->GetCurrentScene()->GetLayerObjects(LAYER::PLAYER);
	for (auto p : players)
	{
		if (p->GetName() == L"Player")
			pPlayer = p;
	}
	dirVec = pPlayer->GetTransform()->GetPosition() + Vec2(0, -16) - GetTransform()->GetPosition();

	bullet->SetDir(dirVec);
	bullet->SetSpeed(750);
	bullet->SetName(L"Bullet");

	GET_SINGLE(SceneManager)->GetCurrentScene()->AddObject(bullet, LAYER::PROJECTILE);
}
