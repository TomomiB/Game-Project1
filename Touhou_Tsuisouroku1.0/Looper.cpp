#include "Looper.h"
#include "Error.h"
#include "TitleScene.h"
//#include "TitleMenu.h"
//#include "CharacterMenu.h"
#include "GameScene.h"
//#include "OptionScene.h"
#include "keyboard.h"
#include "GamePad.h"
#include "Image.h"
#include <DxLib.h>

#define ERR(str) Error::finish(str, __FUNCTION__, __LINE__);

using namespace std;

/* constructor */
Looper::Looper()
{
	Image::getIns()->load();
	SceneParameter parameter;
	// the first scene is always the title
	sceneStack.push(make_shared<TitleScene>(this, parameter));
}


/* here the main loop */
bool Looper::loop()
{
	Keyboard::getIns()->update();
	GamePad::getIns()->update();
	sceneStack.top()->update();
	sceneStack.top()->draw();
	fps.draw();
	fps.wait();

	return true;
}

/* Inherited from the SceneChangeListener class */
void Looper::onSceneChanged(const Define::eScene scene, const SceneParameter& parameter, const bool stackClear)
{
	if (stackClear) {// if stackClear parameter is passed for this function
		while (!sceneStack.empty()) { // check if the stack is empty already, and pop all the stacks
			sceneStack.pop();
		}
	}

	switch (scene) {
	case Define::eScene::Title:
		sceneStack.push(make_shared<TitleScene>(this, parameter));
		break;
	case Define::eScene::Menu:
		//sceneStack.push(make_shared<TitleMenu>(this, parameter));
		break;
	case Define::eScene::Game:
		sceneStack.push(make_shared<GameScene>(this, parameter));
		break;
	case Define::eScene::CharacterSelect:
		//sceneStack.push(make_shared<CharacterMenu>(this, parameter));
		break;
	case Define::eScene::Option:
		//sceneStack.push(make_shared<OptionScene>(this, parameter));
		break;
	case Define::eScene::Quit:
		DxLib_End();
		break;
	case Define::eScene::Back:
		sceneStack.pop();
		break;
	default:
		ERR("Scene doesn't exist");
		break;
	}
}