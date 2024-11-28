#include "pch.h"
#include "Scene.h"
#include "Object.h"
#include "CollisionManager.h"
#include "Camera.h"
#include "SceneManager.h"
#include "Scene.h"
#include "Camera.h"

Scene::Scene()
{
	Camera* cam = new Camera;
	currentCamera = cam;
	cam->SetScene(this);
}

Scene::~Scene()
{
	Release();
}

void Scene::Update()
{
	//for (UINT i = 0; i < (UINT)LAYER::END; ++i)
	//{
	//	for (size_t j = 0; j < m_vecObj[i].size();)
	//	{
	//		if (!m_vecObj[i][j]->GetIsDead())
	//			m_vecObj[i][j++]->Update();
	//		else
	//			m_vecObj[i].erase(m_vecObj[i].begin() + j);
	//	}
	//}
	for (UINT i = 0; i < (UINT)LAYER::END; ++i)
	{
		for (size_t j = 0; j < m_vecObj[i].size(); ++j)
		{
			if (!m_vecObj[i][j]->GetIsDead())
				m_vecObj[i][j]->Update();
		}
	}


}

void Scene::LateUpdate()
{
	for (size_t i = 0; i < (UINT)LAYER::END; i++)
	{
		for (UINT j = 0; j < m_vecObj[i].size(); ++j)
		{
			m_vecObj[i][j]->LateUpdate();
		}
	}
}

void Scene::Render(HDC _hdc)
{
	//for (UINT i = 0; i < (UINT)LAYER::END; ++i)
	//{
	//	for (size_t j = 0; j < m_vecObj[i].size(); ++j)
	//	{
	//		if (!m_vecObj[i][j]->GetIsDead())
	//			m_vecObj[i][j]->Render(_hdc);
	//	}
	//}
	for (UINT i = 0; i < (UINT)LAYER::END; ++i)
	{
		for (size_t j = 0; j < m_vecObj[i].size();)
		{
			Object* nowObj = m_vecObj[i][j];

			if (!nowObj->GetIsDead())
			{
				bool Render = true;
				Vec2 CamPos = GET_SINGLE(SceneManager)->GetCurrentScene()->GetCamera()->GetWorldPosition();
				Vec2 LeftTop = { CamPos.x - SCREEN_WIDTH / 2, CamPos.y - SCREEN_WIDTH / 2 };
				Vec2 RightBottom = { CamPos.x + SCREEN_WIDTH / 2, CamPos.y + SCREEN_HEIGHT / 2 };
				Transform* trm = nowObj->GetTransform();
				Vec2 position = trm->GetPosition();
				Vec2 scale = trm->GetScale();

				if (position.x + scale.x * 2 < LeftTop.x)
					Render = false;
				else if (position.x - scale.x * 2 > RightBottom.x)
					Render = false;
				else if (position.y + scale.y * 2 < LeftTop.y)
					Render = false;
				else if (position.y - scale.y * 2 > RightBottom.y)
					Render = false;

				if (Render)
					m_vecObj[i][j]->Render(_hdc);

				j++;
			}
			else
			{
				m_vecObj[i].erase(m_vecObj[i].begin() + j);
			}
		}
	}

}

void Scene::Release()
{
	// 오브젝트 삭제.
	for (size_t i = 0; i < (UINT)LAYER::END; i++)
	{
		for (UINT j = 0; j < m_vecObj[i].size(); ++j)
		{
			delete m_vecObj[i][j];
		}
		m_vecObj[i].clear();
	}
	GET_SINGLE(CollisionManager)->CheckReset();
	delete currentCamera;
}