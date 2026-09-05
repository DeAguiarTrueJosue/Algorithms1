#include "City.h"

void City::AddHouse(const std::string& name, const Vector2& pos)
{
	mHouses.PushBack({ name, pos });
}

void City::ConnectAllHouses()
{

}
