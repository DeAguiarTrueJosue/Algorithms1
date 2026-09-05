#include "Player.h"
#include <format>

void Player::Initialize(const std::string& name)
{
	mName = name;
	mStats[(int)Stats::Health] = 100;
	mStats[(int)Stats::Speed] = rand() % 81 + 20;
	mStats[(int)Stats::Attack] = rand() % 16 + 5;
	mStats[(int)Stats::AttackCount] = 1;
}

int Player::GetStat(Stats stat) const
{
	return mStats[(int)stat];
}

void Player::SetStat(Stats stat, int value)
{
	mStats[(int)stat] = value;
}

bool Player::IsAlive() const
{
	return 	mStats[(int)Stats::Health] > 0;
}

const std::string& Player::GetName() const
{
	return mName;
}

std::ostream& operator<<(std::ostream& os, const Player& player)
{
	return os << std::format("Name: {:10s}. Stats -> Health: {:3.0f} Attack: {:2.0f} Speed: {:3.0f}", player.mName,
		(float)player.mStats[0], (float)player.mStats[1], (float)player.mStats[2]);
}