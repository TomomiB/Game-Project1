#pragma once
#include "AbstractPlayer.h"

class Reimu : public AbstractPlayer
{
public:
	Reimu(int speed, int power, float range);
	virtual ~Reimu() = default;
	void draw() const override;
	void move() override;
};


