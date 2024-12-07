#include "pch.h"
#include "EndingManager.h"
#include <sstream>

void EndingManager::Init()
{
	startTime = time(NULL);
}

void EndingManager::SetEnding(bool isTrue)
{
	isClear = isTrue;
}

bool EndingManager::GetEnding()
{
	endTime = time(NULL);
	cout << endTime - startTime << endl;
	return isClear;
}

LPCWSTR EndingManager::GetTime()
{
    double elapsedSeconds = difftime(endTime, startTime);

    std::wstringstream wss;
    wss << elapsedSeconds << L" SEC";

    static std::wstring result = wss.str();
    return result.c_str();
}
