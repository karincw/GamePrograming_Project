#include "pch.h"
#include "Agent.h"
#include "SpriteRenderer.h"

Agent::Agent()
{
	AddComponent<SpriteRenderer>();
	//GetComponent<SpriteRenderer>()->CreateTexture(L"Texture\\jiwoo.bmp", L"Tile", );
}

Agent::~Agent()
{
}

void Agent::Update()
{
}

void Agent::LateUpdate()
{
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
