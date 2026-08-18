#pragma once
#ifndef __GLOBAL_H_INCLUDED__
#define __GLOBAL_H_INCLUDED__

#include <string>
#include "Vector.h"

namespace Global
{
	inline std::size_t HashFunction(const std::string& str)
	{
		std::size_t hash = 0;
		for (size_t i = 0; i < str.size(); i++)
		{
			hash = (~hash << i) + (std::size_t)(str[i]);
		}
		return hash;
	}

	template<typename T>
	inline void Swap(T& a, T& b)
	{
		T tmp = a;
		a = b;
		b = tmp;
	}

	template<typename T, typename Compare = std::less<typename T>>
	inline void BubbleSort(Vector<T>& values, Compare sortFunc = Compare{})
	{
		std::size_t size = values.size();
		for (size_t i = 0; i < size - 1; i++)
		{
			for (size_t j = 0; j < size - 1 - i; j++)
			{
				if (sortFunc(values[j + 1], values[j]))
				{
					Swap(values[j + 1], values[j]);
				}
			}
		}
	}

	template<typename T, typename Compare = std::less<typename T>>
	inline void SelectionSort(Vector<T>& values, Compare sortFunc = Compare{})
	{
		std::size_t size = values.size();
		for (size_t i = 0; i < size - 1; i++)
		{
			std:size_t minIndex = i;
			for (size_t j = i + 1; j < size; j++)
			{
				if (sortFunc(values[j], values[minIndex]))
				{
					minIndex = j;
				}
			}
			if (i != minIndex)
			{
				Swap(values[i], values[minIndex]);
			}
		}
	}
}
#endif // !__GLOBAL_H_INCLUDED__