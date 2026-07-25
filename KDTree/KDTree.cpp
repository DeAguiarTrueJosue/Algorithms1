#include <iostream>
#include <KDTree.h>
#include <Vector2.h>
#include <string>
#include <Names.h>

enum ItemType
{
    IT_HEALTH,
    IT_WELLNESS,
    IT_MONEY,
    IT_COUNT
};

struct Item
{
    std::string name;
    ItemType itemType;
    Vector2 position;

    struct FilterByType
    {
        ItemType itemType;
        bool operator()(const void* data)
        {
            const Item* item = (const Item*)data;
            return item->itemType == itemType;
        }
    };
};

int main()
{
    srand(time(NULL));
    Vector<Item> items;
    KDTree<float, 2> tree;

    int maxItems = 100;
    items.Resize(maxItems);

    for (int i = 0; i < maxItems; i++)
    {
        items[i].name = GetRandomName();
        items[i].itemType = (ItemType)(rand() % IT_COUNT);
        items[i].position.x = rand() % 501;
        items[i].position.y = rand() % 501;
        tree.AddItem(&items[i].position.x, &items[i]);
    }

    tree.BuildTree();

    Vector2 minRange = { 200, 200 };
    Vector2 maxRange = { 400, 400 };
    Item::FilterByType filter;
    filter.itemType = IT_MONEY;
    Vector<const void*> itemsInRange;
    for (int i = 0; i < tree.data().size(); i++)
    {
        Item* item = (Item*)((tree.data()[i]->userData));
        std::cout << "Item: " << item->name << " (" << item->position.x << ", " << item->position.y << ")\n";
    }
    tree.FindInRange(itemsInRange, &minRange.x, &maxRange.x, filter);
    std::cout << "\n\n";
    for (auto iter = itemsInRange.Begin(); iter != itemsInRange.End(); ++iter)
    {
        const Item* item = (const Item*)(*iter);
        std::cout << "Item In Range: " << item->name << " (" << item->position.x << ", " << item->position.y << ")\n";
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
