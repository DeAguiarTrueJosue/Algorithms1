#pragma once
#include <string>
#include <cstdlib>
#include "Map.h"

namespace
{
	Map<std::string, int> nameCount;
}

const std::string possibleNames[]
{
	"Pablo",
	"Jennifer",
	"Roberto",
	"Chris",
	"Kat",
	"Cree",
	"Arnold",
	"Plee",
	"Carlos",
	"Kriko",
	"Cago",
	"Kawasaki",
	"Fade",
	"Steve",
	"Sonic",
	"Piada",
	"J",
	"YoMaMa",
	"Kralho",
	"WuW",
	"Hell"
};

const int namesCount = sizeof(possibleNames) / sizeof(std::string);

std::string GetRandomName()
{
	const std::string& chosenName = possibleNames[rand() % namesCount];
	if (!nameCount.Has(chosenName))
	{
		nameCount[chosenName] = 1;
		return chosenName;
	}
	nameCount[chosenName]++;
	return chosenName + std::to_string(nameCount[chosenName]);
}

std::string GetRandomName(int max)
{
	const std::string& chosenName = possibleNames[rand() % std::min(max, namesCount)];
	if (!nameCount.Has(chosenName))
	{
		nameCount[chosenName] = 1;
		return chosenName;
	}
	nameCount[chosenName]++;
	return chosenName + std::to_string(nameCount[chosenName]);
}