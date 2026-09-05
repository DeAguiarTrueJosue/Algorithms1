#pragma once
#include "House.h"
#include <Vector.h>
#include <MSTGraph.h>
#include <MSTGraphK.h>

class City
{
public:
	void AddHouse(const std::string& name, const Vector2& pos);

	void ConnectAllHouses();

	float GetTotalRoadDistancePrim();

	float GetTotalRoadDistanceKruskal();
private:
	Vector<House> mHouses;
	MSTGraph<House, float> mHouseGraph;
	MSTGraph<House, float> mHouseEdgesGraph;
};