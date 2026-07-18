#pragma once

#include <cstddef>
#include <utility>
#include <cassert>

#include "ContainerIterator.h"

template<typename T>
class Vector
{
public:
	Vector()
	{

	}
	~Vector()
	{
		if (mData != nullptr)
		{
			delete[] mData;
			mData = nullptr;
		}
		mCapacity = 0;
		mSize = 0;
	}
	Vector(const Vector& other)
	{
		if (other.mCapacity > 0)
		{
			mData = new T[other.mCapacity];
			for (size_t i = 0; i < other.mCapacity; i++)
			{
				mData[i] = other.mData[i];
			}
		}
		mCapacity = other.mCapacity;
		mSize = other.mSize;
	}
	Vector& operator=(const Vector& other)
	{
		if (mData != nullptr)
		{
			delete[] mData;
			mData = nullptr;
		}
		if (other.mCapacity > 0)
		{
			mData = new T[other.mCapacity];
			for (size_t i = 0; i < other.mCapacity; i++)
			{
				mData[i] = other.mData[i];
			}
		}
		mCapacity = other.mCapacity;
		mSize = other.mSize;
		return *this;
	}
	Vector(Vector&& other)
	{
		mData = std::move(other.mData);
		mSize = other.mSize;
		mCapacity = other.mCapacity;
		other.mData = nullptr;
		other.mCapacity = 0;
		other.mSize = 0;
	}
	Vector& operator=(Vector&& other)
	{
		if (mData != nullptr)
		{
			delete[] mData;
			mData = nullptr;
		}
		mData = std::move(other.mData);
		mSize = other.mSize;
		mCapacity = other.mCapacity;
		other.mData = nullptr;
		other.mCapacity = 0;
		other.mSize = 0;

		return *this;
	}

	void Reserve(size_t capacity)
	{
		if (capacity > mCapacity)
		{
			T* newData = new T[capacity];
			if (mData != nullptr)
			{
				for (size_t i = 0; i < mCapacity; i++)
				{
					newData[i] = mData[i];
				}
			}
			delete[] mData;
			mData = std::move(newData);
			mCapacity = capacity;
		}
	}

	void Resize(size_t size, const T& initialValue = T())
	{
		if (size == mSize)
		{
			return;
		}
		else if (size < mSize)
		{
			for (size_t i = size; i < mSize; i++)
			{
				mData[i].~T();
			}
		}
		else
		{
			size_t newCapacity = std::max(size, mCapacity);
			Reserve(newCapacity);
			for (size_t i = mSize; i < size; i++)
			{
				mData[i] = initialValue;
			}
		}
		mSize = size;
	}

	void Clear()
	{
		Resize(0);
	}

	size_t size() const
	{
		return mSize;
	}

	size_t capacity()
	{
		return mCapacity;
	}

	void PushBack(const T& value)
	{
		if (mSize >= mCapacity)
		{
			size_t newCapacity = (mCapacity == 0) ? 8 : mCapacity * 2;
			Reserve(newCapacity);
		}
		mData[mSize] = value;
		++mSize;
	}

	void PopBack()
	{
		assert(mSize > 0, "No elements in the vector");
		Resize(mSize - 1);
	}

	T& operator[](size_t index)
	{
		assert(index < mSize, "Index out of range");
		return mData[index];
	}

	using Iterator = ContainerIterator<T>;
	using Const_Iterator = ContainerIterator<const T>;
	Iterator Begin() { return Iterator(mData); }
	Iterator End() { return Iterator(mData + mSize); }
	Const_Iterator Begin() const { return Const_Iterator(mData); }
	Const_Iterator End() const { return Const_Iterator(mData + mSize); }

private:
	T* mData = nullptr;
	size_t mCapacity = 0;
	size_t mSize = 0;
};