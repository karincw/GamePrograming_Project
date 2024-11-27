#include "pch.h"
#include "PigScene.h"
#include "Object.h"
#include "Agent.h"
#include "Transform.h"
#include "TileObject.h"
#include "SpriteRenderer.h"

void PigScene::Init()
{
	Agent* agent = new Agent;
	AddObject(agent, LAYER::DEFAULT);
	agent->GetTransform()->SetPosition({ SCREEN_WIDTH / 2 , SCREEN_HEIGHT / 2 });


	for (int i = 0; i < 10; ++i) {
		TileObject* tile = new TileObject;
		AddObject(tile, LAYER::DEFAULT);

		tile->GetTransform()->SetPosition({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + i*256 });
	}
	//tile1->GetComponent<SpriteRenderer>()->CreateTexture(L"Texture\\bishojo1_resize.bmp", L"bishojo1");
}
