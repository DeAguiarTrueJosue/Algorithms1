#include <iostream>
#include "Entity.h"
#include <Vector.h>
#include <Global.h>

int main()
{
	Vector<Entity> myEntities;

	for (size_t i = 0; i < 2; i++)
	{
		myEntities.PushBack(Entity());
		myEntities[i].Initialize("Player" + std::to_string(i + 1));
	}

	for (size_t i = 0; i < 20; i++)
	{
		myEntities.PushBack(Entity());
		myEntities[i + 2].Initialize("Enemy" + std::to_string(i + 1));
	}

	for (size_t i = 0; i < 4; i++)
	{
		std::cout << "Frame: " << i << "\n\n";
		for (size_t j = 0; j < myEntities.size(); j++)
		{
			myEntities[j].Update();
		}

		Global::BubbleSort(myEntities, Entity::ClosestToCenter());

		for (size_t j = 0; j < myEntities.size(); j++)
		{
			if (j == 10)
			{
				std::cout << " ";
			}
			myEntities[j].Render();
			std::cout << "\n";
		}
	}
}