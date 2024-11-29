#include "pch.h"
#include "BishojoScene.h"
#include "Object.h"
#include "Agent.h"
#include "CollisionManager.h"

#include "BishojoObject.h"
#include "SpriteRenderer.h"
#include "Crossbow.h"

void BishojoScene::Init()
{
	CollisionManager* cm = GET_SINGLE(CollisionManager);
	cm->CheckReset();
	cm->CheckLayer(LAYER::PROJECTILE, LAYER::PLAYER);

	BishojoObject* tile1 = new BishojoObject;
	AddObject(tile1, LAYER::DEFAULT);
	BishojoObject* tile2 = new BishojoObject;
	AddObject(tile2, LAYER::DEFAULT);
	BishojoObject* tile3 = new BishojoObject;
	AddObject(tile3, LAYER::DEFAULT);
	BishojoObject* tile4 = new BishojoObject;
	AddObject(tile4, LAYER::DEFAULT);
	BishojoObject* tile5 = new BishojoObject;
	AddObject(tile5, LAYER::DEFAULT);
	BishojoObject* tile6 = new BishojoObject;
	AddObject(tile6, LAYER::DEFAULT);
	BishojoObject* tile7 = new BishojoObject;
	AddObject(tile7, LAYER::DEFAULT);
	BishojoObject* tile8 = new BishojoObject;
	AddObject(tile8, LAYER::DEFAULT);
	BishojoObject* tile9 = new BishojoObject;
	AddObject(tile9, LAYER::DEFAULT);
	BishojoObject* tile10 = new BishojoObject;
	AddObject(tile10, LAYER::DEFAULT);
	BishojoObject* tile11 = new BishojoObject;
	AddObject(tile11, LAYER::DEFAULT);
	BishojoObject* tile12 = new BishojoObject;
	AddObject(tile12, LAYER::DEFAULT);
	BishojoObject* tile13 = new BishojoObject;
	AddObject(tile13, LAYER::DEFAULT);
	BishojoObject* tile14 = new BishojoObject;
	AddObject(tile14, LAYER::DEFAULT);
	BishojoObject* tile15 = new BishojoObject;
	AddObject(tile15, LAYER::DEFAULT);
	BishojoObject* tile16 = new BishojoObject;
	AddObject(tile16, LAYER::DEFAULT);

	Crossbow* crossBow = new Crossbow(0.3f, L"Right");
	AddObject(crossBow, LAYER::ENEMY);
	crossBow->GetTransform()->SetPosition({ SCREEN_WIDTH / 2 , SCREEN_HEIGHT / 2 });

	Agent* agent = new Agent;
	AddObject(agent, LAYER::PLAYER);
	agent->GetTransform()->SetPosition({ SCREEN_WIDTH / 2 , SCREEN_HEIGHT / 2 });

	Transform* trm = tile1->GetTransform();
	trm->SetPosition({ SCREEN_WIDTH / 2 - trm->GetScale().x * 1.5f, SCREEN_HEIGHT / 2 - trm->GetScale().y * 0.5f });

	tile2->GetTransform()->SetPosition({ SCREEN_WIDTH / 2 - trm->GetScale().x * 0.5f, SCREEN_HEIGHT / 2 - trm->GetScale().y * 0.5f });
	tile3->GetTransform()->SetPosition({ SCREEN_WIDTH / 2 + trm->GetScale().x * 0.5f, SCREEN_HEIGHT / 2 - trm->GetScale().y * 0.5f });
	tile4->GetTransform()->SetPosition({ SCREEN_WIDTH / 2 + trm->GetScale().x * 1.5f, SCREEN_HEIGHT / 2 - trm->GetScale().y * 0.5f });
	tile5->GetTransform()->SetPosition({ SCREEN_WIDTH / 2 - trm->GetScale().x * 1.5f, SCREEN_HEIGHT / 2 + trm->GetScale().y * 0.5f });
	tile6->GetTransform()->SetPosition({ SCREEN_WIDTH / 2 - trm->GetScale().x * 0.5f, SCREEN_HEIGHT / 2 + trm->GetScale().y * 0.5f });
	tile7->GetTransform()->SetPosition({ SCREEN_WIDTH / 2 + trm->GetScale().x * 0.5f, SCREEN_HEIGHT / 2 + trm->GetScale().y * 0.5f });
	tile8->GetTransform()->SetPosition({ SCREEN_WIDTH / 2 + trm->GetScale().x * 1.5f, SCREEN_HEIGHT / 2 + trm->GetScale().y * 0.5f });
	tile9->GetTransform()->SetPosition({ SCREEN_WIDTH / 2 + trm->GetScale().x * 2.5f, SCREEN_HEIGHT / 2 - trm->GetScale().y * 0.5f });
	tile10->GetTransform()->SetPosition({ SCREEN_WIDTH / 2 - trm->GetScale().x * 2.5f, SCREEN_HEIGHT / 2 - trm->GetScale().y * 0.5f });
	tile11->GetTransform()->SetPosition({ SCREEN_WIDTH / 2 + trm->GetScale().x * 2.5f, SCREEN_HEIGHT / 2 + trm->GetScale().y * 0.5f });
	tile12->GetTransform()->SetPosition({ SCREEN_WIDTH / 2 - trm->GetScale().x * 2.5f, SCREEN_HEIGHT / 2 + trm->GetScale().y * 0.5f });
	tile13->GetTransform()->SetPosition({ SCREEN_WIDTH / 2 + trm->GetScale().x * 0.5f, SCREEN_HEIGHT / 2 - trm->GetScale().y * 1.5f });
	tile14->GetTransform()->SetPosition({ SCREEN_WIDTH / 2 - trm->GetScale().x * 0.5f, SCREEN_HEIGHT / 2 - trm->GetScale().y * 1.5f });
	tile15->GetTransform()->SetPosition({ SCREEN_WIDTH / 2 + trm->GetScale().x * 0.5f, SCREEN_HEIGHT / 2 + trm->GetScale().y * 1.5f });
	tile16->GetTransform()->SetPosition({ SCREEN_WIDTH / 2 - trm->GetScale().x * 0.5f, SCREEN_HEIGHT / 2 + trm->GetScale().y * 1.5f });

	tile1->GetComponent<SpriteRenderer>()->CreateTexture(L"Texture\\bishojo1.bmp", L"bishojo1");
	tile2->GetComponent<SpriteRenderer>()->CreateTexture(L"Texture\\bishojo2.bmp", L"bishojo2");
	tile3->GetComponent<SpriteRenderer>()->CreateTexture(L"Texture\\bishojo3.bmp", L"bishojo3");
	tile4->GetComponent<SpriteRenderer>()->CreateTexture(L"Texture\\bishojo4.bmp", L"bishojo4");
	tile5->GetComponent<SpriteRenderer>()->CreateTexture(L"Texture\\bishojo5.bmp", L"bishojo5");
	tile6->GetComponent<SpriteRenderer>()->CreateTexture(L"Texture\\bishojo6.bmp", L"bishojo6");
	tile7->GetComponent<SpriteRenderer>()->CreateTexture(L"Texture\\bishojo7.bmp", L"bishojo7");
	tile8->GetComponent<SpriteRenderer>()->CreateTexture(L"Texture\\bishojo8.bmp", L"bishojo8");
	tile9->GetComponent<SpriteRenderer>()->CreateTexture(L"Texture\\bishojo9.bmp", L"bishojo9");
	tile10->GetComponent<SpriteRenderer>()->CreateTexture(L"Texture\\bishojo10.bmp", L"bishojo10");
	tile11->GetComponent<SpriteRenderer>()->CreateTexture(L"Texture\\bishojo11.bmp", L"bishojo11");
	tile12->GetComponent<SpriteRenderer>()->CreateTexture(L"Texture\\bishojo12.bmp", L"bishojo12");
	tile13->GetComponent<SpriteRenderer>()->CreateTexture(L"Texture\\bishojo13.bmp", L"bishojo13");
	tile14->GetComponent<SpriteRenderer>()->CreateTexture(L"Texture\\bishojo14.bmp", L"bishojo14");
	tile15->GetComponent<SpriteRenderer>()->CreateTexture(L"Texture\\bishojo15.bmp", L"bishojo15");
	tile16->GetComponent<SpriteRenderer>()->CreateTexture(L"Texture\\bishojo16.bmp", L"bishojo16");

}
