#include <iostream>
#include <vector>
void InsertionSort(std::vector<int>& vec) {
	for (int i = 1; i < vec.size(); i++)
	{
		int key = vec[i];

		int j = i - 1;
		while (j >= 0) {
			if (vec[j] > key) {
				vec[j + 1] = vec[j];
				--j;
			}
			else {
				break;
			}
		}
		vec[j + 1] = key;
	}
}
void Exercise1() {
	std::vector<int> vec;
	for (size_t i = 0; i < 20; i++)
	{
		int value = 1 + (rand() % 100);
		vec.push_back(value);
		std::cout << value << " ";
	}
	std::cout << "\n";
	InsertionSort(vec);
	for (size_t i = 0; i < 20; i++)
	{
		std::cout << vec[i] << " ";
	}
}
void Merge(std::vector<int>& vec, int left, int midPoint, int right) {
	int leftSize = (midPoint - left) + 1;
	int rigthSize = (right - midPoint);

	std::vector<int> tempLeft(leftSize);
	std::vector<int> tempRight(rigthSize);
	for (int i = 0; i < leftSize; i++)
	{
		tempLeft[i] = vec[left + i];
	}
	for (int i = 0; i < rigthSize; i++)
	{
		tempRight[i] = vec[midPoint + i + 1];
	}
	int leftIndex = 0;
	int rightIndex = 0;
	int vecIndex = left;

	while (leftIndex < leftSize && rightIndex < rigthSize) {
		if (tempLeft[leftIndex] < tempRight[rightIndex]) {
			vec[vecIndex] = tempLeft[leftIndex];
			++leftIndex;
		}
		else {
			vec[vecIndex] = tempRight[rightIndex];
			++rightIndex;
		}
		++vecIndex;
	}
	while (leftIndex < leftSize) {
		vec[vecIndex] = tempLeft[leftIndex];
		++leftIndex;
		++vecIndex;
	}
	while (rightIndex < rigthSize) {
		vec[vecIndex] = tempRight[rightIndex];
		++rightIndex;
		++vecIndex;
	}
}
void MergeSort(std::vector<int>& vec, int left, int right) {
	if (left < right) {
		int midPoint = left + ((right - left) / 2);
		MergeSort(vec, left, midPoint);
		MergeSort(vec, midPoint + 1, right);
		Merge(vec, left, midPoint, right);
	}
}
void Exercise2() {
	std::vector<int> vec;
	for (size_t i = 0; i < 20; i++)
	{
		int value = 1 + (rand() % 100);
		vec.push_back(value);
		std::cout << value << " ";
	}
	std::cout << "\n";
	MergeSort(vec, 0, vec.size() - 1);
	for (size_t i = 0; i < 20; i++)
	{
		std::cout << vec[i] << " ";
	}
}

void Swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
	//a = b + a;
	//b = a - b;
	//a = a - b;
}
int Partition(std::vector<int>& vec, int left, int right) {
	int pivot = vec[right];
	int i = left - 1;
	for (int j = left; j < right; ++j) {
		if (vec[j] < pivot) {
			++i;
			Swap(vec[i], vec[j]);
		}
	}
	Swap(vec[i + 1], vec[right]);
	return i + 1;
}
void QuickSort(std::vector<int>& vec, int left, int right) {
	if (left < right) {
		int p = Partition(vec, left, right);
		QuickSort(vec, left, p - 1);
		QuickSort(vec, p + 1, right);
	}
}
void Exercise3() {
	std::vector<int> vec;
	for (size_t i = 0; i < 20; i++)
	{
		int value = 1 + (rand() % 100);
		vec.push_back(value);
		std::cout << value << " ";
	}
	std::cout << "\n";
	QuickSort(vec, 0, vec.size() - 1);
	for (size_t i = 0; i < 20; i++)
	{
		std::cout << vec[i] << " ";
	}
}

int main()
{
	Exercise3();
}