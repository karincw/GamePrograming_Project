#include "pch.h"
#include "Agent.h"
#include "SpriteRenderer.h"
#include "InputManager.h"
#include "Transform.h"
#include "TimeManager.h"
#include "Animator.h"
#include "Animator.h"
#include "Collider.h"
#include "Rigidbody2D.h"

Agent::Agent()
{

	//AddComponent<Rigidbody2D>();
	//Rigidbody2D* rb = GetComponent<Rigidbody2D>();
	//rb->SetGravityScale(1);

	GetTransform()->SetScale({ 128, 128 });

	AddComponent<Animator>();
	Animator* animator = GetComponent<Animator>();
	animator->CreateTexture(L"Texture\\character_sheet.bmp", L"character_sheet");
	animator->CreateAnimation(L"Character_Idle", Vec2(0, 0), Vec2(32, 32), Vec2(32, 0), 6, 0.1f);
	animator->CreateAnimation(L"Character_Run", Vec2(0, 32), Vec2(32, 32), Vec2(32, 0), 8, 0.1f);

	animator->PlayAnimation(L"Character_Run", true);

	AddComponent<Collider>();
	Collider* col = GetComponent<Collider>();
	col->SetSize({ 50,50 });
}

Agent::~Agent()
{
}

void Agent::Update()
{
	float dt = GET_SINGLE(TimeManager)->GetDT();
	Vec2 moveDir = { 0, 0 };
	if (GET_KEY(KEY_TYPE::W))
	{
		moveDir += Vec2(0, -1);
	}
	if (GET_KEY(KEY_TYPE::A))
	{
		moveDir += Vec2(-1, 0);
	}
	if (GET_KEY(KEY_TYPE::S))
	{
		moveDir += Vec2(0, 1);
	}
	if (GET_KEY(KEY_TYPE::D))
	{
		moveDir += Vec2(1, 0);
	}
	moveDir.Normalize();
	GetTransform()->Translate(moveDir * 100 * dt);
}

void Agent::Render(HDC _hdc)
{
	ComponentRender(_hdc);
}

void Agent::EnterCollision(Collider* _other)
{
}

void Agent::StayCollision(Collider* _other)
{
}

void Agent::ExitCollision(Collider* _other)
{
}
