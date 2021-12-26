#pragma once
#include <memory>
#include "AbstractStage.h"
#include "EnemyManager.h"

class Stage1 : public AbstractStage
{
public:
	Stage1();
	virtual ~Stage1() = default;
	void update() override;
	void draw() const override;

	std::shared_ptr<EnemyManager> enemyManager;
};

