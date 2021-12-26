#pragma once
#include "AbstractPlayer.h"

class Reimu : public AbstractPlayer
{
public:
	Reimu();
	virtual ~Reimu() = default;
	void draw() const override;
	void move() override;
};


