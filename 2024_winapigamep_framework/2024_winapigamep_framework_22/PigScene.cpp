#include "pch.h"
#include "PigScene.h"
#include "Object.h"
#include "Agent.h"
#include "Transform.h"
#include "TileObject.h"
#include "TrapTileObject.h"
#include "FallTileObject.h"
#include "SpriteRenderer.h"
#include "CollisionManager.h"


void PigScene::Init()
{
	CollisionManager* cm = GET_SINGLE(CollisionManager);
	cm->CheckReset();
	cm->CheckLayer(LAYER::TRAP, LAYER::PLAYER);

	Agent* agent = new Agent;
	AddObject(agent, LAYER::PLAYER);
	agent->GetTransform()->SetPosition({ SCREEN_WIDTH / 2 , SCREEN_HEIGHT / 2 });

	Vec2 tilePos = { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};

	tilePos = CreateVerticalTileGroup(tilePos, TILE::NORMAL, 2, 10, false, true);
	tilePos = CreateVerticalTileGroup(tilePos, TILE::NORMAL, 2, 3, false, true);
	tilePos = CreateVerticalTileGroup(tilePos, TILE::NORMAL, 2, 3, false, true);
	tilePos = CreateVerticalTileGroup(tilePos, TILE::NORMAL, 2, 3, false, true);
	tilePos = CreateVerticalTileGroup(tilePos, TILE::NORMAL, 2, 10, false, true);
	tilePos = CreateVerticalTileGroup(tilePos, TILE::NORMAL, 2, 2, false, true);
	tilePos = CreateVerticalTileGroup(tilePos, TILE::NORMAL, 2, 2, false, true);
	tilePos = CreateHorizontalTileGroup(tilePos, TILE::NORMAL, 8, 2, true, true);
	tilePos.x -= 768;
	tilePos.y += 512;
	// Boom Trap
	tilePos = CreateVerticalTileGroup(tilePos, TILE::NORMAL, 2, 4, true, true);
	CreateTile({ tilePos.x, tilePos.y - 1280}, TILE::TRAP);
	CreateTile({ tilePos.x + 256, tilePos.y - 1024 }, TILE::TRAP);
	CreateTile({ tilePos.x, tilePos.y - 768 }, TILE::TRAP);
	CreateTile({ tilePos.x + 256, tilePos.y - 512 }, TILE::TRAP);
	tilePos = CreateVerticalTileGroup(tilePos, TILE::TRAP, 2, 1, true, false);
	tilePos = CreateVerticalTileGroup(tilePos, TILE::NORMAL, 2, 3, true, true);
	tilePos = CreateVerticalTileGroup(tilePos, TILE::NORMAL, 2, 2, true, false);
	// Fall Tile
	tilePos = CreateVerticalTileGroup(tilePos, TILE::FALL, 2, 4, true, true);
	tilePos = CreateVerticalTileGroup(tilePos, TILE::FALL, 2, 2, true, true);
	tilePos = CreateVerticalTileGroup(tilePos, TILE::FALL, 2, 2, true, true);
	tilePos = CreateVerticalTileGroup(tilePos, TILE::FALL, 2, 2, true, false);
	tilePos.x += 768;
	tilePos.y -= 256;
	tilePos = CreateHorizontalTileGroup(tilePos, TILE::NORMAL, 4, 2, true, false);
	CreateHorizontalTileGroup({ tilePos.x - 512, tilePos.y - 256 }, TILE::FALL, 2, 1, true, false);

	// Cross
	Vec2 tilePos2 = { tilePos.x - 256, tilePos.y - 512};
	tilePos2 = CreateVerticalTileGroup(tilePos2, TILE::NORMAL, 2, 3, false, false);
	tilePos2.y += 512;
	tilePos2.x += 512;
	tilePos2 = CreateHorizontalTileGroup(tilePos2, TILE::NORMAL, 10, 2, true, false);
	tilePos2.y -= 256;
	tilePos2 = CreateVerticalTileGroup(tilePos2, TILE::NORMAL, 2, 5, true, false);
	tilePos2.y -= 768;
	tilePos2.x += 512;
	tilePos2 = CreateHorizontalTileGroup(tilePos2, TILE::NORMAL, 2, 2, true, false);
	
	tilePos = CreateHorizontalTileGroup(tilePos, TILE::NORMAL, 11, 2, true, false);
	tilePos.x += 512;
	tilePos = CreateHorizontalTileGroup(tilePos, TILE::NORMAL, 2, 2, true, false);
	tilePos.y -= 256;
	tilePos = CreateHorizontalTileGroup(tilePos, TILE::NORMAL, 2, 2, true, false);
	tilePos.x += 128;
	tilePos.y -= 128;
	tilePos = CreateHorizontalTileGroup(tilePos, TILE::NORMAL, 1, 1, true, true);
	tilePos = CreateHorizontalTileGroup(tilePos, TILE::NORMAL, 1, 1, true, true);
	tilePos = CreateHorizontalTileGroup(tilePos, TILE::NORMAL, 1, 1, true, true);
	tilePos = CreateVerticalTileGroup(tilePos, TILE::NORMAL, 1, 1, false, true);
	tilePos = CreateVerticalTileGroup(tilePos, TILE::FALL, 1, 1, false, true);
	tilePos = CreateHorizontalTileGroup(tilePos, TILE::FALL, 1, 1, false, true);
	tilePos = CreateHorizontalTileGroup(tilePos, TILE::FALL, 1, 1, false, true);
	tilePos = CreateHorizontalTileGroup(tilePos, TILE::FALL, 1, 1, false, true);
	tilePos = CreateVerticalTileGroup(tilePos, TILE::FALL, 1, 1, false, true);
	tilePos = CreateVerticalTileGroup(tilePos, TILE::FALL, 1, 1, false, true);
	tilePos = CreateHorizontalTileGroup(tilePos, TILE::TRAP, 1, 1, true, true);
	tilePos = CreateHorizontalTileGroup(tilePos, TILE::TRAP, 1, 1, true, true);
	tilePos = CreateHorizontalTileGroup(tilePos, TILE::TRAP, 1, 1, true, true);
	tilePos = CreateHorizontalTileGroup(tilePos, TILE::TRAP, 1, 1, true, true);
	tilePos = CreateHorizontalTileGroup(tilePos, TILE::NORMAL, 1, 1, true, true);
	tilePos = CreateHorizontalTileGroup(tilePos, TILE::NORMAL, 8, 1, true, false);

	CreateTile({ 256, 0 }, TILE::TRAP);
}

void PigScene::CreateTile(Vec2 vec, TILE tileType)
{
	Object* tile = nullptr;
	switch (tileType) {
	case TILE::NORMAL:
		tile = new TileObject;
		AddObject(tile, LAYER::BACKGROUND);
		break;
	case TILE::TRAP:
		tile = new TrapTileObject;
		AddObject(tile, LAYER::TRAP);
		break;
	case TILE::FALL:
		tile = new FallTileObject;
		AddObject(tile, LAYER::TRAP);
		break;
	}
	
	tile->GetTransform()->SetPosition(vec);
}

Vec2 PigScene::CreateVerticalTileGroup(Vec2 startVec, TILE tileType, int x, int y, bool isDown, bool isJump = true)
{
	int dirY = isDown ? 1 : -1;
	int vecX = startVec.x;
	for (int i = 0; i < y; ++i) {
		for (int j = 0; j < x; ++j) {
			CreateTile(startVec, tileType);
			startVec.x += 256;
		}
		startVec.x = vecX;
		startVec.y += dirY * 256;
	}
	if (isJump) startVec.y += dirY * 256;
	return startVec;
}

Vec2 PigScene::CreateHorizontalTileGroup(Vec2 startVec, TILE tileType, int x, int y, bool isRight, bool isJump = true)
{
	int dirX = isRight ? 1 : -1;
	int vecY = startVec.y;
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; ++j) {
			CreateTile(startVec, tileType);
			startVec.y -= 256;
		}
		startVec.y = vecY;
		startVec.x += dirX * 256;
	}
	if(isJump) startVec.x += dirX * 256;
	return startVec;
}
