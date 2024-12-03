#include "pch.h"
#include "StarLazer.h"
#include "Lazer.h"
#include "Animator.h"
#include "SceneManager.h"
#include "Scene.h"
#include "InputManager.h"

StarLazer::StarLazer(Vec2 position)
{
	GetTransform()->SetScale(Vec2(1360, 1360));
	GetTransform()->SetPosition(position);

	AddComponent<Animator>();
	Animator* animator = GetComponent<Animator>();
	animator->CreateTexture(L"Texture\\StarLazer.bmp", L"StarLazer_Sheet");
	animator->CreateAnimation(L"StarLazer", Vec2(0, 0), Vec2(512, 512), Vec2(0, 0), 1, 1.0f);
	animator->CreateAnimation(L"StarLazer_rot", Vec2(512, 0), Vec2(512, 512), Vec2(0, 0), 1, 1.0f);

	Lazer* l = new Lazer(LAZER_DIR::Left, GetTransform()->GetScale());
	GET_SINGLE(SceneManager)->GetCurrentScene()->AddObject(l, LAYER::PROJECTILE);
	lazers[0] = l;
	l->GetTransform()->SetPosition(GetTransform()->GetPosition());

	l = new Lazer(LAZER_DIR::Right, GetTransform()->GetScale());
	GET_SINGLE(SceneManager)->GetCurrentScene()->AddObject(l, LAYER::PROJECTILE);
	lazers[1] = l;
	l->GetTransform()->SetPosition(GetTransform()->GetPosition());
	
	l = new Lazer(LAZER_DIR::Top, GetTransform()->GetScale());
	GET_SINGLE(SceneManager)->GetCurrentScene()->AddObject(l, LAYER::PROJECTILE);
	lazers[2] = l;
	l->GetTransform()->SetPosition(GetTransform()->GetPosition());
	
	l = new Lazer(LAZER_DIR::Bottom, GetTransform()->GetScale());
	GET_SINGLE(SceneManager)->GetCurrentScene()->AddObject(l, LAYER::PROJECTILE);
	lazers[3] = l;
	l->GetTransform()->SetPosition(GetTransform()->GetPosition());

	animator->PlayAnimation(L"StarLazer", false);
}

StarLazer::~StarLazer()
{

}

void StarLazer::Update()
{
	if (GET_KEYDOWN(KEY_TYPE::LEFT))
	{
		lazers[0]->SetEnable(true);
	}
	if (GET_KEYDOWN(KEY_TYPE::RIGHT))
	{
		lazers[1]->SetEnable(true);
	}
	if (GET_KEYDOWN(KEY_TYPE::UP))
	{
		lazers[2]->SetEnable(true);
	}
	if (GET_KEYDOWN(KEY_TYPE::DOWN))
	{
		lazers[3]->SetEnable(true);
	}
}

void StarLazer::Render(HDC _hdc)
{
	ComponentRender(_hdc);
}

void StarLazer::EnterCollision(Collider* _other)
{
}

void StarLazer::StayCollision(Collider* _other)
{
}

void StarLazer::ExitCollision(Collider* _other)
{
}
