#pragma once
#include "Component.h"
#include "Texture.h"

class SpriteRenderer :
	public Component
{
public:
	SpriteRenderer();
	virtual ~SpriteRenderer();
public:
	virtual void LateUpdate() override;
	virtual void Render(HDC _hdc) override;
public:
	void CreateTexture(const wstring& _path, const wstring& keyName, Vec2 _size);
private:
	Texture* m_pTex;
	wstring m_pKey;
};

