#include "pch.h"
#include "Title.h"
#include "Object.h"
#include "TitleText.h"
#include "TestText.h"

void Title::Init()
{
	TitleText* titleText = new TitleText;
	AddObject(titleText, LAYER::UI);
	titleText->GetTransform()->SetPosition({ SCREEN_WIDTH / 2 , SCREEN_HEIGHT / 4 });
	/*TestText* text = new TestText;
	text->SetText(L"게임이름이 뭔데");
	AddObject(text, LAYER::UI);*/
}
