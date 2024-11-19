#include "pch.h"
#include "StageScene.h"
#include "Object.h"
#include "Agent.h"
#include "Transform.h"
#include "Tile.h"

void StageScene::Init()
{
	Tile* tile = new Tile;
	AddObject(tile, LAYER::DEFAULT);

	Agent* agent = new Agent;
	AddObject(agent, LAYER::DEFAULT);

	tile->GetTransform()->SetPosition({ SCREEN_WIDTH / 2 , SCREEN_HEIGHT / 2 });
	agent->GetTransform()->SetPosition({ SCREEN_WIDTH / 2 , SCREEN_HEIGHT / 2 });
}
