#pragma once

struct UIPosition
{
	float x;
	float y;
	float width;
	float height;
};

class UIManager
{
	DECLARE_SINGLE(UIManager);
public:
	void Init();
	void Render(HDC _hdc);
public:
	void RenderHP(HDC _hdc);
	void RenderRolling(HDC _hdc);
public:
	float GetHPPercent() { return m_hpPercent; }
	void SetHPPercent(float per) { m_hpPercent = per; }
private:
	UIPosition m_hpPos;
	float m_hpPercent;
};

