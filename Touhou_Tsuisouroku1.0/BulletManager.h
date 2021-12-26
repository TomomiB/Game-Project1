#pragma once
#include <memory>
#include <vector>

class BulletManager
{
public:
	BulletManager();
	virtual ~BulletManager();
	void update();
	void draw() const;

	int count;
	//std::vector<std::shared_ptr</*bullets*/>> enemyBulletList;
};

