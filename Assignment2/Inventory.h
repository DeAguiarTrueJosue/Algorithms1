#pragma once
#include "Item.h"
#include <Vector.h>
#include <PriorityQueue.h>

class Inventory
{
public:
	void Initialize()
	{
		mItems.Reserve(itemTypesSize);
		for (size_t i = 0; i < itemTypesSize; i++)
		{
			mItems.PushBack(Item((ItemType)i, rand() % 4 + 2));
		}
	}
	
	void AddItem(ItemType itemType)
	{
		mItems[(int)itemType].AddItem();
	}

	void DisplayInventory()
	{
		PriorityQueue<Item, Item::CompareCount> items;
		for (size_t i = 0; i < mItems.size(); i++)
		{
			items.Push(mItems[i]);
		}

		std::cout << "Inventory:\n";
		while (!items.Empty())
		{
			std::cout << items.Top().ItemDescription() << "\n";
			items.Pop();
		}
	}

private:
	Vector<Item> mItems;
};