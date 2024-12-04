#include "pch.h"
#include "Agent.h"
#include "SpriteRenderer.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "TimeManager.h"
#include "Animator.h"
#include "Animation.h"
#include "Collider.h"
#include "Scene.h"
#include "Camera.h"
#include "UIManager.h"
#include "Action.h"
#include "Object.h"
#include "FallTileObject.h"
#include "RollingSkillUI.h"

#define SPEED 350
#define ROLLING_SPEED 600
#define DAMAGE 10

#pragma region Callback Actions

void EndRolling(Object* owner)
{
	Agent* agent = dynamic_cast<Agent*>(owner);
	agent->isRolling = false;
	agent->isGroundCheck = false;

	auto func = [](Object* obj) {
		Agent* agent = dynamic_cast<Agent*>(obj);
		agent->canRolling = true;
		};

	GET_SINGLE(TimeManager)->DelayRun(0.2f, func, owner);
}
void EndHit(Object* owner)
{
	Agent* agent = dynamic_cast<Agent*>(owner);
	agent->isHit = false;

	auto func = [](Object* obj) {
		Agent* agent = dynamic_cast<Agent*>(obj);
		agent->canHit = true;
		};

	GET_SINGLE(TimeManager)->DelayRun(1, func, owner);
}
void SetMoveToBeforeTile(Object* owner)
{
	Agent* agent = dynamic_cast<Agent*>(owner);
	if (!agent->backUpTile) return;

	Vec2 dir = agent->backUpTile->GetTransform()->GetPosition() - agent->GetTransform()->GetPosition();
	agent->GetTransform()->Translate(dir);
	agent->cam->GetTransform()->Translate(dir);
	agent->rollingSkillUI->GetTransform()->Translate(dir);
}

#pragma endregion

bool ApplyDamage()
{
	UIManager* uiManager = GET_SINGLE(UIManager);
	uiManager->SetHPPercent(uiManager->GetHPPercent() - DAMAGE);
	if (uiManager->GetHPPercent() <= 0)
	{
		return false;
	}
	return true;
}


Agent::Agent()
	: isRight(true), isRun(false)
	, isRolling(false), canRolling(true)
	, isHit(false), canHit(true)
	, backUpTile(nullptr)
	, isGroundCheck(true)
{
	GetTransform()->SetScale({ 128, 128 });

	AddComponent<Animator>();
	Animator* animator = GetComponent<Animator>();
	animator->CreateTexture(L"Texture\\Noah_sheet.bmp", L"Noah_sheet");

	animator->CreateAnimation(L"Character_Idle_r", Vec2(0, 0), Vec2(32, 32), Vec2(32, 0), 1, 0.1f);
	animator->CreateAnimation(L"Character_Idle_l", Vec2(0, 96), Vec2(32, 32), Vec2(32, 0), 1, 0.1f);

	animator->CreateAnimation(L"Character_Run_r", Vec2(0, 32), Vec2(32, 32), Vec2(32, 0), 8, 0.1f);
	animator->CreateAnimation(L"Character_Run_l", Vec2(0, 128), Vec2(32, 32), Vec2(32, 0), 8, 0.1f);

	animator->CreateAnimation(L"Character_Rolling_r", Vec2(0, 64), Vec2(32, 32), Vec2(32, 0), 6, 0.1f);
	animator->CreateAnimation(L"Character_Rolling_l", Vec2(0, 160), Vec2(32, 32), Vec2(32, 0), 6, 0.1f);

	animator->CreateAnimation(L"Character_Hit_l", Vec2(0, 192), Vec2(32, 32), Vec2(32, 0), 8, 0.1f);
	animator->CreateAnimation(L"Character_Hit_r", Vec2(0, 224), Vec2(32, 32), Vec2(32, 0), 8, 0.1f);

	AddComponent<Collider>();
	Collider* col = GetComponent<Collider>();
	animator->FindAnimation(L"Character_Rolling_r")->animationEndEvent->Insert(EndRolling);
	animator->FindAnimation(L"Character_Rolling_l")->animationEndEvent->Insert(EndRolling);

	animator->FindAnimation(L"Character_Hit_l")->animationEndEvent->Insert(EndHit);
	animator->FindAnimation(L"Character_Hit_r")->animationEndEvent->Insert(EndHit);

	col->SetSize({ 32,64 });

	col->SetOffSetPos({ 0,16 });
	SceneManager* sm = GET_SINGLE(SceneManager);
	
	cam = sm->GetCurrentScene()->GetCamera();
	
	for (auto s : sm->GetCurrentScene()->GetLayerObjects(LAYER::UI)) {
		auto roll = dynamic_cast<RollingSkillUI*>(s);
		if (roll) {
			rollingSkillUI = roll;
		}
	}

	SetName(L"Player");
	isGroundCheck = true;
}
Agent::~Agent()
{
}

void Agent::Update()
{
	if (!isGroundCheck)
	{
		SetMoveToBeforeTile(this);
		Hit();
	}
	if (!isRolling)
		isGroundCheck = false;

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

	if (!isRolling && !isHit)
	{
		if (moveDir.Length() == 0)
		{
			std::wstring animationName = L"Character_Idle";
			if (isRight)
				animationName += L"_r";
			else
				animationName += L"_l";

			GetComponent<Animator>()->PlayAnimation(animationName, true);
			isRun = false;
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

		if (GET_KEYDOWN(KEY_TYPE::SPACE) && moveDir.Length() > 0 && canRolling)
		{
			Animator* ani = GetComponent<Animator>();
			std::wstring animationName = L"Character_Rolling";
			if (isRight)
				animationName += L"_r";
			else
				animationName += L"_l";

			ani->PlayAnimation(animationName, false);
			isRolling = true;
			isRun = false;
			canRolling = false;
			rollingDir = moveDir;
			rollingSkillUI->CoolTimeAnimation();
		}
		moveDir = moveDir * SPEED * dt;

	}
	else if (!isHit && isRolling)
	{
		moveDir = rollingDir * ROLLING_SPEED * dt;
	}

	GetTransform()->Translate(moveDir);
	cam->GetTransform()->Translate(moveDir);
	rollingSkillUI->GetTransform()->Translate(moveDir);

}

void Agent::Render(HDC _hdc)
{
	ComponentRender(_hdc);
}

void Agent::EnterCollision(Collider* _other) //오직 피격만 구현
{
	std::wstring name = _other->GetOwner()->GetName();
	if (name != L"Bullet" && name != L"Explosion") return;

	if (!isRolling)
		Hit();
}

void Agent::StayCollision(Collider* _other)
{
	if (_other->GetOwner()->GetName() == L"Tile")
	{
		isGroundCheck = true;
	}
}

void Agent::ExitCollision(Collider* _other)
{
}

void Agent::Hit()
{
	if (!canHit || isRolling) return;
	isHit = true;
	canHit = false;

	Animator* ani = GetComponent<Animator>();
	ani->StopAnimation();

	std::wstring animationName = L"Character_Hit";
	if (isRight)
		animationName += L"_r";
	else
		animationName += L"_l";

	ani->PlayAnimation(animationName, false);

	if (!ApplyDamage())
	{
		//죽었음
	}

	isRun = false;
}