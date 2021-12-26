#include "GamePad.h"
#include "Keyboard.h"
#include "Define.h"
#include <DxLib.h>
#include <string>
#include <algorithm>

using namespace std;

GamePad::GamePad()
{
	idArray[ePad::left] = 1;
	idArray[ePad::right] = 2;
	idArray[ePad::up] = 3;
	idArray[ePad::down] = 0;
	idArray[ePad::shot] = 5;
	idArray[ePad::bom] = 4;
	idArray[ePad::slow] = 11;
	idArray[ePad::pause] = 12;
}

void GamePad::update()
{
	int padInput = GetJoypadInputState(DX_INPUT_PAD1); // obtain inputs from gamepad
	for (int i = 0; i < PAD_KEY_NUM; i++) {
		// each button on gamepad has a bit assigned to it (within 16 bits)
		if (padInput & (1 << i)) {
			gamePad[i] = 1;
		}
		else {
			gamePad[i] = 0;
		}
	}
	merge_keyboard_to_gamepad();
}

void GamePad::merge_keyboard_to_gamepad()
{
	gamePad[idArray[ePad::left]] = max(gamePad[idArray[ePad::left]], Keyboard::getIns()->getPressingCount(KEY_INPUT_LEFT));
	gamePad[idArray[ePad::right]] = max(gamePad[idArray[ePad::right]], Keyboard::getIns()->getPressingCount(KEY_INPUT_RIGHT));
	gamePad[idArray[ePad::up]] = max(gamePad[idArray[ePad::up]], Keyboard::getIns()->getPressingCount(KEY_INPUT_UP));
	gamePad[idArray[ePad::down]] = max(gamePad[idArray[ePad::down]], Keyboard::getIns()->getPressingCount(KEY_INPUT_DOWN));
	gamePad[idArray[ePad::shot]] = max(gamePad[idArray[ePad::shot]], Keyboard::getIns()->getPressingCount(KEY_INPUT_SPACE));
	gamePad[idArray[ePad::bom]] = max(gamePad[idArray[ePad::bom]], Keyboard::getIns()->getPressingCount(KEY_INPUT_Z));
	gamePad[idArray[ePad::slow]] = max(gamePad[idArray[ePad::slow]], Keyboard::getIns()->getPressingCount(KEY_INPUT_LSHIFT));
	gamePad[idArray[ePad::pause]] = max(gamePad[idArray[ePad::pause]], Keyboard::getIns()->getPressingCount(KEY_INPUT_P));
}

int GamePad::get(ePad buttonID) const
{
	return gamePad[idArray[buttonID]];
}