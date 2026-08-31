#pragma once

#include <string>

class KeyItem
{
public:
	KeyItem();
	KeyItem(const std::string&, int initialCount);

	void Add(int amount);
	void Consume(int amount);

	int GetCount() const;

	void Print() const;

private:
	std::string mName;
	int mCount = 0;
};