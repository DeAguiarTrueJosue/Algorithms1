#pragma once

enum class StatusType
{
	Health,
	Damage,
	Defense,
	Speed,
	Poison
};

const char* statusTypes[]
{
	"Health",
	"Damage",
	"Defense",
	"Speed",
	"Poison",
};

const int statusTypesSize = sizeof(statusTypes) / sizeof(char*);

//Health
//Damage
//Defense
//Speed
//Poison