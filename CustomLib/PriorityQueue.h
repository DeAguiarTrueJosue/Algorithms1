#pragma once

#include "Vector.h"
#include <iostream>

template<typename T, typename Compare = std::less<typename T>>
class PriorityQueue
{
public:
	PriorityQueue() {}
	~PriorityQueue() = default;

	bool Empty() const
	{
		return mData.size() == 0;
	}

	const std::size_t size()
	{
		return mData.size();
	}

	void Push(const T& value)
	{
		mData.PushBack(value);
		HeapifyUp(size() - 1);
	}
	T& Top()
	{
		return mData[0];
	}

	void Pop()
	{
		if (Empty())
		{
			assert(false, "Queue already empty");
			return;
		}
		mData[0] = mData[size() - 1];
		mData.Resize(size() - 1);
		HeapifyDown(0);
	}

private:
	void Swap(T& a, T& b)
	{
		T tmp = a;
		a = b;
		b = tmp;
	}

	void HeapifyUp(int index)
	{
		int parent = (index - 1) / 2;
		while (index > 0 && mCompare(mData[parent], mData[index]))
		{
			Swap(mData[index], mData[parent]);
			index = parent;
			parent = (index - 1) / 2;
		}
	}
	void HeapifyDown(int index)
	{
		int largest = index;
		int leftChild = 2 * index + 1;
		int rightChild = 2 * index + 2;
		if (leftChild < size() && mCompare(mData[largest], mData[leftChild]))
		{
			largest = leftChild;
		}
		if (rightChild < size() && mCompare(mData[largest], mData[rightChild]))
		{
			largest = rightChild;
		}
		if (largest != index)
		{
			Swap(mData[index], mData[largest]);
			HeapifyDown(largest);
		}

	}

	Compare mCompare;
	Vector<T> mData;
};