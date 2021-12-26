#pragma once
#include <DxLib.h>
#include "Define.h"
#include "keyboard.h"
#include "Image.h"
//#include "ImageBullet.h"
//#include "Sound.h"

/* parent class of all game properties(player, enemies, bullets...)*/
class Task
{
public:
	Task() = default;
	virtual ~Task() = default;
	virtual bool update() = 0; // pure virtual function: force the subclass implement this
	virtual void draw() const = 0;
};