#pragma once
#include <string>
#include "ItemType.h";
#include "StatusType.h"
#include <iostream>

class Item
{
public:

	Item(ItemType itemType, int value)
		: mType(itemType), mName(itemTypes[(int)itemType]),
		mStatusType(StatusType((int)itemType % 5)), mValue(value), mCount(0) { };
	Item() = default;

	void ConsumeItem()
	{
		if (mCount > 0)
		{
			mCount--;
		}
		else
		{
			std::cout << "Item not available\n";
		}
	}

	void AddItem()
	{
		mCount++;
	}

	std::string ItemDescription()
	{
		return std::to_string(mCount) + " " + mName + (mCount > 1 ? "s" : "")
			+ ": +" + std::to_string(mValue) + " " + statusTypes[(int)mStatusType];
	}

	struct CompareCount
	{
		bool operator()(const Item& lhs, const Item& rhs)
		{
			return lhs.mCount < rhs.mCount;
		}
	};

private:
	ItemType mType{};
	std::string mName{};
	StatusType mStatusType{};
	int mValue = 0;
	int mCount = 0;

};