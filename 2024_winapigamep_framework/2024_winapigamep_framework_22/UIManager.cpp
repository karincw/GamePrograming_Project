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

	// ���׹̳� �ʺ� m_hpPos.width ������� ���
	float width = m_hpPos.width * (m_hpPercent / 100.0f);

	// �Ŀ� �ٸ� left���� ä��� ���� pos.x�� ���� ������ �̵�
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
