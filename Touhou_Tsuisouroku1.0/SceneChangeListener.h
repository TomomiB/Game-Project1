#pragma once
#include "Define.h"
#include "SceneParameter.h"

class SceneChangeListener
{
public:
	SceneChangeListener() = default;
	virtual ~SceneChangeListener() = default;
	virtual void onSceneChanged(const Define::eScene scene, const SceneParameter& parameter, const bool stackClear) = 0;
};