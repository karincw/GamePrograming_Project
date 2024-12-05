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
#include "UIManager.h"
#include "RollingSkillUI.h"
#include "MagicTower.h"
#include "StarLazer.h"
#include "FollowTrap.h"

void PigScene::Init()
{
	CollisionManager* cm = GET_SINGLE(CollisionManager);
	cm->CheckReset();
	cm->CheckLayer(LAYER::TRAP, LAYER::PLAYER);
	cm->CheckLayer(LAYER::PROJECTILE, LAYER::PLAYER);
	cm->CheckLayer(LAYER::BACKGROUND, LAYER::PLAYER);

	RollingSkillUI* rollingSkill = new RollingSkillUI;
	AddObject(rollingSkill, LAYER::UI);

	Agent* agent = new Agent;
	AddObject(agent, LAYER::PLAYER);
	agent->GetTransform()->SetPosition({ SCREEN_WIDTH / 2 , SCREEN_HEIGHT / 2 });


#pragma region Tile Create

	Vec2 tilePos = { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
	tilePos = CreateVerticalTileGroup(tilePos, TILE::NORMAL, 2, 10, false, true);
	tilePos = CreateVerticalTileGroup(tilePos, TILE::NORMAL, 2, 3, false, true);
	tilePos = CreateVerticalTileGroup(tilePos, TILE::NORMAL, 2, 3, false, true);
	tilePos = CreateVerticalTileGroup(tilePos, TILE::NORMAL, 2, 3, false, true);
	tilePos = CreateVerticalTileGroup(tilePos, TILE::NORMAL, 2, 10, false, true);
	CreateTrap({ tilePos.x + 512 , tilePos.y + 2176 }, ATKTRAP::TOWER);
	CreateTrap({ tilePos.x - 256 , tilePos.y + 1664 }, ATKTRAP::TOWER);
	CreateTrap({ tilePos.x + 512 , tilePos.y + 1152 }, ATKTRAP::TOWER);
	CreateTrap({ tilePos.x - 256 , tilePos.y + 640 }, ATKTRAP::TOWER);
	CreateTrap({ tilePos.x + 512 , tilePos.y + 384 }, ATKTRAP::TOWER);
	tilePos = CreateVerticalTileGroup(tilePos, TILE::NORMAL, 2, 2, false, true);
	CreateTrap({ tilePos.x + 512 , tilePos.y + 384 }, ATKTRAP::TOWER);
	tilePos = CreateVerticalTileGroup(tilePos, TILE::NORMAL, 2, 2, false, true);
	CreateTrap({ tilePos.x + 512 , tilePos.y + 384 }, ATKTRAP::TOWER);
	tilePos = CreateHorizontalTileGroup(tilePos, TILE::NORMAL, 8, 2, true, true);
	tilePos.x -= 640;
	tilePos.y += 384;
	// Boom Trap
	tilePos = CreateVerticalTileGroup(tilePos, TILE::NORMAL, 2, 4, true, true);
	CreateTile({ tilePos.x, tilePos.y - 1152 }, TILE::TRAP);
	CreateTile({ tilePos.x + 256, tilePos.y - 896 }, TILE::TRAP);
	CreateTile({ tilePos.x, tilePos.y - 640 }, TILE::TRAP);
	CreateTile({ tilePos.x + 256, tilePos.y - 384 }, TILE::TRAP);
	tilePos = CreateVerticalTileGroup(tilePos, TILE::TRAP, 2, 1, true, false);
	CreateTrap(tilePos, ATKTRAP::FOLLOW);
	tilePos = CreateVerticalTileGroup(tilePos, TILE::NORMAL, 2, 3, true, true);
	tilePos = CreateVerticalTileGroup(tilePos, TILE::NORMAL, 2, 2, true, false);
	// Fall Tile
	CreateTrap({ tilePos.x + 512, tilePos.y }, ATKTRAP::TOWER);
	CreateTrap({ tilePos.x - 256, tilePos.y + 256 }, ATKTRAP::TOWER);
	CreateTrap({ tilePos.x + 512, tilePos.y + 512 }, ATKTRAP::TOWER);
	CreateTrap({ tilePos.x - 256, tilePos.y + 768 }, ATKTRAP::TOWER);
	tilePos = CreateVerticalTileGroup(tilePos, TILE::FALL, 2, 4, true, true);
	tilePos = CreateVerticalTileGroup(tilePos, TILE::FALL, 2, 2, true, true);
	tilePos = CreateVerticalTileGroup(tilePos, TILE::FALL, 2, 2, true, true);
	tilePos = CreateVerticalTileGroup(tilePos, TILE::FALL, 2, 2, true, false);
	tilePos.x += 640;
	tilePos.y -= 256;
	tilePos = CreateHorizontalTileGroup(tilePos, TILE::NORMAL, 2, 2, true, false);
	tilePos = CreateHorizontalTileGroup(tilePos, TILE::NORMAL, 2, 1, true, false);
	tilePos = CreateHorizontalTileGroup({ tilePos .x - 512, tilePos.y-256 }, TILE::FALL, 2, 1, true, false);
	tilePos.y += 256;
	// Cross
	Vec2 tilePos2 = { tilePos.x - 256, tilePos.y - 512 };
	tilePos2 = CreateVerticalTileGroup(tilePos2, TILE::NORMAL, 2, 3, false, false);
	tilePos2.y += 512;
	tilePos2.x += 512;
	CreateTile({ tilePos2.x - 256, tilePos2.y -256}, TILE::TRAP);
	CreateTile( tilePos2, TILE::TRAP);
	CreateTrap( { tilePos2.x+512, tilePos2.y+256 }, ATKTRAP::TOWER);
	CreateTrap( { tilePos2.x+768, tilePos2.y+256 }, ATKTRAP::TOWER);
	CreateTrap( { tilePos2.x+1280, tilePos2.y+256 }, ATKTRAP::TOWER);
	CreateTrap( { tilePos2.x+1536, tilePos2.y+256 }, ATKTRAP::TOWER);
	CreateTile({ tilePos2.x + 768, tilePos2.y }, TILE::TRAP);
	CreateVerticalTileGroup({ tilePos2.x + 1024, tilePos2.y }, TILE::TRAP, 1, 2, false, false);
	tilePos2 = CreateHorizontalTileGroup(tilePos2, TILE::NORMAL, 10, 2, true, false);
	CreateTile({ tilePos2.x - 512, tilePos2.y }, TILE::TRAP);
	tilePos2.y -= 256;
	tilePos2 = CreateVerticalTileGroup(tilePos2, TILE::NORMAL, 2, 5, true, false);
	tilePos2.y -= 768;
	tilePos2.x += 512;
	tilePos2 = CreateHorizontalTileGroup(tilePos2, TILE::NORMAL, 2, 2, true, false);

	CreateTile({ tilePos.x + 512, tilePos.y - 256 }, TILE::TRAP);
	CreateTile({ tilePos.x + 768, tilePos.y }, TILE::TRAP);
	CreateHorizontalTileGroup({ tilePos.x + 1280, tilePos.y }, TILE::TRAP, 2, 1, true, false);
	CreateTrap({ tilePos.x + 256, tilePos.y + 256 }, ATKTRAP::TOWER);
	CreateTrap({ tilePos.x + 512, tilePos.y + 256 }, ATKTRAP::TOWER);
	CreateTrap({ tilePos.x + 1280, tilePos.y + 256 }, ATKTRAP::TOWER);
	CreateTrap({ tilePos.x + 1536, tilePos.y + 256 }, ATKTRAP::TOWER);
	tilePos = CreateHorizontalTileGroup(tilePos, TILE::NORMAL, 11, 2, true, false);
	CreateTrap({ tilePos.x - 768, tilePos.y + 256 }, ATKTRAP::TOWER);
	CreateTrap({ tilePos.x - 512, tilePos.y + 256 }, ATKTRAP::TOWER);
	CreateHorizontalTileGroup({ tilePos.x -256, tilePos.y - 256 }, TILE::TRAP, 2, 1, false, false);
	CreateTile({ tilePos.x + 256, tilePos.y}, TILE::TRAP);
	tilePos.x += 512;
	tilePos = CreateHorizontalTileGroup(tilePos, TILE::NORMAL, 2, 2, true, false);
	tilePos.y -= 256;
	tilePos = CreateHorizontalTileGroup(tilePos, TILE::NORMAL, 2, 2, true, false);
	tilePos.x += 128;
	tilePos.y -= 128;
	tilePos = CreateHorizontalTileGroup(tilePos, TILE::NORMAL, 1, 1, true, true);
	CreateTrap({ tilePos.x, tilePos.y- 384}, ATKTRAP::LAZER);
	tilePos = CreateHorizontalTileGroup(tilePos, TILE::NORMAL, 1, 1, true, true);
	tilePos = CreateVerticalTileGroup(tilePos, TILE::NORMAL, 1, 1, false, true);
	tilePos = CreateVerticalTileGroup(tilePos, TILE::FALL, 1, 1, false, true);
	tilePos = CreateHorizontalTileGroup(tilePos, TILE::FALL, 1, 1, false, true);
	tilePos = CreateHorizontalTileGroup(tilePos, TILE::FALL, 1, 1, false, true);
	tilePos = CreateVerticalTileGroup(tilePos, TILE::FALL, 1, 1, false, true);
	tilePos = CreateVerticalTileGroup(tilePos, TILE::FALL, 1, 1, false, true);
	tilePos = CreateHorizontalTileGroup(tilePos, TILE::TRAP, 1, 1, true, true);
	CreateTrap({ tilePos.x, tilePos.y + 384}, ATKTRAP::LAZER);
	tilePos = CreateHorizontalTileGroup(tilePos, TILE::TRAP, 1, 1, true, true);
	tilePos = CreateHorizontalTileGroup(tilePos, TILE::TRAP, 1, 1, true, true);
	tilePos = CreateHorizontalTileGroup(tilePos, TILE::NORMAL, 1, 1, true, true);
	tilePos = CreateHorizontalTileGroup(tilePos, TILE::NORMAL, 8, 1, true, false);

#pragma endregion

	CreateTile({ 256, 0 }, TILE::FALL);
}

void PigScene::Render(HDC _hdc)
{
	Scene::Render(_hdc);
	GET_SINGLE(UIManager)->RenderHP(_hdc);
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

void PigScene::CreateTrap(Vec2 vec, ATKTRAP atkTrap)
{
	Object* trap = nullptr;
	switch (atkTrap) {
	case ATKTRAP::TOWER:
		trap = new MagicTower(1);
		AddObject(trap, LAYER::TRAP);
		break;
	case ATKTRAP::LAZER:
		trap = new StarLazer(vec);
		AddObject(trap, LAYER::TRAP);
		break;
	case ATKTRAP::FOLLOW:
		trap = new FollowTrap();
		AddObject(trap, LAYER::TRAP);
		break;
	}

	trap->GetTransform()->SetPosition(vec);
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
	if (isJump) startVec.y += dirY * 128;
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
	if(isJump) startVec.x += dirX * 128;
	return startVec;
}
