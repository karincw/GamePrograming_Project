#include "pch.h"
#include "UIManager.h"
#include "RenderUtils.h"

void UIManager::Init()
{
	m_hpPercent = 100.f;

	m_hpPos = { 472.5f / 800 * SCREEN_WIDTH,
		((538.0f - 50.0f) + (568.0f - 50.0f)) / 2 / 600 * SCREEN_HEIGHT,
		415.0f / 800 * SCREEN_WIDTH,
		30.0f / 600 * SCREEN_HEIGHT };
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
