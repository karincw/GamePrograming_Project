#pragma once
#include "pch.h"

template<typename t>
class Action
{
public:
	Action()
		:funcs({})
	{

	}
	~Action()
	{

	}

public:

	using FuncvoidType = void(*)(t);
	// ��ȯ��(*=> �������̴�)(����)
	//// �Լ�������
	//typedef;
	//using;  

	void Invoke(t value)
	{
		if (funcs.size() <= 0) return;
		for (auto f : funcs)
		{
			f(value);
		}
	}

	void Insert(FuncvoidType f)
	{
		//funcs.push_back(f);
		funcs.emplace_back(f);
	}
	 
	std::vector<FuncvoidType> funcs;
};

template<typename T, typename... Types>
class VariadicAction
{
public:
	VariadicAction()
		:funcs({})
	{

	}
	~VariadicAction()
	{

	}

public:

	using FuncvoidType = void(*)(T, Types...);
	// ��ȯ��(*=> �������̴�)(����)
	//// �Լ�������
	//typedef;
	//using;  

	void Invoke(T t, Types... value)
	{
		if (funcs.size() <= 0) return;
		for (auto f : funcs)
		{
			f(t, value...);
		}
	}

	void Insert(FuncvoidType f)
	{
		//funcs.push_back(f);
		funcs.emplace_back(f);
	}

	std::vector<FuncvoidType> funcs;
};
