#pragma once
#include "Scene.h"
class BishojoScene :
    public Scene
{
public:
	void Init() override;
	void Render(HDC _hdc) override;
};

