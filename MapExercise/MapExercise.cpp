// MapExercise.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Vector.h>
#include <Map.h>

int main()
{
    std::cout << "Custom Map\n";
    Map<int, int> myIntMap;
    for (int i = 0; i < 20; i++)
    {
        int value = rand() % 1000;
        myIntMap.Insert(i, value);
        std::cout << value << " ";
    }
    std::cout << "\n";
    std::cout << "My Values at 3: " << myIntMap[3] << "\n";
    std::cout << "My Values at 7: " << myIntMap[7] << "\n";

    std::cout << "Map Keys:\n";
    Vector<int> keys;
    myIntMap.ObtainKeys(keys);
    for (int i = 0; i < keys.size(); i++)
    {
        std::cout << keys[i] << " ";
    }
    std::cout << "\n";
    std::cout << "Remove 6:\n";
    myIntMap.Remove(6);
    keys.Clear();
    myIntMap.ObtainKeys(keys);
    for (int i = 0; i < keys.size(); i++)
    {
        std::cout << "Key: " << keys[i] << " Value: " << myIntMap[keys[i]] << "\n";
    }
}