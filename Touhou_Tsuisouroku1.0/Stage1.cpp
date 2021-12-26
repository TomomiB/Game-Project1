#include "Stage1.h"
#include "GreenFire01.h"

Stage1::Stage1()
{
	counter = 0;
	enemyManager = std::make_shared<EnemyManager>();
}

void Stage1::update()
{
	counter++;
	enemyManager->update();
}

void Stage1::draw() const
{
	enemyManager->draw();
}