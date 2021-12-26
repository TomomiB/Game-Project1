#pragma once
#include "Task.h"

/* pure virtual */
class AbstractEnemy : public Task
{
public:
	AbstractEnemy(float x, float y);
	virtual ~AbstractEnemy() = default;
	void initialize();
	bool update() override;

	float getX() const { return x; }
	float getY() const { return y; }
	float getRange() const { return range; }
	int getHealth() const { return health; }
	void updateHealth(int playerPower);

protected:
	virtual void setSize() = 0;
	bool isInside() const;

	float x, y;
	float speed;
	float angle;
	float range;

	int counter;
	int width;
	int height;
	int health;
};