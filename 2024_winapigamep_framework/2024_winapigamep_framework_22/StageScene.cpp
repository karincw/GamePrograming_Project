#include "pch.h"
#include "StageScene.h"
#include "Object.h"
#include "Agent.h"

void StageScene::Init()
{
	Object* testObj = new Agent;
	AddObject(testObj, LAYER::DEFAULT);
}
