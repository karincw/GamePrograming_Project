#include "pch.h"
#include "EndingScene.h"
#include "GameOverText.h"
#include "GameClearText.h"
#include "EndingManager.h"
#include "SceneManager.h"

void EndingScene::Init()
{
	Object* gameResultText = nullptr;

	if(GET_SINGLE(EndingManager)->GetEnding())
		gameResultText = new GameClearText;
	else gameResultText = new GameOverText;

	AddObject(gameResultText, LAYER::UI);
	gameResultText->GetTransform()->SetPosition({ SCREEN_WIDTH / 2 , 100 });
	GET_SINGLE(EndingManager)->SetEnding(false);
}

void EndingScene::Render(HDC _hdc)
{
	Scene::Render(_hdc);
}

void EndingScene::Release()
{
}
