#pragma once
#include "Object.h"
class Scene;
class Camera :
	public Object
{
public:
	Camera();
	~Camera();
	void Update() override;
	void Render(HDC _hdc) override;
public:
	void SetScene(Scene* scene);
private:
	Scene* currentScene;
};

