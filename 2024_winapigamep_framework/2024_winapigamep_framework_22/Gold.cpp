#include "pch.h"
#include "Gold.h"
#include "SpriteRenderer.h"
#include "Collider.h"
#include "EndingManager.h"
#include "SceneManager.h"

Gold::Gold()
{
	GetTransform()->SetScale({ 200, 200 });

	AddComponent<SpriteRenderer>();
	SpriteRenderer* sp = GetComponent<SpriteRenderer>();
	sp->CreateTexture(L"Texture\\Gold.bmp", L"gold");

	AddComponent<Collider>();
	Collider* collider = GetComponent<Collider>();
	collider->SetSize({ 200, 200 });

}

Gold::~Gold()
{
}

void Gold::Update()
{

}

void Gold::Render(HDC _hdc)
{
	ComponentRender(_hdc);
}

void Gold::EnterCollision(Collider* _other)
{
	if (_other->GetOwner()->GetName() == L"Player")
	{
		std::cout << "°ÔÀÓ ³¡";
		GET_SINGLE(EndingManager)->SetEnding(true);
		GET_SINGLE(SceneManager)->LoadScene(L"EndingScene");
	}
}
