#include "pch.h"
#include "StarLazer.h"
#include "Lazer.h"
#include "Animator.h"
#include "SceneManager.h"
#include "Scene.h"
#include "InputManager.h"

void PlayLazer(Object* owner)
{
	StarLazer* sl = dynamic_cast<StarLazer*>(owner);

	

}

StarLazer::StarLazer(Vec2 position)
{
	GetTransform()->SetScale(Vec2(1360, 1360));
	GetTransform()->SetPosition(position);

	AddComponent<Animator>();
	Animator* animator = GetComponent<Animator>();
	animator->CreateTexture(L"Texture\\StarLazer.bmp", L"StarLazer_Sheet");
	animator->CreateAnimation(L"StarLazer", Vec2(0, 0), Vec2(512, 512), Vec2(512, 0), 2, 0.5f);

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

void StarLazer::OpenHorizontal()
{
	lazers[0]->SetEnable(true);
	lazers[1]->SetEnable(true);
	lazers[2]->SetEnable(false);
	lazers[3]->SetEnable(false);
}
void StarLazer::OpenVertical()
{
	lazers[0]->SetEnable(false);
	lazers[1]->SetEnable(false);
	lazers[2]->SetEnable(true);
	lazers[3]->SetEnable(true);
}