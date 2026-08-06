#include <iostream>
#include <Vector.h>
#include <KDTree.h>
#include <Vector2.h>
#include <PriorityQueue.h>

#pragma region E1
void Constant(Vector<Vector2>& v)
{
	std::cout << "{" << v[0].x << ", " << v[0].y << "}";
}

void Linear(Vector<Vector2>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << "{" << v[i].x << ", " << v[i].y << "} ";
	}
}

void Log(KDTree<float, 2>& t)
{
	t.BuildTree();
	Vector2 v2 = { 10, 20 };
	Vector2* v2p = (Vector2*)(t.FindNearest(&v2.x));
	std::cout << "{" << v2p->x << ", " << v2p->y << "}";
}

void Exercise1()
{
	Vector<Vector2> numbersv;
	KDTree<float, 2> numberst;
	for (int i = 0; i < 100; i++)
	{
		numbersv.PushBack({ float(rand() % 101), float(rand() % 101) });
		numberst.AddItem(&numbersv[i].x, &numbersv[i]);
	}

	Constant(numbersv);

	std::cout << "\n\n";

	Linear(numbersv);

	std::cout << "\n\n";

	Log(numberst);
}
#pragma endregion

#pragma region E2
void Index(Vector<int>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << " ";
	}
}

void Iteration(Vector<int>& v)
{
	for (auto i = v.Begin(); i != v.End(); i++)
	{
		std::cout << *i << " ";
	}
}

void Recursion(Vector<int>& v, int position)
{
	if (position >= v.size())
	{
		return;
	}
	std::cout << v[position] << " ";
	Recursion(v, position + 1);
}

void Exercise2()
{
	Vector<int> numbers;
	for (int i = 0; i < 100; i++)
	{
		numbers.PushBack(rand() % 101);
	}

	Index(numbers);

	std::cout << "\n\n";

	Iteration(numbers);

	std::cout << "\n\n";

	Recursion(numbers, 0);
}
#pragma endregion

#pragma region E3
class House
{
public:
	int price = 0;
	int squareFoot = 0;
	int rooms = 0;
	int distance = 0;

	void Print()
	{
		std::cout << "Cost:    $" << price << "\nSF:       " << squareFoot <<
			" sf\nRooms:    " << rooms << "\nDistance: " << distance << "m\n";
	}
	struct SortByPrice
	{
		bool operator()(const House& a, const House& b)
		{
			return a.price < b.price;
		}
	};
	struct SortBySquareFoot
	{
		bool operator()(const House& a, const House& b)
		{
			return a.squareFoot < b.squareFoot;
		}
	};
	struct SortByRooms
	{
		bool operator()(const House& a, const House& b)
		{
			return a.rooms < b.rooms;
		}
	};
	struct SortByDistance
	{
		bool operator()(const House& a, const House& b)
		{
			return a.distance < b.distance;
		}
	};
};

class HouseListing
{
public:
	void ListHouses(const House& house)
	{
		mHouses.PushBack(house);
	}
	template<typename T>
	void PrintWithCriteria()
	{
		PriorityQueue<House, T> queue;
		for (int i = 0; i < mHouses.size(); i++)
		{
			queue.Push(mHouses[i]);
		}
		while (!queue.Empty())
		{
			queue.Top().Print();
			std::cout << "\n";
			queue.Pop();
		}
	}
public:
	Vector<House> mHouses;
};

void Exercise3()
{
	HouseListing hl;

	for (int i = 0; i < 20; i++)
	{
		House h;
		h.squareFoot = rand() % 1101 + 400;
		h.rooms = sqrt(h.squareFoot) * 0.1f + (rand() % 2);
		h.distance = rand() % 10001;
		h.price = h.rooms * h.squareFoot * 1000 + h.squareFoot * h.squareFoot - h.distance * 100;
		hl.ListHouses(h);
	}

	hl.PrintWithCriteria<House::SortByPrice>();
}
#pragma endregion

#pragma region E4



void Exercise4() {

}
#pragma endregion


int main()
{
	srand(time(NULL));

	Exercise3();
}