#include "pch.h"
#include "Transform.h"

Transform::Transform()
	:_position({ 0,0 })
	, _rotation(0)
	, _scale({ 1,1 })
{

}

Transform::~Transform()
{

}

void Transform::Translate(Vec2 v)
{
	_position += v;
}

void Transform::LateUpdate()
{

}

void Transform::Render(HDC _hdc)
{

}
