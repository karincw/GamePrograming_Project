#include "pch.h"
#include "Scene.h"
#include "Object.h"
#include "CollisionManager.h"
#include "Camera.h"
#include "SceneManager.h"

Scene::Scene()
	:m_vecObj{}
{
	currentCamera = new Camera;
	currentCamera->SetScene(this);
}

Scene::~Scene()
{
	Release();
}

bool IsInWindow(Transform* trm)
{
	auto currentScene = GET_SINGLE(SceneManager)->GetCurrentScene();
	if (currentScene == nullptr || currentScene->GetCamera() == nullptr)
		return false;

	Vec2 CamPos = currentScene->GetCamera()->GetWorldPosition();
	bool State = true;
	Vec2 LeftTop = { CamPos.x - SCREEN_WIDTH / 2, CamPos.y - SCREEN_WIDTH / 2 };
	Vec2 RightBottom = { CamPos.x + SCREEN_WIDTH / 2, CamPos.y + SCREEN_HEIGHT / 2 };
	Vec2 position = trm->GetPosition();
	Vec2 scale = trm->GetScale();

	if (position.x + SCREEN_WIDTH / 2 < LeftTop.x)
		State = false;
	else if (position.x - SCREEN_WIDTH / 2 > RightBottom.x)
		State = false;
	else if (position.y + SCREEN_HEIGHT / 2 < LeftTop.y)
		State = false;
	else if (position.y - SCREEN_HEIGHT / 2 > RightBottom.y)
		State = false;

	return State;
}

void Scene::Update()
{
	for (UINT i = 0; i < (UINT)LAYER::END; ++i)
	{
		for (size_t j = 0; j < m_vecObj[i].size(); ++j)
		{
			Object* nowObj = m_vecObj[i][j];

			if (!nowObj->GetIsDead())
			{
				if (IsInWindow(nowObj->GetTransform()))
					m_vecObj[i][j]->Update();
			}
		}
	}


}

void Scene::LateUpdate()
{
	for (size_t i = 0; i < (UINT)LAYER::END; i++)
	{
		for (UINT j = 0; j < m_vecObj[i].size(); ++j)
		{
			Object* nowObj = m_vecObj[i][j];
			if (IsInWindow(nowObj->GetTransform()))
				m_vecObj[i][j]->LateUpdate();
		}
	}
}

void Scene::Render(HDC _hdc)
{
	for (UINT i = 0; i < (UINT)LAYER::END; ++i)
	{
		for (size_t j = 0; j < m_vecObj[i].size();)
		{
			Object* nowObj = m_vecObj[i][j];

			if (!nowObj->GetIsDead())
			{
				if (IsInWindow(nowObj->GetTransform()))
					m_vecObj[i][j]->Render(_hdc);

				j++;
			}
			else
			{
				if (nowObj->GetDieToDelete())
					delete nowObj;
				m_vecObj[i].erase(m_vecObj[i].begin() + j);
			}
		}
	}

}

void Scene::Release()
{
	delete currentCamera;
	currentCamera = nullptr; // �����ϰ� �ʱ�ȭ

	for (UINT i = 0; i < (UINT)LAYER::END; i++)
	{
		for (UINT j = 0; j < m_vecObj[i].size(); ++j)
		{
			delete m_vecObj[i][j];
			m_vecObj[i][j] = nullptr; // nullptr�� �ʱ�ȭ
		}
		m_vecObj[i].clear();
	}

	GET_SINGLE(CollisionManager)->CheckReset();
}