#include "pch.h"
#include "PigScene.h"
#include "Object.h"
#include "Agent.h"
#include "Transform.h"
#include "TileObject.h"
#include "TrapTileObject.h"
#include "SpriteRenderer.h"

void PigScene::Init()
{
	Agent* agent = new Agent;
	AddObject(agent, LAYER::PLAYER);
	agent->GetTransform()->SetPosition({ SCREEN_WIDTH / 2 , SCREEN_HEIGHT / 2 });

	Vec2 tilePos = { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};

	tilePos = CreateVerticalTileGroup(tilePos, 2, 10, false);
	tilePos = CreateVerticalTileGroup(tilePos, 2, 3, false);
	tilePos = CreateVerticalTileGroup(tilePos, 2, 3, false);
	tilePos = CreateVerticalTileGroup(tilePos, 2, 3, false);
	tilePos = CreateVerticalTileGroup(tilePos, 2, 10, false);
	tilePos = CreateVerticalTileGroup(tilePos, 2, 2, false);
	tilePos = CreateVerticalTileGroup(tilePos, 2, 2, false);
	tilePos = CreateHorizontalTileGroup(tilePos, 8, 2, true);
	tilePos.x -= 768;
	tilePos.y += 512;
	// Boom Trap
	tilePos = CreateVerticalTileGroup(tilePos, 2, 4, true);
	CreateTrapTile({ tilePos.x, tilePos.y - 1280});
	CreateTrapTile({ tilePos.x + 256, tilePos.y - 1024 });
	CreateTrapTile({ tilePos.x, tilePos.y - 768 });
	CreateTrapTile({ tilePos.x + 256, tilePos.y - 512 });
}

void PigScene::CreateTile(Vec2 vec)
{
	TileObject* tile = new TileObject;
	AddObject(tile, LAYER::BACKGROUND);

	tile->GetTransform()->SetPosition(vec);
}

void PigScene::CreateTrapTile(Vec2 vec)
{
	TrapTileObject* tile = new TrapTileObject;
	AddObject(tile, LAYER::TRAP);

	tile->GetTransform()->SetPosition(vec);
}

Vec2 PigScene::CreateVerticalTileGroup(Vec2 startVec, int x, int y, bool isDown)
{
	int dirY = isDown ? 1 : -1;
	int vecX = startVec.x;
	for (int i = 0; i < y; ++i) {
		for (int j = 0; j < x; ++j) {
			CreateTile(startVec);
			startVec.x += 256;
		}
		startVec.x = vecX;
		startVec.y += dirY * 256;
	}
	startVec.y += dirY * 256;
	return startVec;
}

Vec2 PigScene::CreateHorizontalTileGroup(Vec2 startVec, int x, int y, bool isRight)
{
	int dirX = isRight ? 1 : -1;
	int vecY = startVec.y;
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; ++j) {
			CreateTile(startVec);
			startVec.y -= 256;
		}
		startVec.y = vecY;
		startVec.x += dirX * 256;
	}
	startVec.x += dirX * 256;
	return startVec;
}
