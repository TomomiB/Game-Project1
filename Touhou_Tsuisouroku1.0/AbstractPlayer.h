#pragma once
#include "Task.h"
//#include "HitCheck.h"
//#include "PlayerShot.h"

class AbstractPlayer : public Task
{
public:
	AbstractPlayer();
	virtual ~AbstractPlayer() = default;
	bool update() override;
	virtual void draw() const = 0;
	float getX() const { return x; }
	float getY() const { return y; }
	int getPower() const { return power; }
	int getHealth() const { return health; }
	//std::vector<Bullet>& getActivePlayerBullet();
	//PlayerShot& getPlayerShotRef() { return playerShot; } // pass ref of _playerShot to EnemyManager and boss class for their hit-check
	void setCharacter(int input_speed, int input_power, float input_range) { speed = input_speed; power = input_power; range = input_range; }

	int counter;
	float x, y; // player coordinate
	int health;

private:
	void shotBullets();
	bool didBulletHitMe();
	void updateHitBox();
	void HitCheckAndSetNoHitTimer();

protected:
	bool slow;
	float boxAngle;
	float w = 50.0f; // player width
	float h = 50.0f; // player width;
	float range;
	int direction;
	int directionCount;
	int power;
	int speed;
	int noHitTimer;
	//PlayerShot playerShot; // player's bullets

	virtual void move() = 0;
};