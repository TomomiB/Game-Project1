#pragma once
#include <memory>
#include <vector>
#include <algorithm> // for copy()
#include <iterator> // for back_inserter 
#include "Task.h"
#include "AbstractEnemy.h"

class EnemyManager : public Task
{
public:

	const static int ENEMY_SHOT_POWER = 10;

	EnemyManager();
	virtual ~EnemyManager() = default;
	bool update() override;
	void draw() const override;

private:
	int count;
	std::vector<std::shared_ptr<AbstractEnemy>> enemyList;
	std::vector<std::shared_ptr<AbstractEnemy>> nextFrameEnemyList;

	void registerEnemyAndShots();
};

