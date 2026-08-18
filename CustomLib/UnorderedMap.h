#pragma once
#include <functional>
#include "Vector.h"

template<typename KeyType, typename ValueType>
class UnorderedMap
{
private:
	struct KeyValuePair
	{
		KeyType key;
		ValueType value;
	};

public:
	UnorderedMap(std::size_t initialBucketSize = 8, double loadFactor = 0.8)
		: mLoadFactorThreashhold(loadFactor), mCount(0)
	{
		mBucketCount = std::max<std::size_t>(initialBucketSize, 1);
		mTable.Resize(mBucketCount);
	}

	UnorderedMap(const UnorderedMap&) = delete;
	UnorderedMap(UnorderedMap&&) = delete;
	UnorderedMap& operator=(const UnorderedMap&) = delete;
	UnorderedMap& operator=(UnorderedMap&&) = delete;

	void Insert(const KeyType& key, const ValueType& value)
	{
		std::size_t index = GetTableIndex(key);
		Vector<KeyValuePair*>& bucket = mTable[index];
		for (size_t i = 0; i < mTable[index].size(); i++)
		{
			if (bucket[i]->key == key)
			{
				bucket[i]->value = value;
				return;
			}
		}
		KeyValuePair* kv = new KeyValuePair();
		kv->key = key;
		kv->value = value;
		mTable[index].PushBack(kv);
		++mCount;

		if ((double)mCount / (double)mBucketCount > mLoadFactorThreashhold)
		{
			Rehash();
		}
	}

	bool Find(const KeyType& key, ValueType& outValue) const
	{
		std::size_t index = GetTableIndex(key);
		const Vector<KeyValuePair*>& bucket = mTable[index];
		for (size_t i = 0; i < mTable[index].size(); i++)
		{
			if (bucket[i]->key == key)
			{
				outValue = bucket[i]->value;
				return true;
			}
		}
		return false;
	}

	bool Has(const KeyType& key) const
	{
		std::size_t index = GetTableIndex(key);
		const Vector<KeyValuePair*>& bucket = mTable[index];
		for (size_t i = 0; i < mTable[index].size(); i++)
		{
			if (bucket[i]->key == key)
			{
				return true;
			}
		}
		return false;
	}

	bool Remove(const KeyType& key)
	{
		std::size_t index = GetTableIndex(key);
		Vector<KeyValuePair*>& bucket = mTable[index];
		for (size_t i = 0; i < mTable[index].size(); i++)
		{
			if (bucket[i]->key == key)
			{
				KeyValuePair* tmp = bucket[i];
				bucket[i] = bucket[bucket.size() - 1];
				bucket[bucket.size() - 1] = tmp;
				delete tmp;
				tmp = nullptr;
				bucket.PopBack();
				mCount--;
				return true;
			}
		}
		return false;
	}

	std::size_t Count() const
	{
		return mCount;
	}

	void Clear()
	{
		for (size_t i = 0; i < mTable.size(); i++)
		{
			Vector<KeyValuePair*> bucket = mTable[i];
			for (size_t j = 0; j < bucket.size(); j++)
			{
				delete bucket[j];
				bucket[j] = nullptr;
			}
			bucket.Clear();
		}
		mCount = 0;
	}

	ValueType& operator[](const KeyType& key)
	{

		if (!Has(key))
		{
			Insert(key, mDefault);
		}

		std::size_t index = GetTableIndex(key);
		Vector<KeyValuePair*>& bucket = mTable[index];
		for (size_t i = 0; i < mTable[index].size(); i++)
		{
			if (bucket[i]->key == key)
			{
				return bucket[i]->value;
			}
		}
		return mTable[index][0]->value;
	}

	const ValueType& operator[](const KeyType& key) const
	{
		std::size_t index = GetTableIndex(key);
		Vector<KeyValuePair*>& bucket = mTable[index];
		for (size_t i = 0; i < mTable[index].size(); i++)
		{
			if (bucket[i]->key == key)
			{
				return bucket[i]->value;
			}
		}
	}

private:
	std::size_t GetTableIndex(const KeyType& key) const
	{
		return mHashFunction(key) % mBucketCount;
	}
	void Rehash()
	{
		std::size_t newBucketCount = mBucketCount * 2;
		Vector<Vector<KeyValuePair*>> newTable;
		newTable.Resize(newBucketCount);

		mBucketCount = newBucketCount;
		for (size_t i = 0; i < mTable.size(); i++)
		{
			Vector<KeyValuePair*>& bucket = mTable[i];
			for (size_t j = 0; j < bucket.size(); j++)
			{
				std::size_t index = GetTableIndex(bucket[j]->key);
				newTable[index].PushBack(bucket[j]);
			}
			bucket.Clear();
		}
		mTable = std::move(newTable);
		newTable.Clear();
	}

	ValueType mDefault;
	Vector<Vector<KeyValuePair*>> mTable;
	std::size_t mBucketCount = 0;
	std::size_t mCount = 0;

	double mLoadFactorThreashhold = 1.0;
	std::hash<KeyType> mHashFunction;
};