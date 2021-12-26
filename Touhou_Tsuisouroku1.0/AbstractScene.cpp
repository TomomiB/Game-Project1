#include "AbstractScene.h"

AbstractScene::AbstractScene(SceneChangeListener* listener, const SceneParameter& parameter) : 
	SceneChanged(listener)
{
}