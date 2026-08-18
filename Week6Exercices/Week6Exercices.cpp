#include <iostream>
#include <array>
#include <vector>
#include <string>

class Texture
{
public:
	Texture() : mPixelColors(nullptr) {}
	~Texture()
	{
		if (mPixelColors != nullptr)
		{
			delete[] mPixelColors;
			mPixelColors = nullptr;
		}
	}

	void Initiaize(const std::string& filePath, int size)
	{
		mFilePath = filePath;
		mPixelColors = new float[size * size * 4];
	}

	const std::string& GetFilePath() const
	{
		return mFilePath;
	}

private:
	std::string mFilePath;
	float* mPixelColors = nullptr;
};

class TextureCache
{
private:
	static const int MAX_HASH_SIZE = 1000;
	struct Node
	{
		Texture* data = nullptr;
		Node* next = nullptr;
	};

public:

	int HashFunctionW6E(const std::string& key)
	{
		int hashValue = 0;
		for (int i = 0; i < key.size(); i++)
		{
			int value = (int)key[i];
			hashValue = (hashValue * 256 + value) % MAX_HASH_SIZE;
		}
		return hashValue;
	}

	void InsertTexture(const std::string& filePath)
	{
		int arrayIndex = HashFunctionW6E(filePath);
		Node* tmp = mHashTable[arrayIndex];
		while (tmp != nullptr)
		{
			if (tmp->data->GetFilePath() == filePath)
			{
				std::cout << "Texture \"" << filePath << "\" is already added\n";
				return;
			}
			tmp = tmp->next;
		}
		Texture* newTexture = new Texture();
		newTexture->Initiaize(filePath, 100 + (rand() % 157));
		Node* newNode = new Node();
		newNode->data = newTexture;
		newNode->next = mHashTable[arrayIndex];
		mHashTable[arrayIndex] = newNode;
	}

	const Texture* FindTexture(const std::string& filePath)
	{
		int arrayIndex = HashFunctionW6E(filePath);
		Node* foundNode = mHashTable[arrayIndex];
		while (foundNode != nullptr)
		{
			if (foundNode->data->GetFilePath() == filePath)
			{
				return foundNode->data;
			}
			foundNode = foundNode->next;
		}
		return nullptr;
	}

	void DeleteTexture(const std::string& filePath)
	{
		int arrayIndex = HashFunctionW6E(filePath);
		Node* node = mHashTable[arrayIndex];
		Node* prev = nullptr;
		while (node != nullptr)
		{
			if (node->data->GetFilePath() == filePath)
			{
				if (prev != nullptr)
				{
					prev->next = node->next;
				}
				else
				{
					mHashTable[arrayIndex]->next = node->next;
				}

				std::cout << "Texture \"" << filePath << "\" was deleted\n";
				delete node->data;
				node->data = nullptr;
				delete node;
				node = nullptr;
				break;
			}
			prev = node;
			node = node->next;
		}
	}

	void PrintTable()
	{
		for (int i = 0; i < MAX_HASH_SIZE; i++)
		{
			Node* node = mHashTable[i];
			while (node != nullptr)
			{
				std::cout << i << " > " << node->data->GetFilePath() << "\n";
				node = node->next;
			}
		}
	}

private:
	std::array<Node*, MAX_HASH_SIZE> mHashTable = { nullptr };
};

void Exercise1()
{
	TextureCache myTextureCache;
	std::vector<std::string> directories = {
		"/Models/Textures/",
		"/UI/Textures/",
		"/Gameplay/Textures/",
		"/Enviroment/Textures/"
	};

	int maxTextures = 100;

	for (int i = 0; i < maxTextures; i++)
	{
		int dirIndex = rand() % directories.size();
		std::string fullPath = directories[dirIndex] + "TextureName_" + std::to_string(i);
		myTextureCache.InsertTexture(fullPath);
	}
	myTextureCache.PrintTable();

}

template<typename T>
void Swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
void BubbleSort(std::vector<T>& v)
{
	for (size_t i = 0; i < v.size() - 1; i++)
	{
		for (size_t j = 0; j < v.size() - i - 1; j++)
		{
			if (v[j] > v[j + 1])
			{
				Swap(v[j], v[j + 1]);
			}
		}
	}
}

template<typename T>
void SelectionSort(std::vector<T>& v)
{
	std::vector<T> newV;
	for (size_t i = 0; i < v.size() - 1; i++)
	{
		int index = i;
		for (size_t j = i + 1; j < v.size(); j++)
		{
			if (v[j] < v[index])
			{
				index = j;
			}
		}
		if (index != i)
		{
			Swap(v[index], v[i]);
		}
	}
}

class City
{
public:
	City(std::string name, int distance) : mName(name), mDistanceFromHere(distance) {};

	void Print()
	{
		std::cout << mName << " is " << mDistanceFromHere << "m from here\n";
	}

	bool operator<(const City& rhs)
	{
		return mDistanceFromHere < rhs.mDistanceFromHere;
	}

	bool operator>(const City& rhs)
	{
		return mDistanceFromHere > rhs.mDistanceFromHere;
	}

private:
	std::string mName = "";
	int mDistanceFromHere = 0;
};

void Exercise4()
{
	std::vector<City> cities;
	cities.push_back(City("Vancouver", 0));
	cities.push_back(City("Burnaby", 200));
	cities.push_back(City("North_Vancouver", 1500));
	cities.push_back(City("Delta", 2000));
	cities.push_back(City("Richmond", 1800));
	cities.push_back(City("New_West", 5000));
	cities.push_back(City("Coquitlam", 4500));
	cities.push_back(City("Victoria", 25000));
	cities.push_back(City("Naniamo", 40000));
	cities.push_back(City("Quiznel", 100000));
	cities.push_back(City("Langley", 10000));
	cities.push_back(City("Abbotsford", 12000));
	cities.push_back(City("Maple_Ridge", 9000));
	cities.push_back(City("Port_Coquitlam", 4000));
	cities.push_back(City("Surrey", 6000));

	SelectionSort(cities);

	for (size_t i = 0; i < cities.size(); i++)
	{
		cities[i].Print();
	}

}

int main()
{
	srand(time(NULL));
	std::cout << "Sorting and Unordermap\n";
	Exercise4();
}