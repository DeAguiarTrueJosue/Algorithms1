#include <iostream>
#include "Inventory.h"
#include <Vector.h>
#include <Names.h>
#include <cstdlib>

int main()
{
	Inventory* inv = Inventory::Get();
	Vector<std::string> mKeyNames;

	for (int i = 0; i < 20; i++)
	{
		mKeyNames.PushBack(possibleNames[i]);
	}

	for (int i = 0; i < 100; i++)
	{
		inv->PickupKey(mKeyNames[rand() % mKeyNames.size()], 1);
	}

	for (int i = 0; i < mKeyNames.size(); i++)
	{
		inv->GetKey(mKeyNames[i])->Print();
	}

	std::string decision;
	int doorsUnlocked = 0;
	int doorsCouldntOpen = 0;

	while (decision != "3")
	{
		std::cout << "What would you like to do?"
			"\n1. Open a door"
			"\n2. Obtain a key"
			"\n3. Exit\n\n";

		std::getline(std::cin, decision);
		std::cout << "\n";

		if (decision == "1")
		{
			const std::string& keyNeeded = mKeyNames[rand() % mKeyNames.size()];
			std::cout << "You arrive at a door and need a " << keyNeeded << "\n";

			KeyItem* key = inv->GetKey(keyNeeded);

			if (key != nullptr)
			{
				std::cout << "You used a " << keyNeeded << " and have unlocked the door\n";
				inv->UseKey(keyNeeded, 1);
				doorsUnlocked++;
			}
			else
			{
				doorsCouldntOpen++;
				std::cout << "You do not have the " << keyNeeded << ". The door will remain locked\n";
			}
		}
		else if (decision == "2")
		{
			const std::string& keyPicked = mKeyNames[rand() % mKeyNames.size()];
			std::cout << "You found a " << keyPicked << "\n";

			inv->PickupKey(keyPicked, 1);
			inv->GetKey(keyPicked)->Print();
		}
		else if (decision == "check")
		{
			for (int i = 0; i < mKeyNames.size(); i++)
			{
				KeyItem* key = inv->GetKey(mKeyNames[i]);
				if (key != nullptr)
				{
					key->Print();
				}
			}
		}
		
		std::cout << "\n";
		system("pause");
		system("cls");
	}

	std::cout << "Keys you still had:\n\n";
	for (int i = 0; i < mKeyNames.size(); i++)
	{
		KeyItem* key = inv->GetKey(mKeyNames[i]);
		if (key != nullptr)
		{
			key->Print();
		}
	}

	std::cout << "\nDoors you unlocked: " << doorsUnlocked;
	std::cout << "\nDoors you coudnt unlock: " << doorsCouldntOpen;
	std::cout << "\n";
}