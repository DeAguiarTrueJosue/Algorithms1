#pragma once
#include <iostream>
#include "Stack.h"
#include "Queue.h"

template<typename T>
class Graph
{
private:
	struct Node
	{
		const T* data = nullptr;
		bool isVisited = false;
		Node* fromNode = nullptr;
		Vector<int> edges;

	};

public:
	Graph()
	{

	}

	~Graph()
	{
		Terminate();
	}

	int AddItem(const T* data)
	{
		Node* newNode = new Node();
		newNode->data = data;
		m_nodes.PushBack(newNode);
		return m_nodes.Size() - 1;
	}
	void AddLink(int a, int b, bool bothWays = true)
	{
		if (a >= m_nodes.Size() || b >= m_nodes.Size())
		{
			return;
		}
		m_nodes[a]->edges.PushBack(b);
		if (bothWays)
		{
			m_nodes[b]->edges.PushBack(a);
		}
	}

	void GetAllConnectionsDFS(int startIndex, Vector<const T*>& connections)
	{
		Reset();

		Stack<Node*> stack;
		stack.Push(m_nodes[startIndex]);
		while (!stack.Empty())
		{
			Node* node = stack.Top();
			stack.Pop();
			if (!node->isVisited)
			{
				node->isVisited = true;
				connections.PushBack(node->data);
				for (size_t i = 0; i < node->edges.Size(); ++i)
				{
					int edgeIndex = node->edges[i];
					Node* edgeNode = m_nodes[edgeIndex];
					if (!edgeNode->isVisited)
					{
						stack.Push(edgeNode);
					}
				}
			}
		}

	}

	void GetAllConnectionsBFS(int startIndex, Vector<const T*>& connections)
	{
		Reset();

		Queue<Node*> queue;
		queue.Enqueue(m_nodes[startIndex]);
		while (!queue.Empty())
		{
			Node* node = queue.Front();
			queue.Dequeue();
			if (!node->isVisited)
			{
				node->isVisited = true;
				connections.PushBack(node->data);
				for (size_t i = 0; i < node->edges.Size(); ++i)
				{
					int edgeIndex = node->edges[i];
					Node* edgeNode = m_nodes[edgeIndex];
					if (!edgeNode->isVisited)
					{
						queue.Enqueue(edgeNode);
					}
				}
			}
		}

	}

	bool GetPathDFS(int startIndex, int endIndex, Vector<const T*>& path)
	{
		Reset();

		bool pathFound = false;
		Node* startNode = m_nodes[startIndex];
		Node* endNode = m_nodes[endIndex];
		Stack<Node*> stack;
		stack.Push(startNode);
		while (!stack.Empty())
		{
			Node* node = stack.Top();
			stack.Pop();
			if (!node->isVisited)
			{
				node->isVisited = true;
				if (node == endNode)
				{
					pathFound = true;
					break;

				}
				for (size_t i = 0; i < node->edges.Size(); i++)
				{
					int edgeIndex = node->edges[i];
					Node* edgeNode = m_nodes[edgeIndex];
					if (!edgeNode->isVisited)
					{
						edgeNode->fromNode = node;
						stack.Push(edgeNode);
					}
				}
			}
		}
		if (pathFound)
		{
			Node* pathNode = endNode;
			while (pathNode != nullptr)
			{
				path.PushBack(pathNode->data);
				pathNode = pathNode->fromNode;
			}
		}
		return pathFound;
	}

	bool GetPathBFS(int startIndex, int endIndex, Vector<const T*>& path)
	{
		Reset();
		bool pathFound = false;
		Node* startNode = m_nodes[startIndex];
		Node* endNode = m_nodes[endIndex];

		Queue<Node*> queue;
		queue.Enqueue(startNode);
		while (!queue.Empty())
		{
			Node* node = queue.Front();
			queue.Dequeue();
			if (!node->isVisited)
			{
				node->isVisited = true;
				if (node == endNode)
				{
					pathFound = true;
					break;
				}

				for (size_t i = 0; i < node->edges.Size(); i++)
				{
					int edgeIndex = node->edges[i];
					Node* edgeNode = m_nodes[edgeIndex];
					if (!edgeNode->isVisited)
					{
						edgeNode->fromNode = node;
						queue.Enqueue(edgeNode);
					}
				}
			}
		}
		if (pathFound)
		{
			Node* pathNode = endNode;
			while (pathNode != nullptr)
			{
				path.PushBack(pathNode->data);
				pathNode = pathNode->fromNode;
			}
		}
		return pathFound;
	}

	void PrintGraph()
	{
		std::cout << "Print Graph:\n";
		for (size_t i = 0; i < m_nodes.Size(); ++i)
		{
			std::cout << (*m_nodes[i]->data) << ": ";
			for (size_t e = 0; e < m_nodes[i]->edges.Size(); ++e)
			{
				int edgeNodeIndex = m_nodes[i]->edges[e];
				std::cout << (*m_nodes[edgeNodeIndex]->data) << " ";
			}
			std::cout << "\n";
		}
	}

	void Terminate()
	{
		for (size_t i = 0; i < m_nodes.Size(); i++)
		{
			delete m_nodes[i];
			m_nodes[i] = nullptr;
		}
		m_nodes.Clear();

	}

private:
	void Reset()
	{
		for (size_t i = 0; i < m_nodes.Size(); i++)
		{
			m_nodes[i]->isVisited = false;
			m_nodes[i]->fromNode = nullptr;
		}
	}
	Vector<Node*> m_nodes;
};