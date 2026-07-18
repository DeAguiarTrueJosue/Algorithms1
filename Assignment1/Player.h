#pragma once
#include <string>
#include <Array.h>
#include "Status.h"

struct Player
{
public:
	Player()
	{
		for (int i = 0; i < mStatus.size(); i++)
		{
			mStatus[i] = rand() % 5 + 1;
		}
		mStatus[(int)Status::Health] = 100;
	}
	Player(std::string name) : Player()
	{
		mName = name;
	}
	~Player() = default;

	int& status(Status status)
	{
		return mStatus[(int)status];
	}

	std::string Display()
	{
		return mName + ":" +
			"\nHealth: " + std::to_string(mStatus[(int)Status::Health]) +
			"\nAttack: " + std::to_string(mStatus[(int)Status::Attack]) +
			"\nDefense: " + std::to_string(mStatus[(int)Status::Defense]) +
			"\nStamina: " + std::to_string(mStatus[(int)Status::Stamina]) +
			"\nSpeed: " + std::to_string(mStatus[(int)Status::Speed]);
	}

	std::string mName;
	Array<int, 5> mStatus;
};