#include "Error.h"
#include <string>
//#include "Define.h" <- I should be deleting this if compiles without issues

using namespace std;

void Error::finish(const char* errorMessage, LPCTSTR lpszFuncName, int lineN)
{
	char funcName[1024];
	sprintf_s(funcName, "%s", lpszFuncName);
	printfDx("A fatal error occured\n%s\n%s(%d)", errorMessage, funcName, lineN);

	while (!ProcessMessage()) {
		ClearDrawScreen();
		ScreenFlip();
	}
	DxLib_End();
	exit(99);
}