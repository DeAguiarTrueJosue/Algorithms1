#pragma once

#include <algorithm>
#include <iterator>
#include <cstddef>

template<typename T>
class ContainerIterator
{
public:
	using iterator_category = std::random_access_iterator_tag;
	using value_type = T;
	using difference_type = std::ptrdiff_t;
	using pointer = T*;
	using reference = T&;

public:
	ContainerIterator(T* ptr) : mPtr(ptr) {};

	T& operator*() { return *mPtr; }
	T* operator->() { return mPtr; }

	ContainerIterator& operator++() { ++mPtr; return *this; }
	ContainerIterator& operator--() { --mPtr; return *this; }
	ContainerIterator operator++(int) { ContainerIterator tmp = *this; ++mPtr; return tmp; }
	ContainerIterator operator--(int) { ContainerIterator tmp = *this; --mPtr; return tmp; }

	ContainerIterator operator+(difference_type n) const { return ContainerIterator(mPtr + n); }
	ContainerIterator operator-(difference_type n) const { return ContainerIterator(mPtr - n); }

	ContainerIterator& operator+=(difference_type n) const { mPtr += n; return *this; }
	ContainerIterator& operator-=(difference_type n) const { mPtr -= n; return *this; }

	difference_type operator-(const ContainerIterator& rhs) const { return mPtr - rhs.mPtr; }

	bool operator==(const ContainerIterator& rhs) const { return mPtr == rhs.mPtr; }
	bool operator!=(const ContainerIterator& rhs) const { return mPtr != rhs.mPtr; }
	bool operator>(const ContainerIterator& rhs) const { return mPtr > rhs.mPtr; }
	bool operator<(const ContainerIterator& rhs) const { return mPtr < rhs.mPtr; }
	bool operator>=(const ContainerIterator& rhs) const { return mPtr >= rhs.mPtr; }
	bool operator<=(const ContainerIterator& rhs) const { return mPtr <= rhs.mPtr; }

private:
	T* mPtr;
};