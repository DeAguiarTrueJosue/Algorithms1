#include "Inventory.h"

Inventory* Inventory::Get()
{
    static Inventory sInstance;
    return &sInstance;
}

void Inventory::PickupKey(const std::string& keyName, int amount)
{
	if (mKeys.Has(keyName))
	{
		mKeys[keyName].Add(amount);
	}
	else
	{
		KeyItem newItem(keyName, amount);
		mKeys.Insert(keyName, newItem);
	}
}

void Inventory::UseKey(const std::string& keyName, int amount)
{
	if (mKeys.Has(keyName))
	{
		mKeys[keyName].Consume(amount);
		if (mKeys[keyName].GetCount() <= 0)
		{
			mKeys.Remove(keyName);
		}
	}
}

KeyItem* Inventory::GetKey(const std::string& keyName)
{
	KeyItem* key = nullptr;
	if (mKeys.Has(keyName))
	{
		key = &mKeys[keyName];
	}
	return key;
}
