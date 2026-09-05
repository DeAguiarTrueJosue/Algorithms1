#pragma once

#include "Player.h"
#include <Vector.h>

class Team
{
public:
	void Initialize(int numPlayers);

	Player& GetNextBattlingPlayer();

	void DamagePlayer(Player& player);

	int GetRemainingPlayers();

	void OrderPlayers();

	void StartTurn();

	void PrintTeam() const;

private:
	std::string mName;
	Vector<Player> mPlayers;
};