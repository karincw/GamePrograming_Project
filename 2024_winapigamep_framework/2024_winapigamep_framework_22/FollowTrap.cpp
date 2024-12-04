#include "pch.h"
#include "FollowTrap.h"
#include "Collider.h"
#include "CircleCollider.h"
#include "Action.h"
#include "TimeManager.h"

void DetectColliderEnter(Collider* _other, Object* owner)
{
	Object* obj = _other->GetOwner();
	if (obj->GetName() != L"Player") return;

	FollowTrap* ft = dynamic_cast<FollowTrap*>(owner);
	ft->currentTarget = obj;
}
void DetectColliderStay(Collider* _other, Object* owner)
{

}
void DetectColliderExit(Collider* _other, Object* owner)
{
	Object* obj = _other->GetOwner();
	if (obj->GetName() != L"Player") return;

	FollowTrap* ft = dynamic_cast<FollowTrap*>(owner);
	ft->currentTarget = nullptr;
}
void ColliderEnter(Collider* _other, Object* owner)
{

}
void ColliderStay(Collider* _other, Object* owner)
{

}
void ColliderExit(Collider* _other, Object* owner)
{

}

void FollowTrap::Accel()
{
	if (currentTarget == nullptr)
	{
		Deceleration();
		return;
	}

	Transform* ownerTrm = GetTransform();
	Transform* targetTrm = currentTarget->GetTransform();

	Vec2 targetDir = targetTrm->GetPosition() - ownerTrm->GetPosition();
	targetDir.Normalize();

	Vec2 midDir = (targetDir + moveDir);
	midDir.Normalize();

	moveDir = (targetDir + moveDir * 15);

	if (moveDir.Length() == 0) moveDir = targetDir;

	if ((targetDir - midDir).Length() < MaxAccelableDir)
	{
		Accelation();
	}
	else
	{
		Deceleration();
	}

	std::cout << moveDir.x << " " << moveDir.y << "\n";
}

FollowTrap::FollowTrap()
	: speed(0)
	, currentTarget(nullptr)
	, moveDir({ 0,0 })
{

	AddComponent<CircleCollider>();
	CircleCollider* circleCol1 = GetComponent<CircleCollider>();
	circleCol1->collisionEnterEvent->Insert(ColliderEnter);
	circleCol1->collisionStayEvent->Insert(ColliderStay);
	circleCol1->collisionExitEvent->Insert(ColliderExit);

	AddComponent<CircleCollider>();
	CircleCollider* circleCol2 = GetComponent<CircleCollider>();
	circleCol2->collisionEnterEvent->Insert(DetectColliderEnter);
	circleCol2->collisionStayEvent->Insert(DetectColliderStay);
	circleCol2->collisionExitEvent->Insert(DetectColliderExit);

	circleCol1->SetRadius(64);
	circleCol2->SetRadius(256);

}

FollowTrap::~FollowTrap()
{
}

void FollowTrap::Update()
{
	Accel();

	if (speed >= maxSpeed)
		speed = maxSpeed;
	else if (speed <= 0)
		speed = 0;

	moveDir.Normalize();
	GetTransform()->Translate(moveDir * speed * fDT);
}

void FollowTrap::Render(HDC _hdc)
{
	ComponentRender(_hdc);
}

void FollowTrap::Accelation()
{
	speed += AccelationSpeed;
}

void FollowTrap::Deceleration()
{
	speed += DecelationSpeed;
}
