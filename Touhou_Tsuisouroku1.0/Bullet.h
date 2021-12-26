#pragma once
#include "Task.h"

class Bullet : public Task
{
public:
	Bullet();
	Bullet(float x, float y, float speed, float angle, int flag, int power, int bulletType, int bulletColor);
	virtual ~Bullet() = default;
	bool update() override;
	void draw() const override;
	void initializeBullet();

protected:
	bool isInside();

	float x, y;
	float speed;
	float angle;
	int counter;
	int flag;
	int power; // power is defined for the player's shot. for enemy's shot, set a dummy value.
	int bulletType;
	int bulletColor;
	float range;
};

