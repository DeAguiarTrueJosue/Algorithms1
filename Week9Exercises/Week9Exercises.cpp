#include <iostream>
#include <Vector.h>
#include <queue>
#include <stack>
#include <algorithm>

struct Node
{
    int nodeIndex = -1;
};

void DFS(const Vector<Vector<Node>>& graph, int startNode)
{
    Vector<bool> visited;
    visited.Resize(graph.size());

    std::stack<int> process;
    process.push(startNode);

    while (!process.empty())
    {
        int nodeIndex = process.top();
        process.pop();
        if (!visited[nodeIndex])
        {
            visited[nodeIndex] = true;
            for (int i = 0; i < graph[nodeIndex].size(); i++)
            {
                const Node& node = graph[nodeIndex][i];
                std::cout << nodeIndex << " ";
                if (visited[node.nodeIndex])
                {
                    process.push(node.nodeIndex);
                }
            }
        }
    }
}

void BFS(const Vector<Vector<Node>>& graph, int startNode)
{
    Vector<bool> visited;
    visited.Resize(graph.size());

    std::queue<int> process;
    process.push(startNode);

    while (!process.empty())
    {
        int nodeIndex = process.front();
        process.pop();
        if (!visited[nodeIndex])
        {
            visited[nodeIndex] = true;
            for (int i = 0; i < graph[nodeIndex].size(); i++)
            {
                const Node& node = graph[nodeIndex][i];
                std::cout << nodeIndex << " ";
                if (visited[node.nodeIndex])
                {
                    process.push(node.nodeIndex);
                }
            }
        }
    }
}

void AddLinke(std::vector<Node>& neighbors, int linkedIndex)
{
    auto iter = std::find_if(neighbors.begin(), neighbors.end(),
        [linkedIndex](const Node& n)
        {
            return n.nodeIndex == linkedIndex;
        }
    );
    if (iter == neighbors.end())
    {
        Node newNeighbor;
        newNeighbor.nodeIndex = linkedIndex;
        neighbors.push_back(newNeighbor);
    }
}

void AddLinkedPair(std::vector<std::vector<Node>>& graph, int node, int linkedNeighbor)
{
    AddLinke(graph[node], linkedNeighbor);
    AddLinke(graph[linkedNeighbor], node);
}

void Exercise1()
{

}

int main()
{
    std::cout << "Hello World!\n";
}