#include <iostream>
#include "List.h"

void Exercise1LinkedLists()
{
	List listOfNumbers;

	for (int i = 0; i < 20; i++)
	{
		listOfNumbers.AddToEnd(rand() % 100 + 1);
	}

	for (int i = 0; i < 20; i++)
	{
		std::cout << listOfNumbers[i] << std::endl;
	}
}

struct Vector2
{
	int x = 0;
	int y = 0;
};

struct KDNode
{
	Vector2 data;
	KDNode* left = nullptr;
	KDNode* right = nullptr;
};

void PrintDataAtHeightLevel(KDNode* node, int height, const std::string& side)
{
	if (node == nullptr)
	{
		return;
	}
	if (height == 0)
	{
		std::cout << side << "(" << node->data.x << ", " << node->data.y << ")\n";
	}
	else
	{
		PrintDataAtHeightLevel(node->left, height - 1, "L");
		PrintDataAtHeightLevel(node->right, height - 1, "R");
	}
}

void PrintTree(KDNode* tree)
{
	for (int i = 0; i < 30; i++)
	{
		PrintDataAtHeightLevel(tree, i, "Root");
	}
}

void DeleteTree(KDNode* node)
{
	if (node != nullptr)
	{
		DeleteTree(node->left);
		DeleteTree(node->right);
		delete node;
		node = nullptr;
	}
}

KDNode* Insert(const Vector2& data, KDNode* prevNode, int dim)
{
	if (prevNode == nullptr)
	{
		KDNode* node = new KDNode;
		node->data = data;
		return node;
	}
	if (prevNode->data.x == data.x && prevNode->data.y == prevNode->data.y)
	{
		std::cout << "ERROR: node has already been added\n";
	}
	if (dim == 0)
	{
		if (data.x < prevNode->data.x)
		{
			prevNode->left = Insert(data, prevNode->left, (dim + 1) % 2);
		}
		else
		{
			prevNode->right = Insert(data, prevNode->right, (dim + 1) % 2);
		}
	}
	else if (dim == 1)
	{
		if (data.y < prevNode->data.y)
		{
			prevNode->left = Insert(data, prevNode->left, (dim + 1) % 2);
		}
		else
		{
			prevNode->right = Insert(data, prevNode->right, (dim + 1) % 2);
		}
	}
	else
	{
		std::cout << "ERROR: dimension not set";
	}
	return prevNode;
}

Vector2 Minimum(const Vector2& a, const Vector2& b, const Vector2& c, int dim)
{
	int aDimValue = (dim == 0) ? a.x : a.y;
	int bDimValue = (dim == 0) ? b.x : b.y;
	int cDimValue = (dim == 0) ? c.x : c.y;
	if (aDimValue < bDimValue && aDimValue < cDimValue)
	{
		return a;
	}
	else if (bDimValue < cDimValue)
	{
		return b;
	}
	else
	{
		return c;
	}
}

Vector2 FindMin(KDNode* node, int dim, int cd)
{
	if (node == nullptr)
	{
		Vector2 invalid{
			INT_MAX,
			INT_MAX
		};
		return invalid;
	}
	int nextCD = (cd + 1) % 2;
	if (cd == dim)
	{
		if (node->left == nullptr)
		{
			return node->data;
		}

		return FindMin(node->left, dim, nextCD);
	}

	return Minimum(FindMin(node->left, dim, nextCD), FindMin(node->right, dim, nextCD), node->data, dim);
}

KDNode* DeleteNode(const Vector2& data, KDNode* node, int dim)
{
	if (node == nullptr)
	{
		std::cout << "[ERROR] Node was not found";
	}
	if (data.x < node->data.x && data.y == node->data.y)
	{
		if (node->right != nullptr)
		{
			node->data = FindMin(node->right, dim, (dim + 1) % 2);
			node->right = DeleteNode(node->data, node->right, (dim + 1) % 2);
		}
		else if (node->left != nullptr)
		{
			node->data = FindMin(node->left, dim, (dim + 1) % 2);
			node->right = DeleteNode(node->data, node->left, (dim + 1) % 2);
		}
		else
		{
			delete node;
			node = nullptr;
		}
	}
	else
	{
		if (dim == 0)
		{
			if (data.x < node->data.x)
			{
				node->left = DeleteNode(data, node->left, (dim + 1) % 2);
			}
			else
			{
				node->right = DeleteNode(data, node->right, (dim + 1) % 2);
			}
		}
		else
		{
			if (data.y < node->data.y)
			{
				node->left = DeleteNode(data, node->left, (dim + 1) % 2);
			}
			else
			{
				node->right = DeleteNode(data, node->right, (dim + 1) % 2);
			}
		}
	}
	return node;
}

void PrintRange(const Vector2& minRange, const Vector2& maxRange, KDNode* node, int dim)
{
	if (node == nullptr)
	{
		return;
	}
	if (node->data.x >= minRange.x && node->data.x <= maxRange.x && node->data.y >= minRange.y && node->data.y <= maxRange.y)
	{
		std::cout << "(" << node->data.y << ", " << node->data.y << ")\n";
	}
	int nextDim = (dim + 1) % 2;
	if (dim == 0)
	{
		if (minRange.x <= node->data.x)
		{
			PrintRange(minRange, maxRange, node->left, nextDim);
		}
		else if (minRange.x <= maxRange.x)
		{
			PrintRange(minRange, maxRange, node->right, nextDim);
		}
	}
	else
	{
		if (minRange.y <= node->data.y)
		{
			PrintRange(minRange, maxRange, node->left, nextDim);
		}
		else if (minRange.y <= maxRange.y)
		{
			PrintRange(minRange, maxRange, node->right, nextDim);
		}
	}
}

void Exercise2KDTrees()
{
	KDNode* root = nullptr;
	Vector2 data;
	for (int i = 0; i < 20; i++)
	{
		data.x = rand() % 100 + 1;
		data.y = rand() % 100 + 1;
		KDNode* newNode = Insert(data, root, 0);
		if (root == nullptr)
		{
			root = newNode;
		}
	}
	PrintTree(root);

	Vector2 minX = FindMin(root, 0, 0);
	Vector2 minY = FindMin(root, 1, 0);

	std::cout << "\n\n\n";

	std::cout << "MinX: " << "(" << minX.x << ", " << minX.y << ")\n";
	std::cout << "MinY: " << "(" << minY.x << ", " << minY.y << ")\n";

	std::cout << "\n\n\n";

	Vector2 minRange{ 30, 30 };
	Vector2 maxRange{ 70, 70 };
	PrintRange(minRange, maxRange, root, 0);

	DeleteTree(root);
}

int main()
{
	srand(time(NULL));

	Exercise2KDTrees();

	return 0;
}