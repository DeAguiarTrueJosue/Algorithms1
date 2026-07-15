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
	~Player() = default;

	int& status(Status status)
	{
		return mStatus[(int)status];
	}

	std::string mName;
	Array<int, 5> mStatus;
};