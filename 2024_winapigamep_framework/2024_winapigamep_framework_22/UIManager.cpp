#include "pch.h"
#include "UIManager.h"
#include "RenderUtils.h"

void UIManager::Init()
{
	m_hpPercent = 100.f;

	m_hpPos = 
	{ 
		SCREEN_WIDTH / 3 * 2.3f,
		SCREEN_HEIGHT - 50,
		SCREEN_WIDTH / 3,
		30
	};
}

void UIManager::Render(HDC _hdc)
{
	RenderHP(_hdc);
}

void UIManager::RenderHP(HDC _hdc)
{
	Vec2 pos = { m_hpPos.x, m_hpPos.y };
	RenderUtils::RenderRect(_hdc, pos, m_hpPos.width, m_hpPos.height);

	// 스테미나 너비를 m_hpPos.width 기반으로 계산
	float width = m_hpPos.width * (m_hpPercent / 100.0f);

	// 파워 바를 left부터 채우기 위해 pos.x를 왼쪽 끝으로 이동
	Vec2 leftPos = { m_hpPos.x - m_hpPos.width / 2 + width / 2, m_hpPos.y };
	HBRUSH brush = ::CreateSolidBrush(RGB(157, 2, 37));
	HBRUSH oldBrush = (HBRUSH)::SelectObject(_hdc, brush);

	RenderUtils::RenderRect(_hdc, leftPos, width, m_hpPos.height);

	::SelectObject(_hdc, oldBrush);
	::DeleteObject(brush);
}

void UIManager::RenderRolling(HDC _hdc)
{
}
