#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <chrono>

std::chrono::steady_clock::time_point begin;
void StartClock()
{
	begin = std::chrono::high_resolution_clock::now();
}

float StopClock()
{
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
	return duration;
}

void ConstantAlgorithm()
{
	std::array<int, 100> sArray = std::array<int, 100>();
	std::array<int, 10000> bArray = std::array<int, 10000>();

	for (int i = 0; i < 100; ++i)
	{
		sArray[i] = i;
	}
	StartClock();
	for (int i = 0; i < 20; ++i)
	{
		std::cout << sArray[rand() % 100] << std::endl;
	}
	std::cout << "Total time:" << StopClock() << std::endl;

	for (int i = 0; i < 10000; ++i)
	{
		bArray[i] = i;
	}
	StartClock();
	for (int i = 0; i < 20; ++i)
	{
		std::cout << bArray[rand() % 10000] << std::endl;
	}
	std::cout << "Total time:" << StopClock() << std::endl;
}

void LinearAlgorithm()
{
	std::vector<int> sVector = std::vector<int>(100);
	std::vector<int> bVector = std::vector<int>(10000);

	for (int i = 0; i < 100; i++)
	{
		sVector[i] = rand() % 50 + 1;
	}

	for (int i = 0; i < 10000; i++)
	{
		bVector[i] = rand() % 50 + 1;
	}

	int counter = 0;
	std::cout << "Choose a number from 1 to 50: ";
	std::string input = "";
	std::cin >> input;
	int inputNumber = std::stoi(input);

	StartClock();
	for (int i = 0; i < 100; i++)
	{
		if (sVector[i] == inputNumber)
		{
			counter++;
		}
	}
	std::cout << "Total time:" << StopClock() << std::endl;

	counter = 0;

	StartClock();
	for (int i = 0; i < 10000; i++)
	{
		if (bVector[i] == inputNumber)
		{
			counter++;
		}
	}
	std::cout << "Total time:" << StopClock() << std::endl;
}

void LogarithmicAlgorithm()
{
	std::vector<int> sVector = std::vector<int>(100);
	std::vector<int> bVector = std::vector<int>(10000);

	for (int i = 0; i < 100; i++)
	{
		sVector[i] = rand() % 100 + 1;
	}

	for (int i = 0; i < 10000; i++)
	{
		bVector[i] = rand() % 100 + 1;
	}

	int counter = 0;
	std::cout << "Choose a number from 1 to 10: ";
	std::string input = "";
	std::cin >> input;
	int inputNumber = std::stoi(input);

	StartClock();
	for (int i = 0; i < 100; i += inputNumber)
	{
		std::cout << sVector[i] << " ";
	}
	std::cout << "Total time:" << StopClock() << std::endl;

	counter = 0;

	StartClock();
	for (int i = 0; i < 10000; i += inputNumber)
	{
		std::cout << bVector[i] << " ";
	}
	std::cout << "Total time:" << StopClock() << std::endl;
}

void ExponentialAlgorithm()
{
	std::vector<int> sVector = std::vector<int>(100);
	std::vector<int> bVector = std::vector<int>(10000);

	for (int i = 0; i < 100; i++)
	{
		sVector[i] = rand() % 100 + 1;
	}

	for (int i = 0; i < 10000; i++)
	{
		bVector[i] = rand() % 100 + 1;
	}

	StartClock();
	for (int i = 0; i < 100; i++)
	{
		for (int j = i + 1; j < 100; j++)
		{
			if (sVector[i] == sVector[j])
			{
				std::cout << "Pair found in indexes " << i << " and " << j << std::endl;
				break;
			}
		}
	}
	std::cout << "Total time:" << StopClock() << std::endl;

	StartClock();
	for (int i = 0; i < 10000; i++)
	{
		for (int j = i + 1; j < 10000; j++)
		{
			if (bVector[i] == bVector[j])
			{
				std::cout << "Pair found in indexes " << i << " and " << j << std::endl;
				break;
			}
		}
	}
	std::cout << "Total time:" << StopClock() << std::endl;
}

int main()
{
	srand(time(NULL));

	ExponentialAlgorithm();

	return 0;
}