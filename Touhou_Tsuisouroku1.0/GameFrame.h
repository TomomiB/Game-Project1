#pragma once
#include "Task.h"

class GameFrame final : public Task
{
public:
	GameFrame() = default;
	~GameFrame() = default;
	bool update() override;
	void draw() const override;
	void setPlayerProperty(int health, int power);

private:
	int _playerHealth;
	int _playerPower;
};