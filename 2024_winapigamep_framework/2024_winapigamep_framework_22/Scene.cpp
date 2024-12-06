#include "pch.h"
#include "Scene.h"
#include "Object.h"
#include "CollisionManager.h"
#include "Camera.h"
#include "SceneManager.h"

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
	for (UINT i = 0; i < (UINT)LAYER::END; ++i)
	{
		for (size_t j = 0; j < m_vecObj[i].size(); ++j)
		{
			Object* nowObj = m_vecObj[i][j];

			if (!nowObj->GetIsDead())
			{
				bool state = true;
				Vec2 CamPos = GET_SINGLE(SceneManager)->GetCurrentScene()->GetCamera()->GetWorldPosition();
				Vec2 LeftTop = { CamPos.x - SCREEN_WIDTH / 2, CamPos.y - SCREEN_WIDTH / 2 };
				Vec2 RightBottom = { CamPos.x + SCREEN_WIDTH / 2, CamPos.y + SCREEN_HEIGHT / 2 };
				Transform* trm = nowObj->GetTransform();
				Vec2 position = trm->GetPosition();
				Vec2 scale = trm->GetScale();

				if (position.x + SCREEN_WIDTH / 2 < LeftTop.x)
					state = false;
				else if (position.x - SCREEN_WIDTH / 2 > RightBottom.x)
					state = false;
				else if (position.y + SCREEN_HEIGHT / 2 < LeftTop.y)
					state = false;
				else if (position.y - SCREEN_HEIGHT / 2 > RightBottom.y)
					state = false;

				if (state)
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

			bool Render = true;
			Vec2 CamPos = GET_SINGLE(SceneManager)->GetCurrentScene()->GetCamera()->GetWorldPosition();
			Vec2 LeftTop = { CamPos.x - SCREEN_WIDTH / 2, CamPos.y - SCREEN_WIDTH / 2 };
			Vec2 RightBottom = { CamPos.x + SCREEN_WIDTH / 2, CamPos.y + SCREEN_HEIGHT / 2 };
			Transform* trm = nowObj->GetTransform();
			Vec2 position = trm->GetPosition();
			Vec2 scale = trm->GetScale();

			if (position.x + SCREEN_WIDTH / 2 < LeftTop.x)
				Render = false;
			else if (position.x - SCREEN_WIDTH / 2 > RightBottom.x)
				Render = false;
			else if (position.y + SCREEN_HEIGHT / 2 < LeftTop.y)
				Render = false;
			else if (position.y - SCREEN_HEIGHT / 2 > RightBottom.y)
				Render = false;

			if (Render)
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
				bool Render = true;
				Vec2 CamPos = GET_SINGLE(SceneManager)->GetCurrentScene()->GetCamera()->GetWorldPosition();
				Vec2 LeftTop = { CamPos.x - SCREEN_WIDTH / 2, CamPos.y - SCREEN_WIDTH / 2 };
				Vec2 RightBottom = { CamPos.x + SCREEN_WIDTH / 2, CamPos.y + SCREEN_HEIGHT / 2 };
				Transform* trm = nowObj->GetTransform();
				Vec2 position = trm->GetPosition();
				Vec2 scale = trm->GetScale();

				if (position.x + SCREEN_WIDTH / 2 < LeftTop.x)
					Render = false;
				else if (position.x - SCREEN_WIDTH / 2 > RightBottom.x)
					Render = false;
				else if (position.y + SCREEN_HEIGHT / 2 < LeftTop.y)
					Render = false;
				else if (position.y - SCREEN_HEIGHT / 2 > RightBottom.y)
					Render = false;

				if (Render)
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
	for (size_t i = 0; i < (UINT)LAYER::END; i++)
	{
		for (UINT j = 0; j < m_vecObj[i].size(); ++j)
		{
			delete m_vecObj[i][j];
		}
		m_vecObj[i].clear();
	}
	GET_SINGLE(CollisionManager)->CheckReset();
}