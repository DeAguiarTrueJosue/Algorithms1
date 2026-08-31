#pragma once
#include <string>
#include <cstdlib>

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
	return possibleNames[rand() % namesCount];
}

std::string GetRandomName(int max)
{
	return possibleNames[rand() % std::min(max, namesCount)];
}