#include <iostream>
#include "Team.h"

int main()
{
	srand(time(NULL));
	std::cout << "Super Hyper Incredible Combat System\n\n";

	Team t1;
	t1.Initialize(20);
	t1.OrderPlayers();

	Team t2;
	t2.Initialize(20);
	t2.OrderPlayers();

	int turnNumber = 1;

	while (t1.GetRemainingPlayers() > 0 && t2.GetRemainingPlayers() > 0)
	{
		t1.PrintTeam();
		std::cout << "\n";
		t2.PrintTeam();
		std::cout << "\n";
		std::cout << "Turn " << turnNumber++;
		std::cout << "\n";
		t1.StartTurn();
		t2.StartTurn();

		while (true)
		{
			std::cout << "\n";
			t1.OrderPlayers();
			t2.OrderPlayers();

			Player& p1 = t1.GetNextBattlingPlayer();
			Player& p2 = t2.GetNextBattlingPlayer();

			if (p1[Stats::AttackCount] <= 0 && p2[Stats::AttackCount] <= 0) { break; }
			if (t1.GetRemainingPlayers() == 0 || t2.GetRemainingPlayers() == 0) { break; }

			if (p1[Stats::AttackCount] <= 0) { t1.DamagePlayer(p2); continue; }
			if (p2[Stats::AttackCount] <= 0) { t2.DamagePlayer(p1); continue; }

			if (p1[Stats::Speed] < p2[Stats::Speed]) { t1.DamagePlayer(p2); }
			else { t2.DamagePlayer(p1); }
		}
	}

	std::cout << "\n\nAnd the winner team is:\n";
	if (t1.GetRemainingPlayers() == 0)
	{
		t2.PrintTeam();
	}
	else
	{
		t1.PrintTeam();
	}
}