#include "EnemyManager.h"
#include "GreenFire01.h"

EnemyManager::EnemyManager() : count(0)
{
}

bool EnemyManager::update()
{
	count++;
	registerEnemyAndShots();

	for (int i = 0; i < enemyList.size(); i++) {
		// if enemy goes out of the window or dies, delete it from the list
		if (enemyList[i]->update() == false /* OR enemy dies*/) {
			enemyList.erase(enemyList.begin() + i);
		}
	}

	return true;
}

void EnemyManager::draw() const
{
	for (const auto enemy : enemyList) {
		enemy->draw();
	}
}

void EnemyManager::registerEnemyAndShots()
{
	if (count == 100) {
		enemyList.emplace_back(std::make_shared<GreenFire01>(400, 100));
	}
	if (count == 110) {
		enemyList.emplace_back(std::make_shared<GreenFire01>(400, 100));
	}
}