#pragma once
#include "Scene.h"

enum class TILE
{
	NORMAL,
	TRAP,
	FALL,
};

enum class ATKTRAP
{
	TOWER,
	LAZER,
	FOLLOW,
};

class PigScene :
    public Scene
{
	void Init() override;
	void Render(HDC _hdc) override;
	void CreateTile(Vec2 vec, TILE tileType);
	void CreateTrap(Vec2 vec, ATKTRAP atkTrap);
	Vec2 CreateVerticalTileGroup(Vec2 startVec, TILE tileType, int x, int y, bool isDown, bool isJump); 
	Vec2 CreateHorizontalTileGroup(Vec2 startVec, TILE tileType, int x, int y, bool isRight, bool isJump);
};
