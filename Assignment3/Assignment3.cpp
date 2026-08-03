#include <iostream>
#include <Vector3.h>
#include <Vector.h>
#include <KDTree.h>

std::string nameTypes[5] = { "Health", "Weapon Ammo", "Coins", "Upgrade", "Special Item" };

enum PickUpType
{
	Invalid = -1,
	Health,
	WeaponAmmo,
	Coins,
	Upgrade,
	SpecialItem
};

struct PickUp
{
	PickUp() {}
	PickUp(PickUpType type, const Vector3& pos) : type(type), name(nameTypes[type]), position(pos) {}

	PickUpType type;
	std::string name;
	Vector3 position;

	struct FilterByType
	{
		PickUpType itemType;
		bool operator()(const void* data)
		{
			const PickUp* item = (const PickUp*)data;
			return item->type == itemType || itemType == Invalid;
		}
	};
};

class PickUpManager
{
public:

	void AddItem(const PickUp& value)
	{
		mPickUps.PushBack(value);
		mTree.AddItem(&mPickUps[mPickUps.size() - 1].position.x, &mPickUps[mPickUps.size() - 1]);
	}

	const PickUp* GetClosestPickUp(const Vector3& pos)
	{
		return (PickUp*)(mTree.FindNearest(&pos.x));
	}

	const Vector<PickUp*> ObtainPickupsInRange(const Vector3& pos, float range, PickUpType pickupType)
	{
		PickUp::FilterByType filter;
		filter.itemType = pickupType;
		Vector<const void*> datasInRange;
		Vector3 zero = { pos.x - range, pos.y - range, pos.z - range };
		Vector3 next = { pos.x + range, pos.y + range, pos.z + range };
		mTree.FindInRange(datasInRange, &zero.x, &next.x, filter);
		Vector<PickUp*> pickUpsInRange;
		pickUpsInRange.Resize(datasInRange.size());
		for (size_t i = 0; i < datasInRange.size(); i++)
		{
			pickUpsInRange[i] = (PickUp*)(datasInRange[i]);
		}
		return pickUpsInRange;
	}

	Vector<PickUp> mPickUps;
	KDTree<float, 3> mTree;
};

int main()
{
	srand(time(NULL));
	PickUpManager manager;
	manager.mPickUps.Reserve(128);
	for (size_t i = 0; i < 100; i++)
	{
		Vector3 pos = { float(rand() % 51), float(rand() % 51), float(rand() % 51) };
 		PickUp pickUp((PickUpType)(rand() % 5), pos);
		manager.AddItem(pickUp);
	}

	manager.mTree.BuildTree();

	Vector3 player;

	std::cout << "Choose Your Location (0 - 50)\n";
	std::cout << "x: ";
	std::cin >> player.x;
	std::cout << "y: ";
	std::cin >> player.y;
	std::cout << "z: ";
	std::cin >> player.z;

	std::cout << "\n";

	std::cout << "Items In Range 10:\n";
	Vector<PickUp*> foundInRange = manager.ObtainPickupsInRange(player, 10, Invalid);
	for (size_t i = 0; i < foundInRange.size(); i++)
	{
		std::cout << foundInRange[i]->name << ": (" << foundInRange[i]->position.x << ", "
			<< foundInRange[i]->position.y << ", " << foundInRange[i]->position.z << ")\n";
	}

	std::cout << "\nHealth Items In Range 50:\n";
	foundInRange = manager.ObtainPickupsInRange(player, 50, Health);
	for (size_t i = 0; i < foundInRange.size(); i++)
	{
		std::cout << foundInRange[i]->name << ": (" << foundInRange[i]->position.x << ", "
			<< foundInRange[i]->position.y << ", " << foundInRange[i]->position.z << ")\n";
	}

	std::cout << "\nClosest PickUp:\n";
	const PickUp* closestPickUp = manager.GetClosestPickUp(player);
	std::cout << closestPickUp->name << ": (" << closestPickUp->position.x << ", "
		<< closestPickUp->position.y << ", " << closestPickUp->position.z << ")\n";
}