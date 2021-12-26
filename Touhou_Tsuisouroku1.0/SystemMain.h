#pragma once
#include <DxLib.h>

class SystemMain final
{
public:
	SystemMain() = default;
	~SystemMain() = default;
	bool init() const;
	void terminate() const;
	void main() const;
};

