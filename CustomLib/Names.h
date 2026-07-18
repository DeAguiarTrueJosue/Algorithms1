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
	"J"
};

const int namesCount = sizeof(possibleNames) / sizeof(std::string);

std::string GetRandomName()
{
	return possibleNames[rand() % namesCount];
}