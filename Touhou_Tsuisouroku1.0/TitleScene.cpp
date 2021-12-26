#include "TitleScene.h"
//#include "GameScene.h"

TitleScene::TitleScene(SceneChangeListener* listener,
	const SceneParameter& parameter) : AbstractScene(listener, parameter)
{
	// do nothing with the parameter
}

/* always update() => draw() */
void TitleScene::update()
{
	if (!isSoundOn) {
		//PlaySoundMem(Sound::getIns()->getTitleSound(), DX_PLAYTYPE_LOOP);
		isSoundOn = true;
	}
	if (GamePad::getIns()->get(ePad::shot) == 1 || Keyboard::getIns()->getPressingCount(KEY_INPUT_SPACE) == 1) {
		goToMenuScene();
	}
	if (Keyboard::getIns()->getPressingCount(KEY_INPUT_ESCAPE) == 1) {
		SceneParameter parameter;
		SceneChanged->onSceneChanged(Define::eScene::Quit, parameter, false);
	}
}

/* always update() => draw()*/
void TitleScene::draw() const
{
	DrawGraph(1, 0, Image::getIns()->getTitle(), TRUE);
}

void TitleScene::goToMenuScene()
{
	// no need to specify the parameter here
	SceneParameter parameter;
	parameter.set("stage", 1);
	// true because player won't come back to this screen
	const bool stackClear = true;

	// use the parameter that we set above to specify next scene
	//SceneChanged->onSceneChanged(Define::eScene::Menu, parameter, stackClear);
	SceneChanged->onSceneChanged(Define::eScene::Game , parameter, stackClear);
}