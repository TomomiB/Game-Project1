#pragma once
#include "Singleton.h"
#include <array>

enum ePad
{
	left, right, up, down, shot, bom, slow, pause
};

class GamePad final: public Singleton<GamePad>
{
public:
	GamePad();
	~GamePad() = default;
	void update();
	int get(ePad buttonID) const; // obtain the input of eID

private:
	void merge_keyboard_to_gamepad();
	const static int PAD_KEY_NUM = 16;
	std::array<int, PAD_KEY_NUM> idArray;
	std::array<int, PAD_KEY_NUM> gamePad;
};

