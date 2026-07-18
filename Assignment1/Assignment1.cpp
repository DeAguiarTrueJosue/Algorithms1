#include <iostream>
#include "Player.h"
#include <Vector.h>

int Combat(Player& p1, Player& p2, int& p1Score, int& p2Score)
{
	p1Score = p1.status(Status::Health) - ((p2.status(Status::Attack) *
		p2.status(Status::Stamina)) - (p1.status(Status::Defense) * p1.status(Status::Speed)));
	p2Score = p2.status(Status::Health) - ((p1.status(Status::Attack) *
		p1.status(Status::Stamina)) - (p2.status(Status::Defense) * p2.status(Status::Speed)));
	return p1Score - p2Score;
}

int GetSign(int x)
{
	return (x >= 0) - (0 > x);
}

int main()
{
	srand(time(NULL));
	Vector<Player> players;
	Array<std::string, 15> possibleNames("");
	possibleNames[0] = "Pablo";
	possibleNames[1] = "Jennifer";
	possibleNames[2] = "Roberto Carlos";
	possibleNames[3] = "Chris";
	possibleNames[4] = "Kat";
	possibleNames[5] = "Cree";
	possibleNames[6] = "Arnold";
	possibleNames[7] = "Plee";
	possibleNames[8] = "Carlos";
	possibleNames[9] = "Kriko";
	possibleNames[10] = "Cago";
	possibleNames[11] = "Kawasaki";
	possibleNames[12] = "Fade";
	possibleNames[13] = "Steve";
	possibleNames[14] = "Sonic";

	for (size_t i = 0; i < 10; i++)
	{
		players.PushBack(Player(possibleNames[rand() % possibleNames.size()]));
	}

	for (size_t i = 0; i < 6; i++)
	{
		players.PopBack();
	}

	for (size_t i = players.size(); i < 20; i++)
	{
		players.PushBack(Player(possibleNames[rand() % possibleNames.size()]));
	}

	for (size_t i = 0; i < players.size(); i++)
	{
		std::cout << "Player " << i + 1 << ", " << players[i].Display() << "\n\n";
	}

	int index1 = rand() % players.size();
	int index2 = rand() % players.size();

	while (index1 == index2)
	{
		index2 = rand() % players.size();
	}

	int p1Score;
	int p2Score;
	int result = Combat(players[index1], players[index2], p1Score, p2Score);
	int winner = 0;

	std::cout << "Combatant 1, " << players[index1].Display() << "\n\n";
	std::cout << "Combatant 2, " << players[index2].Display() << "\n\n";

	if (result == 0)
	{
		winner == (rand() % 2) + 1;

		std::cout << "This game was a tie\n";
		std::cout << "A coin was flipped and the winner was decided\n\n";
	}
	else
	{
		winner = GetSign(result);

		if (winner == -1)
		{
			winner = 2;
		}
	}

	if (winner == 1)
	{
		std::cout << "Winner: "  << p1Score << " points to " << p2Score << " points\n"
			<< "Combatant 1, " << players[index1].Display();
	}
	else
	{
		std::cout << "Winner: " << p2Score << " points to " << p1Score << " points\n"
			<< "Combatant 2, " << players[index2].Display();
	}
}