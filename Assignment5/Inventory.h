#pragma once
#include "KeyItem.h"
#include <Map.h>

class Inventory
{
public:
	static Inventory* Get();

	void PickupKey(const std::string& keyName, int amount);

	void UseKey(const std::string& keyName, int amount);

	KeyItem* GetKey(const std::string& keyName);
private:
	Map<std::string, KeyItem> mKeys;
};