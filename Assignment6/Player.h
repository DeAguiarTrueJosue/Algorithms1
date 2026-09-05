#pragma once
#include "Stats.h"
#include <string>
#include <Array.h>
#include <iostream>


class Player
{
public:
	void Initialize(const std::string& name);

	int GetStat(Stats stat) const;

	void SetStat(Stats stat, int value);

	bool IsAlive() const;

	const std::string& GetName() const;

	friend std::ostream& operator<<(std::ostream& os, const Player& player);

	int& operator[](const Stats& stat)
	{
		return mStats[(int)stat];
	}

	bool operator<(const Player& b) const
	{
		if ((!IsAlive() || GetStat(Stats::AttackCount) == 0) && (!b.IsAlive() || b.GetStat(Stats::AttackCount) == 0))
		{
			return GetStat(Stats::Speed) > b.GetStat(Stats::Speed);
		}
		if ((!IsAlive() || GetStat(Stats::AttackCount) == 0))
		{
			return false;
		}
		if ((!b.IsAlive() || b.GetStat(Stats::AttackCount) == 0))
		{
			return true;
		}

		return GetStat(Stats::Speed) > b.GetStat(Stats::Speed);
	}

private:
	std::string mName = "";
	Array<int, 4> mStats{0};
};