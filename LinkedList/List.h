#pragma once

#include <cassert>
#include "Node.h"

class List
{
public:
	int& operator[](int index)
	{
		Node* toReturn = mHead;
		for (int i = 0; i < index; i++)
		{
			toReturn = toReturn->next;
		}
		return toReturn->mData;
	}

	void AddToEnd(int value)
	{
		if (mSize == 0)
		{
			mHead = new Node{
				value,
				nullptr
			};
			mSize++;
			return;
		}
		Node* currentNode = mHead;
		for (int i = 0; i < mSize - 1; i++)
		{
			currentNode = currentNode->next;
		}
		currentNode->next = new Node{
			value,
			nullptr
		};
		mSize++;
	}

	void AddToStart(int value)
	{
		Node* newHead = new Node{
			value,
			mHead
		};
		mHead = newHead;
		mSize++;
	}

	size_t size() const
	{
		return mSize;
	}

	~List()
	{
		Node** list = new Node*[mSize];
		Node* currentNode = mHead;
		for (int i = 0; i < mSize; i++)
		{
			list[i] = currentNode;
			currentNode = currentNode->next;
		}
		for (int i = 0; i < mSize; i++)
		{
			delete list[i];
		}
		delete[] list;
	}

private:
	Node* mHead = nullptr;
	size_t mSize = 0;
};