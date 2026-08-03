#pragma once
#include "Vector.h"

template<typename T>
class Stack
{
public:
	void Push(const T& value)
	{
		mData.PushBack();
	}

	void Pop()
	{
		assert(!Empty(), "[Error] Trying to pop an empty stack");
		mData.PopBack();
	}

	const T& Top() const
	{
		assert(!Empty(), "[Error] Trying to view an empty stack");
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