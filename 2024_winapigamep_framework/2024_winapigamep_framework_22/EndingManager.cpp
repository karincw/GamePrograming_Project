#include "pch.h"
#include "EndingManager.h"

void EndingManager::Init()
{
	//startTime = time(NULL);
}

void EndingManager::SetEnding(bool isTrue)
{
	isClear = isTrue;
}

bool EndingManager::GetEnding()
{
	//endTime = time(NULL);
	//cout << endTime - startTime << endl;
	return isClear;
}
