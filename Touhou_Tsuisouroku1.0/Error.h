#pragma once
#include <Windows.h>
#include <DxLib.h>

class Error
{
public:
	static void finish(const char* errorMessage, LPCTSTR lpszFuncName, int lineN);
};

