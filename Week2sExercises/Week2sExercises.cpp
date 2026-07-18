#include <iostream>

#include <Array.h>
#include <Vector.h>
#include <PriorityQueue.h>

int main()
{
	Array<int, 20> arrayNumbers;
	Vector<int> vectorNumbers;
	PriorityQueue<int> priorityNumbers;

	vectorNumbers.Reserve(20);

	for (size_t i = 0; i < 20; i++)
	{
		arrayNumbers[i] = rand() % 101;
		vectorNumbers.PushBack(arrayNumbers[i]);
		priorityNumbers.Push(arrayNumbers[i]);
	}

	std::cout << "Array\n";
	for (Array<int, 20>::Iterator i = arrayNumbers.Begin(); i < arrayNumbers.End(); i++)
	{
		std::cout << *i << "\n";
	}

	std::cout << "\nVector\n";
	for (Vector<int>::Iterator i = vectorNumbers.Begin(); i < vectorNumbers.End(); i++)
	{
		std::cout << *i << "\n";
	}

	std::cout << "\Priority Queue\n";
	while (!priorityNumbers.Empty())
	{
		std::cout << priorityNumbers.Top() << "\n";
		priorityNumbers.Pop();
	}
}