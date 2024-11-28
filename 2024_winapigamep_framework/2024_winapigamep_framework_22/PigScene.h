#pragma once
#include "Scene.h"
class PigScene :
    public Scene
{
	void Init() override;
	void CreateTile(Vec2 vec);
	void CreateTrapTile(Vec2 vec);
	Vec2 CreateVerticalTileGroup(Vec2 startVec, int x, int y, bool isDown);
	Vec2 CreateHorizontalTileGroup(Vec2 startVec, int x, int y, bool isRight);
};

