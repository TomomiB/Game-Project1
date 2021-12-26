#include "GameScene.h"
#include "Error.h"
#include "Stage1.h"
#include "Reimu.h"

#define ERR(str) Error::finish(str, __FUNCTION__, __LINE__);
using namespace std;

const static char* tag_stage = "stage";
const static char* tag_character = "character";

GameScene::GameScene(SceneChangeListener* listener, const SceneParameter& parameter) : AbstractScene(listener, parameter)
{
	switch (parameter.get(tag_stage)) {
	case 1:
		stage = make_shared<Stage1>();
		break;
	default:
		ERR("Level doesn't exist");
		break;
	}
	// make player class and init here...
	player = make_shared<Reimu>();
}

void GameScene::update()
{
	player->update();
	board->update();

	if (Keyboard::getIns()->getPressingCount(KEY_INPUT_ESCAPE) == 1) {
		SceneParameter parameter;
		SceneChanged->onSceneChanged(Define::eScene::Quit, parameter, false);
	}
}

void GameScene::draw() const
{
	player->draw();
	board->draw();
}