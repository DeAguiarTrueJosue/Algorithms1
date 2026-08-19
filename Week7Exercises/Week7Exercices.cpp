#include <iostream>
#include <Vector.h>

struct Node
{
	int data = 0;
	Node* left = nullptr;
	Node* right = nullptr;
};

Node* CreateNode(int data)
{
	Node* newNode = new Node();
	newNode->data = data;
	return newNode;
}

Node* Insert(Node* node, int data)
{
	if (node == nullptr)
	{
		return CreateNode(data);
	}
	if (data < node->data)
	{
		node->left = Insert(node->left, data);
	}
	else if (data > node->data)
	{
		node->right = Insert(node->right, data);
	}
	return node;
}

bool Search(Node* node, int data)
{
	if (node == nullptr)
	{
		return false;
	}
	else if (node->data == data)
	{
		return true;
	}
	if (data < node->data)
	{
		return Search(node->left, data);
	}
	else
	{
		return Search(node->right, data);
	}
}

Node* GetMinNode(Node* node) {
	Node* minNode = node;
	while (minNode != nullptr && minNode->left != nullptr) {
		minNode = minNode->left;
	}
	return minNode;

}
Node* GetMaxNode(Node* node) {
	Node* maxNode = node;
	while (maxNode != nullptr && maxNode->right != nullptr) {
		maxNode = maxNode->right;
	}
	return maxNode;
}

Node* Delete(Node* node, int data) {
	if (node == nullptr) {
		return node;
	}
	if (data < node->data) {
		node->left = Delete(node->left, data);
	}
	else if (data > node->data) {
		node->right = Delete(node->right, data);
	}
	else {
		if (node->left == nullptr) {
			Node* tmp = node->right;
			delete node;
			node = nullptr;
			return tmp;
		}
		if (node->right == nullptr) {
			Node* tmp = node->left;
			delete node;
			node = nullptr;
			return tmp;
		}
		Node* tmp = GetMinNode(node->right);
		node->data = tmp->data;
		node->right = Delete(node->right, tmp->data);
	}
	return node;
}

void PrintInOrder(Node* node)
{
	if (node != nullptr)
	{
		PrintInOrder(node->left);
		std::cout << node->data << " ";
		PrintInOrder(node->right);
	}
}

void PrintInReverseOrder(Node* node)
{
	if (node != nullptr)
	{
		PrintInReverseOrder(node->right);
		std::cout << node->data << " ";
		PrintInReverseOrder(node->left);
	}
}

int GenerateIPAddress()
{
	int address = (rand() % 9) + 1;
	for (size_t i = 0; i < 7; i++)
	{
		address = (address * 10) + (rand() % 10);
	}
	return address;
}

void Exercise1BST()
{
	Vector<int> addresss;
	Node* bstRoot = nullptr;
	int maxNumbers = 20;
	for (size_t i = 0; i < maxNumbers; i++)
	{
		int address = GenerateIPAddress();
		bstRoot = Insert(bstRoot, address);
		std::cout << address << " ";
		if (rand() % 2 == 0)
		{
			addresss.PushBack(address);
		}
	}
	std::cout << "\n\n";
	std::cout << "Print in order\n";
	PrintInOrder(bstRoot);
	std::cout << "\n\n";
	std::cout << "Print in reverse order\n";
	PrintInReverseOrder(bstRoot);

	std::cout << "\n\n";

	Node* minNode = GetMinNode(bstRoot);
	Node* maxNode = GetMaxNode(bstRoot);

	std::cout << "Min data: " << minNode->data << "\n";
	std::cout << "Max data: " << maxNode->data << "\n";

	for (size_t i = 0; i < addresss.size(); i++)
	{
		bstRoot = Delete(bstRoot, addresss[i]);
	}

	std::cout << "\n\n";
	std::cout << "Print in order\n";
	PrintInOrder(bstRoot);
	std::cout << "\n\n";
	std::cout << "Print in reverse order\n";
	PrintInReverseOrder(bstRoot);
}

class IPAddress
{
public:
	IPAddress()
	{
		for (size_t i = 0; i < 4; i++)
		{
			mAddress[i] = rand() % 256;
		}
	}

	friend std::ostream& operator<<(std::ostream& os, const IPAddress& a)
	{
		os << a.mAddress[0] << "." << a.mAddress[1] << "." << a.mAddress[2] << "." << a.mAddress[3];
		return os;
	}

	bool operator<(const IPAddress& rhs) const
	{
		for (size_t i = 0; i < 4; i++)
		{
			if (mAddress[i] != rhs.mAddress[i])
			{
				return mAddress[i] < rhs.mAddress[i];
			}
		}
		return false;
	}

	bool operator<=(const IPAddress& rhs) const
	{
		for (size_t i = 0; i < 4; i++)
		{
			if (mAddress[i] != rhs.mAddress[i])
			{
				return mAddress[i] < rhs.mAddress[i];
			}
		}
		return true;
	}

	bool operator>(const IPAddress& rhs) const
	{
		for (size_t i = 0; i < 4; i++)
		{
			if (mAddress[i] != rhs.mAddress[i])
			{
				return mAddress[i] > rhs.mAddress[i];
			}
		}
		return false;
	}

	bool operator>=(const IPAddress& rhs) const
	{
		for (size_t i = 0; i < 4; i++)
		{
			if (mAddress[i] != rhs.mAddress[i])
			{
				return mAddress[i] > rhs.mAddress[i];
			}
		}
		return true;
	}

	bool operator==(const IPAddress& rhs) const
	{
		for (size_t i = 0; i < 4; i++)
		{
			if (mAddress[i] != rhs.mAddress[i])
			{
				return false;
			}
		}
		return true;
	}

	bool operator!=(const IPAddress& rhs) const
	{
		for (size_t i = 0; i < 4; i++)
		{
			if (mAddress[i] != rhs.mAddress[i])
			{
				return true;
			}
		}
		return false;
	}

private:
	int mAddress[4];
};

struct AVLNode
{
	IPAddress data;
	AVLNode* left = nullptr;
	AVLNode* right = nullptr;
	int height = 0;
};

AVLNode* CreateNode(const IPAddress& data)
{
	AVLNode* node = new AVLNode();
	node->data = data;
	return node;
}

void PrintInOrder(AVLNode* node)
{
	if (node != nullptr)
	{
		PrintInOrder(node->left);
		std::cout << node->data << "\n";
		PrintInOrder(node->right);
	}
}

void PrintInReverseOrder(AVLNode* node)
{
	if (node != nullptr)
	{
		PrintInReverseOrder(node->right);
		std::cout << node->data << "\n";
		PrintInReverseOrder(node->left);
	}
}

bool Search(AVLNode* node, const IPAddress& data)
{
	if (node == nullptr)
	{
		return false;
	}
	else if (node->data == data)
	{
		return true;
	}
	if (data < node->data)
	{
		return Search(node->left, data);
	}
	return Search(node->right, data);
}

AVLNode* GetMinNode(AVLNode* node) {
	AVLNode* minNode = node;
	while (minNode != nullptr && minNode->left != nullptr) {
		minNode = minNode->left;
	}
	return minNode;

}
AVLNode* GetMaxNode(AVLNode* node) {
	AVLNode* maxNode = node;
	while (maxNode != nullptr && maxNode->right != nullptr) {
		maxNode = maxNode->right;
	}
	return maxNode;
}

int NodeHeight(AVLNode* node)
{
	if (node != nullptr)
	{
		return node->height;
	}
	return 0;
}

int BalanceFactor(AVLNode* node)
{
	if (node != nullptr)
	{
		return NodeHeight(node->left) - NodeHeight(node->right);
	}
}

AVLNode* RotateRight(AVLNode* node)
{
	AVLNode* l = node->left;
	AVLNode* tmp = l->right;
	l->right = node;
	node->left = tmp;
	node->height = std::max(NodeHeight(node->left), NodeHeight(node->right));
	l->height = std::max(NodeHeight(l->left), NodeHeight(l->right)) + 1;
	return l;
}

AVLNode* RotateLeft(AVLNode* node)
{
	AVLNode* r = node->right;
	AVLNode* tmp = r->left;
	r->left = node;
	node->right = tmp;
	node->height = std::max(NodeHeight(node->left), NodeHeight(node->right));
	r->height = std::max(NodeHeight(r->left), NodeHeight(r->right)) + 1;
	return r;
}

AVLNode* Insert(AVLNode* node, const IPAddress& data)
{
	if (node == nullptr)
	{
		return CreateNode(data);
	}
	if (data < node->data)
	{
		node->left = Insert(node->left, data);
	}
	else if (data > node->data)
	{
		node->right = Insert(node->right, data);
	}

	node->height = std::max(NodeHeight(node->left), NodeHeight(node->right)) + 1;

	int balanceFactor = BalanceFactor(node);

	if (balanceFactor > 1 && data < node->left->data)
	{
		return RotateRight(node);
	}

	if (balanceFactor < -1 && data > node->right->data)
	{
		return RotateLeft(node);
	}

	if (balanceFactor > 1 && data < node->left->data)
	{
		node->left = RotateLeft(node->left);
		return RotateRight(node);
	}

	if (balanceFactor < -1 && data > node->right->data)
	{
		node->right = RotateRight(node->right);
		return RotateLeft(node);
	}

	return node;
}

AVLNode* Delete(AVLNode* node, const IPAddress& data) {
	if (node == nullptr) {
		return node;
	}
	if (data < node->data) {
		node->left = Delete(node->left, data);
	}
	else if (data > node->data) {
		node->right = Delete(node->right, data);
	}
	else {
		if (node->left == nullptr) {
			AVLNode* tmp = node->right;
			delete node;
			node = nullptr;
			return tmp;
		}
		if (node->right == nullptr) {
			AVLNode* tmp = node->left;
			delete node;
			node = nullptr;
			return tmp;
		}
		AVLNode* tmp = GetMinNode(node->right);
		node->data = tmp->data;
		node->right = Delete(node->right, node->data);

		node->height = std::max(NodeHeight(node->left), NodeHeight(node->right)) + 1;

		int balanceFactor = BalanceFactor(node);

		if (balanceFactor > 1 && BalanceFactor(node->left) >= 0)
		{
			return RotateRight(node);
		}

		if (balanceFactor < -1 && BalanceFactor(node->right) <= 0)
		{
			return RotateLeft(node);
		}

		if (balanceFactor > 1 && BalanceFactor(node->left) < 0)
		{
			node->left = RotateLeft(node->left);
			return RotateRight(node);
		}

		if (balanceFactor < -1 && BalanceFactor(node->right) > 0)
		{
			node->right = RotateRight(node->right);
			return RotateLeft(node);
		}
	}
	return node;
}

void Exercise2AVLTree()
{
	Vector<IPAddress> addresses;
	AVLNode* avlTree = nullptr;
	int maxAddresses = 20;
	for (size_t i = 0; i < maxAddresses; i++)
	{
		IPAddress newAddress;
		avlTree = Insert(avlTree, newAddress);
		std::cout << newAddress << "\n";
		if (rand() % 2 == 0)
		{
			addresses.PushBack(newAddress);
		}
	}
	std::cout << "\n\n";
	std::cout << "Print in order\n";
	PrintInOrder(avlTree);
	std::cout << "\n\n";
	std::cout << "Print in reverse order\n";
	PrintInReverseOrder(avlTree);

	std::cout << "\n\n";

	AVLNode* minNode = GetMinNode(avlTree);
	AVLNode* maxNode = GetMaxNode(avlTree);

	std::cout << "Min data: " << minNode->data << "\n";
	std::cout << "Max data: " << maxNode->data << "\n";

	for (size_t i = 0; i < addresses.size(); i++)
	{
		avlTree = Delete(avlTree, addresses[i]);
	}

	std::cout << "\n\n";
	std::cout << "Print in order\n";
	PrintInOrder(avlTree);
	std::cout << "\n\n";
	std::cout << "Print in reverse order\n";
	PrintInReverseOrder(avlTree);
}

int main()
{
	Exercise2AVLTree();
}