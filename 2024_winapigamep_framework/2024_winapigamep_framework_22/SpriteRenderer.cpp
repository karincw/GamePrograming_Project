#include "pch.h"
#include "SpriteRenderer.h"
#include "ResourceManager.h"
#include "Object.h"
#include "Transform.h"
#include "Texture.h"
SpriteRenderer::SpriteRenderer()
	:m_pTex(nullptr),
	m_pKey(L""),
	isStretchBlt(true)
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
	Transform* trm = m_pOwner->GetComponent<Transform>();
	Vec2 vPos = trm->GetPosition();
	Vec2 vSize = trm->GetScale();
	int width = m_pTex->GetWidth();
	int height = m_pTex->GetHeight();

	::BitBlt(_hdc
		, (int)(vPos.x - vSize.x / 2), (int)(vPos.y - vSize.y / 2), width, height,
		m_pTex->GetTexDC()
		, 0, 0, SRCCOPY
	);

}

void SpriteRenderer::CreateTexture(const wstring& _path, const wstring& keyName)
{
	m_pTex = GET_SINGLE(ResourceManager)->TextureLoad(keyName, _path);
	m_pKey = keyName;

	Object* pObj = GetOwner();
	Transform* trm = pObj->GetComponent<Transform>();
	Vec2 scale = trm->GetScale();
	float ratioX = scale.x / m_pTex->GetWidth();
	float ratioY = scale.y / m_pTex->GetHeight();

	m_pTex = m_pTex->MakeStretchTex(ratioX, ratioY);
}


Texture* SpriteRenderer::GetTexture()
{
	return m_pTex;
}
