#pragma once
#include "AbstractScene.h"

class TitleScene : public AbstractScene
{
public:
	TitleScene(SceneChangeListener* listener, const SceneParameter& parameter);
	virtual ~TitleScene() = default;
	void update() override;
	void draw() const override;

private:
	void goToMenuScene();
	bool isSoundOn = false;
};