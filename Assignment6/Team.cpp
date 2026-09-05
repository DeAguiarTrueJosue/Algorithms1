#include "Team.h"
#include <Names.h>
#include <PriorityQueue.h>
#include <Global.h>

void Team::Initialize(int numPlayers)
{
	mName = GetRandomName();
	for (int i = 0; i < numPlayers; i++)
	{
		mPlayers.PushBack(Player());
		mPlayers[mPlayers.size() - 1].Initialize(GetRandomName());
	}
}

Player& Team::GetNextBattlingPlayer()
{
	return mPlayers[0];
}

void Team::DamagePlayer(Player& player)
{
	player[Stats::AttackCount]--;
	Player& attacked = mPlayers[rand() % GetRemainingPlayers()];
	std::cout << player.GetName() << " attacked " << attacked.GetName() << " from team " << mName << "\n";
	attacked[Stats::Health] -= player[Stats::Attack];
	if (attacked[Stats::Health] <= 0)
	{
		std::cout << attacked.GetName() << " died from the attack\n";
		attacked[Stats::Speed] = 0;
		return;
	}
	std::cout << attacked.GetName() << " was left on " << attacked[Stats::Health] << "HP\n";
	if (rand() % 4 == 0)
	{
		if (attacked[Stats::Speed] > 5)
		{
			attacked[Stats::Speed] -= 10;
			if (attacked[Stats::Speed] < 5) { attacked[Stats::Speed] = 5; }
			std::cout << attacked.GetName() << " was slowed to " << attacked[Stats::Speed] << "\n";
		}
	}
	else if (rand() % 15 < 2)
	{
		attacked[Stats::Speed] += 5;
		std::cout << attacked.GetName() << " sped up to " << attacked[Stats::Speed] << "\n";
	}
}

int Team::GetRemainingPlayers()
{
	int remaining = 0;

	for (int i = 0; i < mPlayers.size(); i++)
	{
		if (mPlayers[i][Stats::Health] > 0)
		{
			remaining++;
		}
		else
		{
			break;
		}
	}

	return remaining;
}

void Team::OrderPlayers()
{
	Global::IntroSort(mPlayers.Begin(), mPlayers.End());
}

void Team::StartTurn()
{
	for (int i = 0; i < mPlayers.size(); i++)
	{
		mPlayers[i].SetStat(Stats::AttackCount, 1);
	}
}

	void Team::PrintTeam() const
	{
		std::cout << "Team " << mName << "\nPlayers:\n";
		for (int i = 0; i < mPlayers.size(); i++)
		{
			if (mPlayers[i].IsAlive())
			{
				std::cout << mPlayers[i] << "\n";
			}
		}
	}
