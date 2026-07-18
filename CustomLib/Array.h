#pragma once
#include <cstddef>
#include <utility>
#include "ContainerIterator.h"

template<typename T, size_t N>
class Array
{
public:

	Array()
	{

		static_assert(N > 0, "Array must ba at least 1");

		mData = new T[N];
	}

	Array(T initialValue)
	{
		static_assert(N > 0, "Array must ba at least 1");

		mData = new T[N];

		for (size_t i = 0; i < N; i++)
		{
			mData[i] = initialValue;
		}
	}

	Array(const Array& other)
	{
		mData = new T[N];
		for (size_t i = 0; i < N; i++)
		{
			mData[i] = other[i];
		}
	}

	Array(Array<T, N>&& other)
	{
		mData = std::move(other.mData);
		other.mData = nullptr;
	}

	~Array()
	{
		delete[] mData;
		mData = nullptr;
	}

	Array& operator=(const Array<T, N>& other)
	{
		if (mData != nullptr)
		{
			delete[] mData;
		}
		mData = new T[N];
		for (size_t i = 0; i < N; i++)
		{
			mData[i] = other[i];
		}
		return *this;
	}

	Array& operator=(Array<T, N>&& other)
	{
		if (mData != nullptr)
		{
			delete[] mData;
		}
		mData = std::move(other.mData);
		other.mData = nullptr;
		return *this;
	}

	const T* data() const
	{
		return mData;
	}

	T* data()
	{
		return mData;
	}

	const size_t size() const
	{
		return N;
	}

	T& operator[](size_t index)
	{
		return mData[index];
	}

	const T& operator[](size_t index) const
	{
		return mData[index];
	}

	using Iterator = ContainerIterator<T>;
	using Const_Iterator = ContainerIterator<const T>;
	Iterator Begin() { return Iterator(mData); }
	Iterator End() { return Iterator(mData + N); }
	Const_Iterator Begin() const { return Const_Iterator(mData); }
	Const_Iterator End() const { return Const_Iterator(mData + N); }

private:
	T* mData = nullptr;
};