#pragma once
#include<vector>
template<typename t>
class Action
{
public:
	Action()
	{

	}
	~Action()
	{

	}

public:
	using FuncvoidType = void(*)(t);
	// 반환형(*=> 포인터이다)(인자)
	//// 함수포인터
	//typedef;
	//using;  
	void Invoke(t value)
	{
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
	void Delete(FuncvoidType f)
	{
		for (int iter = funcs.begin(); iter < funcs.end();)
		{
			if (funcs.at(iter) == f)
				iter = funcs.erase(iter);
			else
				iter++;
		}
	}
	 
	std::vector<FuncvoidType> funcs;
};
