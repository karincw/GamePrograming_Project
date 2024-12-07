#include "pch.h"
#include "Title.h"
#include "Object.h"
#include "TitleText.h"
#include "TestText.h"
#include "CollisionManager.h"
#include "PlayButton.h"
#include "ExitButton.h"
#include "DirectionArrow.h"
#include "Background.h"

void Title::Init()
{
	CollisionManager* cm = GET_SINGLE(CollisionManager);
	cm->CheckReset();
	cm->CheckLayer(LAYER::UI, LAYER::UI);

	TitleText* titleText = new TitleText;
	AddObject(titleText, LAYER::UI);

	DirectionArrow* arrow = new DirectionArrow;
	AddObject(arrow, LAYER::UI);

	PlayButton* play = new PlayButton;
	AddObject(play, LAYER::UI);

	ExitButton* exit = new ExitButton;
	AddObject(exit, LAYER::UI);

	Background* background = new Background;
	AddObject(background, LAYER::BACKGROUND);
}
