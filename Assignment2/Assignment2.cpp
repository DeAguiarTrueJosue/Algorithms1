#include <iostream>
#include <string>
#include "Inventory.h"

int main()
{
	srand(time(NULL));

	Inventory inventory;

	inventory.Initialize();

	for (size_t i = 0; i < 100; i++)
	{
		inventory.AddItem((ItemType)(rand() % itemTypesSize));
	}

	inventory.DisplayInventory();	
}