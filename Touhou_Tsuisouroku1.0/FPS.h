#pragma once
#include <list>

class FPS
{
public:
	FPS();
	void wait();
	void draw() const;

private:
	std::list<int> list;
	float fps;
	unsigned counter;

	void updateAverage();
	void regist();
	unsigned getWaitTime() const;
};