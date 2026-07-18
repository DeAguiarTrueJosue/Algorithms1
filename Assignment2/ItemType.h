#pragma once

enum class ItemType
{
	HealthPotion,
	StrengthPotion,
	StonePotion,
	LightingPotion,
	Antidote,

	VampireFangs,
	Excalibour,
	DualWielding,
	Dagger,
	ThrowingNeedle,

	CozyScarf,
	ThornBoots,
	HeavyArmour,
	Jetpack,
	ClownFlower
};

const char* itemTypes[]
{
	"Health Potion",
	"Strength Potion",
	"Stone Potion",
	"Lighting Potion",
	"Antidote",
	
	"Vampire Fangs",
	"Excalibour",
	"Dual Wielding",
	"Dagger",
	"Throwing Needle",
	
	"Cozy Scarf",
	"Thorn Boots",
	"Heavy Armour",
	"Jetpack",
	"Clown Flower"
};

const int itemTypesSize = sizeof(itemTypes) / sizeof(char*);

//Health
//Damage
//Defense
//Speed
//Poison

//Potion
//Sword
//Armour