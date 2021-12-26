#pragma once
#include "SceneChangeListener.h"
#include "SceneParameter.h"
// most of the child classes will need these header files
#include <DxLib.h>
#include "Define.h"
#include "Keyboard.h"
#include "GamePad.h"
#include "Image.h"
//#include "Sound.h"

class SceneChangeListener;

class AbstractScene
{
public:
	AbstractScene(SceneChangeListener* SceneChangeListener, const SceneParameter& parameter);
	virtual ~AbstractScene() = default;
	virtual void update() = 0;
	virtual void draw() const = 0;

protected:
	SceneChangeListener* SceneChanged;
};