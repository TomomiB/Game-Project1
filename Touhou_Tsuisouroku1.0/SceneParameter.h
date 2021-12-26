#pragma once
#include <string>
#include <map>

class SceneParameter
{
public:
	const static int Error = -1;

	SceneParameter() = default;
	virtual ~SceneParameter() = default;

	void set(std::string key, int val);
	int get(std::string key) const;

private:
	std::map<std::string, int> map;
};

