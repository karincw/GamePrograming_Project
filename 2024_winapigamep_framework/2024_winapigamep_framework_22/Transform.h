#pragma once
#include "Component.h"
class Transform : public Component
{
public:
	Transform();
	~Transform();
public:
	void LateUpdate() override;
	void Render(HDC _hdc) override;
public:
	void Translate(Vec2 v);
public:
	void SetPosition(Vec2 v) { _position = v; }
	void SetScale(Vec2 v) { _scale = v; }
	void SetRotation(float r) { _rotation = r; }
	Vec2 GetPosition() { return _position; };
	Vec2 GetScale() { return _scale; };
	float GetRotation() { return _rotation; };
private:
	Vec2 _position;
	float _rotation;
	Vec2 _scale;
};

