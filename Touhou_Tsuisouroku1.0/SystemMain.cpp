#include "SystemMain.h"
#include "Define.h"
#include "Looper.h"

bool SystemMain::init() const
{
	SetAlwaysRunFlag(TRUE); // process while the window is not active
	SetWindowSizeChangeEnableFlag(TRUE);
	SetOutApplicationLogValidFlag(FALSE); // no log will be saved
	SetFullScreenResolutionMode(DX_FSRESOLUTIONMODE_DESKTOP); // maintain the window ration for full screen mode
	SetWindowText("Touhou Tsuisouroku");
	ChangeWindowMode(TRUE); // enable the window mode
	const int COLOR_BIT = 32;
	SetGraphMode(Define::WIN_W, Define::WIN_H, COLOR_BIT);

	if (DxLib_Init()) {
		return false;
	}
	SetDrawScreen(DX_SCREEN_BACK);
	return true;
}

void SystemMain::terminate() const
{
	DxLib_End();
}

void SystemMain::main() const
{
	Looper looper;
	while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen()) {
		if (!looper.loop() || CheckHitKey(KEY_INPUT_ESCAPE)) { // ESCAPE condition is only for debugging
			break;
		}
	}
}