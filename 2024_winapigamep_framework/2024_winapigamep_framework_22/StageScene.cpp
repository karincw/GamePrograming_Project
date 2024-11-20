#include "pch.h"
#include "StageScene.h"
#include "Object.h"
#include "Agent.h"
#include "Transform.h"
#include "Tile.h"
#include "SpriteRenderer.h"

void StageScene::Init()
{
	Tile* tile1 = new Tile;
	AddObject(tile1, LAYER::DEFAULT);
	Tile* tile2 = new Tile;
	AddObject(tile2, LAYER::DEFAULT);
	Tile* tile3 = new Tile;
	AddObject(tile3, LAYER::DEFAULT);
	Tile* tile4 = new Tile;
	AddObject(tile4, LAYER::DEFAULT);
	Tile* tile5 = new Tile;
	AddObject(tile5, LAYER::DEFAULT);
	Tile* tile6 = new Tile;
	AddObject(tile6, LAYER::DEFAULT);
	Tile* tile7 = new Tile;
	AddObject(tile7, LAYER::DEFAULT);
	Tile* tile8 = new Tile;
	AddObject(tile8, LAYER::DEFAULT);
	Agent* agent = new Agent;
	AddObject(agent, LAYER::DEFAULT);
	agent->GetTransform()->SetPosition({ SCREEN_WIDTH / 2 , SCREEN_HEIGHT / 2 });

	tile1->GetTransform()->SetPosition({ SCREEN_WIDTH / 2 - 450, SCREEN_HEIGHT / 2 - 150 });
	tile2->GetTransform()->SetPosition({ SCREEN_WIDTH / 2 - 150, SCREEN_HEIGHT / 2 - 150 });
	tile3->GetTransform()->SetPosition({ SCREEN_WIDTH / 2 + 150, SCREEN_HEIGHT / 2 - 150 });
	tile4->GetTransform()->SetPosition({ SCREEN_WIDTH / 2 + 450, SCREEN_HEIGHT / 2 - 150 });
	tile5->GetTransform()->SetPosition({ SCREEN_WIDTH / 2 - 450, SCREEN_HEIGHT / 2 + 150 });
	tile6->GetTransform()->SetPosition({ SCREEN_WIDTH / 2 - 150, SCREEN_HEIGHT / 2 + 150 });
	tile7->GetTransform()->SetPosition({ SCREEN_WIDTH / 2 + 150, SCREEN_HEIGHT / 2 + 150 });
	tile8->GetTransform()->SetPosition({ SCREEN_WIDTH / 2 + 450, SCREEN_HEIGHT / 2 + 150 });

	//tile1->GetComponent<SpriteRenderer>()->CreateTexture(L"Texture\\bishojo1_resize.bmp", L"bishojo1");
	tile1->GetComponent<SpriteRenderer>()->CreateTexture(L"Texture\\bishojo1.bmp", L"bishojo1");
	tile2->GetComponent<SpriteRenderer>()->CreateTexture(L"Texture\\bishojo2.bmp", L"bishojo2");
	tile3->GetComponent<SpriteRenderer>()->CreateTexture(L"Texture\\bishojo3.bmp", L"bishojo3");
	tile4->GetComponent<SpriteRenderer>()->CreateTexture(L"Texture\\bishojo4.bmp", L"bishojo4");
	tile5->GetComponent<SpriteRenderer>()->CreateTexture(L"Texture\\bishojo5.bmp", L"bishojo5");
	tile6->GetComponent<SpriteRenderer>()->CreateTexture(L"Texture\\bishojo6.bmp", L"bishojo6");
	tile7->GetComponent<SpriteRenderer>()->CreateTexture(L"Texture\\bishojo7.bmp", L"bishojo7");
	tile8->GetComponent<SpriteRenderer>()->CreateTexture(L"Texture\\bishojo8.bmp", L"bishojo8");

}
