#pragma once
#include<time.h>

class EndingManager
{
	DECLARE_SINGLE(EndingManager);
public:
	void Init();
	void SetEnding(bool isClear);
	bool GetEnding();
	LPCWSTR GetTime();
private:
	bool isClear = false;
	time_t startTime = NULL;
	time_t endTime = NULL;
};

