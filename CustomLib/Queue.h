#pragma once
#include "Vector.h"

template<typename T>
class Queue
{
public:
	void Enqueue(const T& value)
	{
		mData.PushBack();
	}

	void Dequeue()
	{
		assert(!Empty(), "[Error] Trying to dequeue an empty queue");
		mData.PopFront();
	}

	const T& Front() const
	{
		assert(!Empty(), "[Error] Trying to view an empty queue");
		return mData[mData.size() - 1];
	}

	std::size_t size() const
	{
		return mData.size();
	}

	bool Empty() const
	{
		return mData.size() == 0;
	}

private:
	Vector<T> mData;
};