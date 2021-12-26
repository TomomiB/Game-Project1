#include "GameScene.h"
#include "Error.h"
#include "Stage1.h"

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
}

void GameScene::update()
{
	player->update();
}

void GameScene::draw() const
{
	player->draw();
}