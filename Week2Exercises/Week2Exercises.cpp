#include <iostream>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <concurrent_priority_queue.h>
#include <string>
#include <chrono>
#include <Names.h>

#pragma region ClockWorks
std::chrono::steady_clock::time_point begin;
void StartClock()
{
	begin = std::chrono::high_resolution_clock::now();
}

float StopClock()
{
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
	return duration;
}

std::string DisplayTime(float time)
{
	return "Total time:" + std::to_string(StopClock());
}
#pragma endregion

#pragma region Exercise1 Screens
void GoToScreen(const std::string& screenName, std::array<std::string, 10>& screens)
{
	for (size_t i = 0; i < screens.size(); i++)
	{
		if (screens[i].empty())
		{
			screens[i] = screenName;
			break;
		}
	}
	std::cout << "Screen Added: " << screenName << "\n";
}

void GoToScreen(const std::string& screenName, std::vector<std::string>& screens)
{
	screens.push_back(screenName);
	std::cout << "Screen Added: " << screenName << "\n";
}

void GoToScreen(const std::string& screenName, std::stack<std::string>& screens)
{
	screens.push(screenName);
	std::cout << "Screen Added: " << screenName << "\n";
}

void GoBack(std::array<std::string, 10>& screens)
{
	for (int i = screens.size() - 1; i >= 0; i--)
	{
		if (!screens[i].empty())
		{
			std::cout << "Go Back From: " << screens[i] << "\n";
			screens[i] = "";
			if (i > 0)
			{
				std::cout << "Is On Screen: " << screens[i - 1] << "\n";
			}
			break;
		}
	}
}

void GoBack(std::vector<std::string>& screens)
{
	std::cout << "Go Back From: " << screens.back() << "\n";
	screens.pop_back();
	if (!screens.empty())
	{
		std::cout << "Is On Screen: " << screens.back() << "\n";
	}
}

void GoBack(std::stack<std::string>& screens)
{
	std::cout << "Go Back From: " << screens.top() << "\n";
	screens.pop();
	if (!screens.empty())
	{
		std::cout << "Is On Screen: " << screens.top() << "\n";
	}
}

void Exercise1ScreenFlow()
{
	std::cout << "Screen Flow\n\n";
	std::array<std::string, 10> arrayScreens;
	std::vector<std::string> vectorScreens;
	std::stack<std::string> stackScreens;

	std::cout << "Array: \n";
	StartClock();
	GoToScreen("MainMenu", arrayScreens);
	GoToScreen("Game", arrayScreens);
	GoToScreen("GameOver", arrayScreens);
	GoBack(arrayScreens);
	GoBack(arrayScreens);
	GoBack(arrayScreens);
	std::cout << DisplayTime(StopClock()) << "\n\n";

	std::cout << "Vector: \n";
	StartClock();
	GoToScreen("MainMenu", vectorScreens);
	GoToScreen("Game", vectorScreens);
	GoToScreen("GameOver", vectorScreens);
	GoBack(vectorScreens);
	GoBack(vectorScreens);
	GoBack(vectorScreens);
	std::cout << DisplayTime(StopClock()) << "\n\n";

	std::cout << "Stack: \n";
	StartClock();
	GoToScreen("MainMenu", stackScreens);
	GoToScreen("Game", stackScreens);
	GoToScreen("GameOver", stackScreens);
	GoBack(stackScreens);
	GoBack(stackScreens);
	GoBack(stackScreens);
	std::cout << DisplayTime(StopClock()) << "\n\n";
}
#pragma endregion

#pragma region Exercise2 Tickets

void EnterLine(const std::string& personName, std::array<std::string, 10>& people)
{
	for (size_t i = 0; i < people.size(); i++)
	{
		if (people[i].empty())
		{
			people[i] = personName;
			break;
		}
	}
	std::cout << "Person Added: " << personName << "\n";
}

void EnterLine(const std::string& personName, std::vector<std::string>& people)
{
	people.push_back(personName);
	std::cout << "Person Added: " << personName << "\n";
}

void EnterLine(const std::string& personName, std::queue<std::string>& people)
{
	people.push(personName);
	std::cout << "Person Added: " << personName << "\n";
}

void PurchaseTicket(std::array<std::string, 10>& people)
{
	std::cout << people[0] << " Paid" << "\n";
	for (int i = 0; i < people.size() - 1; i++)
	{
		people[i] = people[i + 1];
	}
	people[people.size() - 1] = "";
}

void PurchaseTicket(std::vector<std::string>& people)
{
	std::cout << people[0] << " Paid" << "\n";
	people.erase(people.begin());
}

void PurchaseTicket(std::queue<std::string>& people)
{
	std::cout << people.front() << " Paid" << "\n";
	people.pop();
}

void Exercise2MovieTickets()
{
	std::array<std::string, 10> arrayPeople;
	std::vector<std::string> vectorPeople;
	std::queue<std::string> queuePeople;

	std::cout << "Array: \n";
	StartClock();
	EnterLine("MainMenu", arrayPeople);
	EnterLine("Game", arrayPeople);
	EnterLine("GameOver", arrayPeople);
	PurchaseTicket(arrayPeople);
	PurchaseTicket(arrayPeople);
	PurchaseTicket(arrayPeople);
	std::cout << DisplayTime(StopClock()) << "\n\n";

	std::cout << "Vector: \n";
	StartClock();
	EnterLine("MainMenu", vectorPeople);
	EnterLine("Game", vectorPeople);
	EnterLine("GameOver", vectorPeople);
	PurchaseTicket(vectorPeople);
	PurchaseTicket(vectorPeople);
	PurchaseTicket(vectorPeople);
	std::cout << DisplayTime(StopClock()) << "\n\n";

	std::cout << "Stack: \n";
	StartClock();
	EnterLine("MainMenu", queuePeople);
	EnterLine("Game", queuePeople);
	EnterLine("GameOver", queuePeople);
	PurchaseTicket(queuePeople);
	PurchaseTicket(queuePeople);
	PurchaseTicket(queuePeople);
	std::cout << DisplayTime(StopClock()) << "\n\n";
}

#pragma endregion

#pragma region Exercise3.1PQ

void Exercise3P1PQ()
{
	std::priority_queue<int, std::vector<int>, std::less<int>> priorityQueue;
	int maxNumbers = 10;
	int minRange = 1;
	int maxRange = 200;
	std::cout << "AddingNumbers\n\n";

	for (size_t i = 0; i < maxNumbers; i++)
	{
		int value = minRange + (rand() % (maxRange - minRange + 1));
		std::cout << std::to_string(value) << "\n";
		priorityQueue.push(value);
	}

	std::cout << "\nPopping\n\n";
	
	while (!priorityQueue.empty())
	{
		std::cout << priorityQueue.top() << "\n";
		priorityQueue.pop();
	}
}


#pragma endregion

#pragma region Exercise3.2 Marks

class Student
{
public:
	Student() : mAge(0), mMark(0)
	{

	};
	Student(const std::string& firstName, const std::string& lastName, int age, int mark)
		: mFirstName(firstName), mLastName(lastName), mAge(age), mMark(mark) {};
	~Student() = default;

	bool operator<(const Student& rhs) const
	{
		if (mLastName == rhs.mLastName)
		{
			return rhs.mFirstName < mFirstName;
		}
		return mLastName < rhs.mLastName;
	}

	bool operator>(const Student& rhs) const
	{
		return mLastName > rhs.mLastName;
	}

	std::string Display() const
	{
		return std::to_string(mAge) + "yo " + mLastName + ", " + mFirstName + ": " + std::to_string(mMark);
	}

	struct CompareMarkAscending
	{
		bool operator()(const Student& lhs, const Student& rhs)
		{
			return lhs.mMark > rhs.mMark;
		}
	};
	struct CompareMarkDecending
	{
		bool operator()(const Student& lhs, const Student& rhs)
		{
			return lhs.mMark < rhs.mMark;
		}
	};

private:
	std::string mFirstName;
	std::string mLastName;
	int mAge;
	int mMark;
};

void Exercise3P2StudantMarks()
{
	std::priority_queue<Student, std::vector<Student>, Student::CompareMarkAscending> students;

	for (size_t i = 0; i < 50; i++)
	{
		students.push(Student(GetRandomName(), GetRandomName(), rand() % 16 + 15, rand() % 61 + 40));
	}

	while (!students.empty())
	{
		std::cout << students.top().Display() << "\n";
		students.pop();
	}
}

#pragma endregion


int main()
{
	srand(time(NULL));

	Exercise3P2StudantMarks();
}
