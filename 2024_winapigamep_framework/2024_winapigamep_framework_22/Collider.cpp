#include "pch.h"
#include "Collider.h"
#include "Object.h"
#include "GDISelector.h"
#include "Scene.h"
#include "SceneManager.h"
#include "Camera.h"
#include "Action.h"

UINT Collider::m_sNextID = 0;
Collider::Collider()
	: m_vSize(30.f, 30.f)
	, m_vLatePos(0.f, 0.f)
	, m_vOffsetPos(0.f, 0.f)
	, m_ID(m_sNextID++)
{
	collisionEnterEvent = new VariadicAction<Collider*, Object*>();
	collisionStayEvent = new VariadicAction<Collider*, Object*>();
	collisionExitEvent = new VariadicAction<Collider*, Object*>();
}

Collider::~Collider()
{
	delete collisionEnterEvent;
	delete collisionStayEvent;
	delete collisionExitEvent;
}

void Collider::LateUpdate()
{
	if (!_enable) return;
	const Object* pOwner = GetOwner();
	Transform* trm = m_pOwner->GetComponent<Transform>();
	Vec2 vPos = trm->GetPosition();
	m_vLatePos = vPos + m_vOffsetPos;
}

void Collider::Render(HDC _hdc)
{
	if (!_enable) return;
	PEN_TYPE ePen = PEN_TYPE::GREEN;
	if (m_showDebug)
		ePen = PEN_TYPE::RED;
	GDISelector pen(_hdc, ePen);
	GDISelector brush(_hdc, BRUSH_TYPE::HOLLOW);
	Vec2 RenderPos = m_vLatePos - GET_SINGLE(SceneManager)->GetCurrentScene()->GetCamera()->GetTransform()->GetPosition();
	RECT_RENDER(_hdc, RenderPos.x, RenderPos.y, m_vSize.x, m_vSize.y);
}

void Collider::EnterCollision(Collider* _other)
{
	if (!_enable) return;
	m_showDebug = true;
	GetOwner()->EnterCollision(_other);
	collisionEnterEvent->Invoke(_other, GetOwner());
}

void Collider::StayCollision(Collider* _other)
{
	if (!_enable) return;
	GetOwner()->StayCollision(_other);
	collisionStayEvent->Invoke(_other, GetOwner());
}

void Collider::ExitCollision(Collider* _other)
{
	if (!_enable) return;
	GetOwner()->ExitCollision(_other);
	m_showDebug = false;
	collisionExitEvent->Invoke(_other, GetOwner());
}

void Collider::UpdateLatedUpatedPos()
{
	Transform* trm = m_pOwner->GetComponent<Transform>();
	Vec2 vPos = trm->GetPosition();
	m_vLatePos = vPos + m_vOffsetPos;
}
