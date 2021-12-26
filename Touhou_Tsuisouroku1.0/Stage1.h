#pragma once
#include "AbstractStage.h"

class Stage1 : public AbstractStage
{
public:
	Stage1();
	virtual ~Stage1() = default;
	void update() override;
	void draw() const override;
};

