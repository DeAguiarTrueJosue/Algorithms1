#include "KeyItem.h"
#include <iostream>

KeyItem::KeyItem()
{
	mName = "";
	mCount = 0;
}

KeyItem::KeyItem(const std::string& name, int initialCount)
{
	mName = name;
	mCount = initialCount;
}

void KeyItem::Add(int amount)
{
	mCount += amount;
}

void KeyItem::Consume(int amount)
{
	mCount -= amount;
}

int KeyItem::GetCount() const
{
	return mCount;
}

void KeyItem::Print() const
{
	std::cout << mName << ": " << std::to_string(mCount) << std::endl;
}
