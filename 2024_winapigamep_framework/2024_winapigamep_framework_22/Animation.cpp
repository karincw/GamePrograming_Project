#include "pch.h"
#include "Animation.h"
#include "Animator.h"
#include "Object.h"
#include "Texture.h"
#include "TimeManager.h"
#include "Transform.h"
Animation::Animation()
	: m_pAnimator(nullptr)
	, m_CurFrame(0)
	, m_pTex(nullptr)
	, m_fAccTime(0.f)
	, m_reSizeRatio(0.f)
	, m_PostProcessingDC()
	, m_PostProcessingBitMap()
	, m_PostProcessingBitInfo{}
{
}

Animation::~Animation()
{
	::DeleteDC(m_PostProcessingDC);
	::DeleteObject(m_PostProcessingBitMap);
}

void Animation::Update()
{
	if (m_pAnimator->GetRepeatcnt() <= 0)
	{
		m_CurFrame = m_vecAnimFrame.size() - 1;
		return;
	}
	m_fAccTime += fDT;
	// 누적한 시간이 내가 이 프레임에 진행한 시간을 넘어섰냐?
	if (m_fAccTime >= m_vecAnimFrame[m_CurFrame].fDuration)
	{
		// 일단 모은 시간에서 현재 진행한 시간을 빼고
		m_fAccTime -= m_vecAnimFrame[m_CurFrame].fDuration;
		++m_CurFrame; // 다음프레임으로 옮기기
		if (m_CurFrame >= m_vecAnimFrame.size()) // 한바퀴 돌게하고싶어
		{
			if (!m_pAnimator->GetRepeat())
				m_pAnimator->SetRepeatcnt();
			m_CurFrame = 0;
			m_fAccTime = 0.f;
		}

	}
}

void Animation::Render(HDC _hdc)
{
	Object* pObj = m_pAnimator->GetOwner();
	Transform* trm = pObj->GetComponent<Transform>();
	Vec2 position = trm->GetPosition();
	Vec2 scale = trm->GetScale();
	// 오프셋 적용
	position = position + m_vecAnimFrame[m_CurFrame].vOffset;

	//TransparentBlt(m_PostProcessingDC
	//	, 0, 0
	//	, m_pTex->GetWidth(), m_pTex->GetHeight()
	//	, m_pTex->GetTexDC()
	//	, 0, 0
	//	, m_pTex->GetWidth(), m_pTex->GetHeight()
	//	, RGB(255, 0, 255)
	//);

	//StretchBlt(_hdc
	////StretchBlt(m_PostProcessingDC
	//	, 0
	//	, 0
	//	, m_pTex->GetWidth() * m_reSizeRatio
	//	, m_pTex->GetHeight() * m_reSizeRatio
	//	, m_pTex->GetTexDC()
	//	, 0
	//	, 0
	//	, (m_pTex->GetWidth())
	//	, (m_pTex->GetHeight())
	//	, SRCCOPY
	//); //리사이즈
	

	TransparentBlt(_hdc
		, (int)(position.x - scale.x / 2)
		, (int)(position.y - scale.y / 2)
		, scale.x
		, scale.y
		, m_PostProcessingDC
		, (int)(m_vecAnimFrame[m_CurFrame].vLT.x * m_reSizeRatio)
		, (int)(m_vecAnimFrame[m_CurFrame].vLT.y * m_reSizeRatio)
		, (int)(m_vecAnimFrame[m_CurFrame].vSlice.x * m_reSizeRatio)
		, (int)(m_vecAnimFrame[m_CurFrame].vSlice.y * m_reSizeRatio)
		, RGB(255, 0, 255));
	//실질적 그리기


}

void Animation::Create(Texture* _pTex, Vec2 _vLT, Vec2 _vSliceSize, Vec2 _vStep, int _framecount, float _fDuration, bool _isRotate)
{
	Object* pObj = m_pAnimator->GetOwner();
	Transform* trm = pObj->GetComponent<Transform>();
	Vec2 position = trm->GetPosition();
	Vec2 scale = trm->GetScale();
	m_reSizeRatio = scale.x / _vSliceSize.x;

	m_pTex = _pTex;
	m_PostProcessingDC = CreateCompatibleDC(m_pTex->GetTexDC());
	m_PostProcessingBitMap = CreateCompatibleBitmap(m_pTex->GetTexDC()
		, m_pTex->GetWidth() * m_reSizeRatio, m_pTex->GetHeight() * m_reSizeRatio);
	SelectObject(m_PostProcessingDC, m_PostProcessingBitMap);
	::GetObject(m_PostProcessingBitMap, sizeof(BITMAP), &m_PostProcessingBitInfo);

	//m_reSizeRatio = _vSliceSize.x / scale.x;

	//StretchBlt(_hdc
	StretchBlt(m_PostProcessingDC
		, 0
		, 0
		, m_pTex->GetWidth() * m_reSizeRatio
		, m_pTex->GetHeight() * m_reSizeRatio
		, m_pTex->GetTexDC()
		, 0
		, 0
		, (m_pTex->GetWidth())
		, (m_pTex->GetHeight())
		, SRCCOPY
	); //리사이즈

	m_IsRotate = _isRotate;
	for (int i = 0; i < _framecount; ++i)
	{
		m_vecAnimFrame.push_back(tAnimFrame({ _vLT + _vStep * i,
			_vSliceSize, _fDuration,{0.f,0.f} }));
	}
}
