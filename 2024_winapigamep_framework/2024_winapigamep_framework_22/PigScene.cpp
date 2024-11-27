#include "pch.h"
#include "PigScene.h"
#include "Object.h"
#include "Agent.h"
#include "Transform.h"
#include "TileObject.h"
#include "SpriteRenderer.h"

void PigScene::Init()
{
	TileObject* tile1 = new TileObject;
	AddObject(tile1, LAYER::DEFAULT);

	Agent* agent = new Agent;
	AddObject(agent, LAYER::DEFAULT);
	agent->GetTransform()->SetPosition({ SCREEN_WIDTH / 2 , SCREEN_HEIGHT / 2 });

	Transform* trm = tile1->GetTransform();
	trm->SetPosition({ SCREEN_WIDTH / 2 - trm->GetScale().x * 1.5f, SCREEN_HEIGHT / 2 - trm->GetScale().y * 0.5f });

	tile1->GetTransform()->SetPosition({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 });

	//tile1->GetComponent<SpriteRenderer>()->CreateTexture(L"Texture\\bishojo1_resize.bmp", L"bishojo1");
}
