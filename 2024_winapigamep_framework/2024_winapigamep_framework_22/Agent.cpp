#include "pch.h"
#include "Agent.h"
#include "SpriteRenderer.h"
#include "InputManager.h"
#include "Transform.h"
#include "TimeManager.h"
#include "Animator.h"
#include "Animation.h"
#include "Collider.h"
#include "Rigidbody2D.h"
#include "Action.h"

void PlayRun(Object* owner)
{
	Agent* agent = dynamic_cast<Agent*>(owner);
	agent->isRolling = false;

	Animator* ani = agent->GetComponent<Animator>();
	std::wstring animationName = L"Character_Idle";
	Vec2 dir = agent->GetRollingDir();
	if (dir.x >= 0)
	{
		animationName += L"_r";
	}
	else if (dir.x < 0)
	{
		animationName += L"_l";
	}

	agent->GetComponent<Animator>()->PlayAnimation(animationName, true);
}

Agent::Agent()
	:isRight(false), isRun(false), isRolling(false)
	, RollingDir({ 0,0 })
{
	//AddComponent<Rigidbody2D>();
	//Rigidbody2D* rb = GetComponent<Rigidbody2D>();
	//rb->SetGravityScale(1);

	GetTransform()->SetScale({ 128, 128 });

	AddComponent<Animator>();
	Animator* animator = GetComponent<Animator>();
	animator->CreateTexture(L"Texture\\character_sheet.bmp", L"character_sheet");
	animator->CreateAnimation(L"Character_Idle_r", Vec2(0, 0), Vec2(32, 32), Vec2(32, 0), 1, 0.1f);
	animator->CreateAnimation(L"Character_Run_r", Vec2(0, 32), Vec2(32, 32), Vec2(32, 0), 8, 0.1f);
	animator->CreateAnimation(L"Character_Rolling_r", Vec2(0, 64), Vec2(32, 32), Vec2(32, 0), 6, 0.1f);

	animator->CreateAnimation(L"Character_Idle_l", Vec2(0, 96), Vec2(32, 32), Vec2(32, 0), 1, 0.1f);
	animator->CreateAnimation(L"Character_Run_l", Vec2(0, 128), Vec2(32, 32), Vec2(32, 0), 8, 0.1f);
	animator->CreateAnimation(L"Character_Rolling_l", Vec2(0, 160), Vec2(32, 32), Vec2(32, 0), 6, 0.1f);

	animator->PlayAnimation(L"Character_Run_r", true);

	AddComponent<Collider>();
	Collider* col = GetComponent<Collider>();
	col->SetOffSetPos({ 0, 48 });
	animator->FindAnimation(L"Character_Rolling_l")->animationEndEvent->Insert(PlayRun);
	animator->FindAnimation(L"Character_Rolling_r")->animationEndEvent->Insert(PlayRun);

	col->SetSize({ 32,32 });
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

	if (!isRolling)
	{
		if (moveDir.x == 0 && moveDir.y == 0)
		{
			std::wstring animationName = L"Character_Idle";
			if (isRight)
				animationName += L"_r";
			else
				animationName += L"_l";

			GetComponent<Animator>()->PlayAnimation(animationName, true);
			isRun = false;
		}
		else if (!isRun || (isRight && moveDir.x < 0))
		{
			GetComponent<Animator>()->PlayAnimation(L"Character_Run_l", true);
			isRight = false;
			isRun = true;
		}
		else if (!isRun || (!isRight && moveDir.x > 0))
		{
			GetComponent<Animator>()->PlayAnimation(L"Character_Run_r", true);
			isRight = true;
			isRun = true;
		}
		else if (!isRun && moveDir.y != 0)
		{
			std::wstring animationName = L"Character_Run";
			if (isRight)
				animationName += L"_r";
			else
				animationName += L"_l";

			GetComponent<Animator>()->PlayAnimation(animationName, true);
			isRun = true;
		}

		if (GET_KEYDOWN(KEY_TYPE::SPACE) && moveDir.Length() > 0)
		{
			Animator* ani = GetComponent<Animator>();
			std::wstring animationName = L"Character_Rolling";
			if (moveDir.x >= 0)
			{
				animationName += L"_r";
			}
			else if (moveDir.x < 0)
			{
				animationName += L"_l";
			}

			ani->PlayAnimation(animationName, false);
			RollingDir = moveDir * 2;
			isRolling = true;
			isRun = false;
		}

		GetTransform()->Translate(moveDir * 100 * dt);
	}
	else
	{
		GetTransform()->Translate(RollingDir * 100 * dt);
	}

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
