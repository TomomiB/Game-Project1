#pragma once
#include <stack>
#include <memory>
#include "AbstractScene.h"
#include "SceneChangeListener.h"
#include "Define.h"
#include "FPS.h"

class Looper final : public SceneChangeListener
{
public:
	Looper();
	~Looper() = default;
	bool loop();
	void onSceneChanged(const Define::eScene scene, const SceneParameter& parameter, const bool stackClear) override;

private:
	std::stack<std::shared_ptr<AbstractScene>> sceneStack; // stack of scenes
	FPS fps;
};
