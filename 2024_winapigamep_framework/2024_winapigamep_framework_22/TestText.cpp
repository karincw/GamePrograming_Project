#include "pch.h"
#include "TestText.h"

TestText::TestText()
{

}

TestText::~TestText()
{
}

void TestText::Update()
{
}

void TestText::Render(HDC _hdc)
{
	HFONT hFont = CreateFont(
		48, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE,
		ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, L"Arial"
	);

	SelectObject(_hdc, hFont);

	SetTextColor(_hdc, RGB(255, 0, 0));
	SetBkMode(_hdc, TRANSPARENT);
	TextOut(_hdc, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 4, text.c_str(), static_cast<int>(text.length()));
}

void TestText::EnterCollision(Collider* _other)
{
}

void TestText::StayCollision(Collider* _other)
{
}

void TestText::ExitCollision(Collider* _other)
{
}
