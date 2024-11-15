#include "pch.h"
#include "SpriteRenderer.h"
#include "ResourceManager.h"
#include "Object.h"

SpriteRenderer::SpriteRenderer()
	:m_pTex(nullptr),
	m_pKey(L"")
{

}

SpriteRenderer::~SpriteRenderer()
{

}

void SpriteRenderer::LateUpdate()
{
}

void SpriteRenderer::Render(HDC _hdc)
{
	if (m_pTex == nullptr) return;

	Vec2 vPos = m_pOwner->GetPos();
	Vec2 vSize = m_pOwner->GetSize();
	int width = m_pTex->GetWidth();
	int height = m_pTex->GetHeight();

	::BitBlt(_hdc
		, (int)(vPos.x - vSize.x / 2)
		, (int)(vPos.y - vSize.y / 2)
		, width, height,
		m_pTex->GetTexDC()
		, 0, 0, SRCCOPY
	);
}

void SpriteRenderer::CreateTexture(const wstring& _path, const wstring& keyName, Vec2 _size)
{
	m_pTex = GET_SINGLE(ResourceManager)->TextureLoad(keyName, _path);
	m_pKey = keyName;
}
