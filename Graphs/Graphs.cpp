#include <iostream>
#include <vector>
#include <queue>
#include <stack>

void DFS(const std::vector<std::vector<int>>& graph, int startVertex)
{
	std::vector<bool> visited;
	visited.resize(graph.size(), false);

	std::cout << "DFS Print All:\n";
	std::stack<int> process;
	process.push(startVertex);
	while (!process.empty())
	{
		int vertex = process.top();
		process.pop();
		if (!visited[vertex])
		{
			visited[vertex] = true;
			std::cout << vertex << " ";
			for (int i = 0; i < graph[vertex].size(); i++)
			{
				if (!visited[graph[vertex][i]])
				{
					process.push(graph[vertex][i]);
				}
			}
		}
	}
	std::cout << "\n";
}

void BFS(const std::vector<std::vector<int>>& graph, int startVertex)
{
	std::vector<bool> visited;
	visited.resize(graph.size(), false);

	std::cout << "BFS Print All:\n";
	std::queue<int> process;
	process.push(startVertex);
	while (!process.empty())
	{
		int vertex = process.front();
		process.pop();
		if (!visited[vertex])
		{
			visited[vertex] = true;
			std::cout << vertex << " ";
			for (int i = 0; i < graph[vertex].size(); i++)
			{
				if (!visited[graph[vertex][i]])
				{
					process.push(graph[vertex][i]);
				}
			}
		}
	}
	std::cout << "\n";
}

void RecDfs(const std::vector<std::vector<int>>& graph, int nextVertex, std::vector<bool>& visited)
{
	visited[nextVertex] = true;
	std::cout << nextVertex << "\n";
	for (int i = graph[nextVertex].size() - 1; i >= 0; i--)
	{
		int nextVertexToSearch = graph[nextVertex][i];
		if (!visited[nextVertexToSearch])
		{
			RecDfs(graph, nextVertexToSearch, visited);
		}
	}
}

int main()
{
	std::cout << "Graph!\n\n";

	int numVertices = 0;
	std::cout << "Number Of Vertices: ";
	std::cin >> numVertices;

	std::vector<std::vector<int>> adjacentList;
	adjacentList.resize(numVertices);

	int inputStart = -1;
	int inputEnd = -1;

	std::cout << "\nBuilding the Graph:\n";
	while (true)
	{
		std::cout << "Enter Start Vertex: ";
		std::cin >> inputStart;
		if (inputStart < 0 || inputStart >= numVertices)
		{
			std::cout << "Invalid index [" << inputStart << "]\n";
			break;
		}

		std::cout << "Enter End Vertex: ";
		std::cin >> inputEnd;
		if (inputEnd < 0 || inputEnd >= numVertices)
		{
			std::cout << "Invalid index [" << inputEnd << "]\n";
			break;
		}

		auto iter = std::find(adjacentList[inputStart].begin(), adjacentList[inputStart].end(), inputEnd);
		if (iter == adjacentList[inputStart].end())
		{
			adjacentList[inputStart].push_back(inputEnd);
		}

		iter = std::find(adjacentList[inputEnd].begin(), adjacentList[inputEnd].end(), inputStart);
		if (iter == adjacentList[inputEnd].end())
		{
			adjacentList[inputEnd].push_back(inputStart);
		}
	}
	system("cls");

	std::cout << "Adjacent list:\n";
	for (int i = 0; i < numVertices; i++)
	{
		std::cout << i << ": {";
		for (int j = 0; j < adjacentList[i].size(); j++)
		{
			std::cout << adjacentList[i][j] << ", ";
		}
		std::cout << "}\n";
	}

	int startVertex = 0;
	std::cout << "Start vertex: ";
	std::cin >> startVertex;
	DFS(adjacentList, startVertex);
	BFS(adjacentList, startVertex);
	std::vector<bool> visited;
	visited.resize(5);
	RecDfs(adjacentList, startVertex, visited);
}