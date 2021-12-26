#pragma once
// most of the child classes will need these header files
#include <DxLib.h>
#include "Define.h"
#include "Keyboard.h"
#include "GamePad.h"
#include "Image.h"
//#include "Sound.h"

class AbstractStage
{
public:
	AbstractStage();
	virtual ~AbstractStage() = default;
	virtual void update() = 0;
	virtual void draw() const = 0;

protected:
	int counter;
};

