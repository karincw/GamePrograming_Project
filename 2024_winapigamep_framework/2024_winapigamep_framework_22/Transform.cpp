#include "pch.h"


Transform::Transform()
	:_position({ 0,0 })
	, _scale({ 0,0 })
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
