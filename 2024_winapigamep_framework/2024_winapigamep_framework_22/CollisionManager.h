#pragma once

template<typename T>
class Action;
class Collider;
union COLLIDER_ID
{
	struct
	{
		UINT left_ID;
		UINT right_ID;
	};
	ULONGLONG ID;
};
class CollisionManager
{
	DECLARE_SINGLE(CollisionManager);
public:
	void Update();
	void CheckLayer(LAYER _left, LAYER _right);
	void CheckReset();
	void SafeLoadScene(wstring);
private:
	void CollisionLayerUpdate(LAYER _left, LAYER _right);
	bool IsCollision(Collider* _left, Collider* _right);
private:
	// 그룹 간의 충돌체크 배열
	UINT m_arrLayer[(UINT)LAYER::END];
	map<ULONGLONG, bool> m_mapCollisionInfo;
	bool loadScene;
	wstring sceneName;
};