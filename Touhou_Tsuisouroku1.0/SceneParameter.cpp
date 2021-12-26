#include "SceneParameter.h"

void SceneParameter::set(std::string key, int val)
{
	map[key] = val;
}

int SceneParameter::get(std::string key) const
{
	auto it = map.find(key);
	if (map.end() == it) {
		return Error;
	}
	else {
		return it->second;
	}
}