#include "pch.h"
#include "CollisionManager.h"
#include "SceneManager.h"
#include "Scene.h"
#include "Object.h"
#include "Collider.h"
#include "CircleCollider.h"
void CollisionManager::Update()
{
	for (UINT Row = 0; Row < (UINT)LAYER::END; ++Row)
	{
		for (UINT Col = Row; Col < (UINT)LAYER::END; ++Col)
		{
			if (m_arrLayer[Row] & (1 << Col))
			{
				//int a = 0;
				CollisionLayerUpdate((LAYER)Row, (LAYER)Col);
			}
		}
	}
}

void CollisionManager::CheckLayer(LAYER _left, LAYER _right)
{
	// �������� ������ ���ô�.
	// ���� ���� LAYER�� ������, ū ���� ��
	UINT Row = (UINT)_left;
	UINT Col = (UINT)_right;
	//Row = min(Row, Col);
	if (Row > Col)
		std::swap(Row, Col);
	//m_arrLayer[Row];
	//Col;

	//// ��Ʈ ����
	// üũ�� �Ǿ��ִٸ�
	if (m_arrLayer[Row] & (1 << Col))
	{
		// üũ Ǯ��
		m_arrLayer[Row] &= ~(1 << Col);
	}
	// üũ�� �ȵǾ��ִٸ�r
	else
	{
		m_arrLayer[Row] |= (1 << Col);
	}
	int a = 0;
}

void CollisionManager::CheckReset()
{
	// �޸� �ʱ�ȭ
	memset(m_arrLayer, 0, sizeof(UINT) * (UINT)LAYER::END);
}
void CollisionManager::CollisionLayerUpdate(LAYER _left, LAYER _right)
{
	std::shared_ptr<Scene> pCurrentScene = GET_SINGLE(SceneManager)->GetCurrentScene();
	const vector<Object*>& vecLeftLayer = pCurrentScene->GetLayerObjects(_left);
	const vector<Object*>& vecRightLayer = pCurrentScene->GetLayerObjects(_right);
	map<ULONGLONG, bool>::iterator iter;
	for (size_t i = 0; i < vecLeftLayer.size(); ++i)
	{
		std::vector<Collider*> pLeftColliders = vecLeftLayer[i]->GetComponents<Collider>();
		// �浹ü ���� ���
		if (pLeftColliders.empty())
			continue;

		for (size_t j = 0; j < vecRightLayer.size(); j++)
		{
			std::vector<Collider*> pRightColliders = vecRightLayer[j]->GetComponents<Collider>();
			// �浹ü�� ���ų�, �ڱ��ڽŰ��� �浹�� ���
			if (pRightColliders.empty() || vecLeftLayer[i] == vecRightLayer[j])
				continue;

			COLLIDER_ID colliderID; // �� �浹ü�θ� ���� �� �ִ� ID

			for (auto leftCol : pLeftColliders)
			{
				for (auto rightCol : pRightColliders)
				{
					colliderID.left_ID = leftCol->GetID();
					colliderID.right_ID = rightCol->GetID();

					iter = m_mapCollisionInfo.find(colliderID.ID);
					// ���� ������ �浹�� �� ����.
					if (iter == m_mapCollisionInfo.end())
					{
						// �浹 ������ �̵�ϵ� ������ ��� ���(�浹���� �ʾҴٷ�)
						m_mapCollisionInfo.insert({ colliderID.ID, false });
						//m_mapCollisionInfo[colliderID.ID] = false;
						iter = m_mapCollisionInfo.find(colliderID.ID);
					}

					if (IsCollision(leftCol, rightCol))
					{
						// �������� �浹��
						if (iter->second)
						{
							if (vecLeftLayer[i]->GetIsDead() || vecRightLayer[j]->GetIsDead())
							{
								leftCol->ExitCollision(rightCol);
								rightCol->ExitCollision(leftCol);
								iter->second = false;
							}
							else
							{
								leftCol->StayCollision(rightCol);
								rightCol->StayCollision(leftCol);
							}
						}
						else // ������ �浹 x
						{
							if (!vecLeftLayer[i]->GetIsDead() && !vecRightLayer[j]->GetIsDead())
							{
								leftCol->EnterCollision(rightCol);
								rightCol->EnterCollision(leftCol);
								iter->second = true;
							}
						}
					}
					else // �浹 ���ϳ�?
					{
						if (iter->second) // �ٵ� ������ �浹��
						{
							leftCol->ExitCollision(rightCol);
							rightCol->ExitCollision(leftCol);
							iter->second = false;
						}
					}
				}
			}
		}
	}
}

bool CollisionManager::IsCollision(Collider* _left, Collider* _right)
{
	CircleCollider* circleLeft = dynamic_cast<CircleCollider*>(_left);
	CircleCollider* circleRight = dynamic_cast<CircleCollider*>(_right);

	if (circleLeft != nullptr && circleRight != nullptr) // �Ѵ� ��
	{
		float maxDist = max(circleLeft->GetRadius(), circleRight->GetRadius());
		auto leftPos = circleLeft->GetOwner()->GetTransform()->GetPosition();
		auto rightPos = circleRight->GetOwner()->GetTransform()->GetPosition();
		auto len = leftPos - rightPos;
		if (maxDist >= len.Length())
		{
			return true;
		}
	}
	else if (circleLeft != nullptr || circleRight != nullptr) // �ϳ��� ��
	{
		bool leftIsCircle = circleLeft != nullptr ? true : false;
		Object* square = leftIsCircle ? _right->GetOwner() : _left->GetOwner();
		Object* circle = leftIsCircle ? _left->GetOwner() : _right->GetOwner();

		Vec2 rectPos = square->GetTransform()->GetPosition() + square->GetComponent<Collider>()->GetOffSetPos();
		Vec2 rectSize = square->GetComponent<Collider>()->GetSize();
		Vec2 circlePos = circle->GetTransform()->GetPosition() + circle->GetComponent<CircleCollider>()->GetOffSetPos();
		float circleRad = circleLeft->GetRadius();

		// 2. �簢���� ��踦 ���ؿð̴ϴ�.
		float left = rectPos.x - (rectSize.x / 2);
		float right = rectPos.x + (rectSize.x / 2);
		float top = rectPos.y - (rectSize.y / 2);
		float bottom = rectPos.y + (rectSize.y / 2);

		// �浹üũ�� ���� ���尡��� ���� �����ðž�.
		float closestX = std::clamp(circlePos.x, left, right);
		float closestY = std::clamp(circlePos.y, top, bottom);

		float dx = circlePos.x - closestX;
		float dy = circlePos.y - closestY;
		float dist = sqrt(dx * dx + dy * dy);

		if (dist <= circleRad)
			return true;
	}
	else //�Ѵ� �׸�
	{
		Vec2 vLeftPos = _left->GetLatedUpatedPos();
		Vec2 vRightPos = _right->GetLatedUpatedPos();
		Vec2 vLeftSize = _left->GetSize();
		Vec2 vRightSize = _right->GetSize();

		RECT leftRt = RECT_MAKE(vLeftPos.x, vLeftPos.y, vLeftSize.x, vLeftSize.y);
		RECT rightRt = RECT_MAKE(vRightPos.x, vRightPos.y, vRightSize.x, vRightSize.y);
		RECT rt;
		return ::IntersectRect(&rt, &leftRt, &rightRt);
	}
	return false;

}
