#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

bool comp(std::pair<int, std::set<int> > a, std::pair<int, std::set<int> > b)
{
	return a.second.size() < b.second.size();
}

std::vector<std::pair<int, std::set<int> > > buildGraph(int v, int e)
{
	std::vector<std::pair<int, std::set<int> > > graph(v);
	for (int i = 0; i < v; ++i)
		graph[i].first = i;
	for (int i = 0; i < e; ++i)
	{
		int from, to;
		std::cin >> from >> to;
		--from;
		--to;
		graph[from].second.insert(to);
		graph[to].second.insert(from);
	}
	return graph;
}

bool canCoverVertices(std::vector<std::pair<int, std::set<int> > >& graph, int s)
{
	std::sort(graph.begin(), graph.end(), comp);
	for (int i = 0; i < graph.size(); ++i)
	{
		int count = 0;
		std::vector<bool> used(graph.size(), false);
		for (int j = i; j < graph.size(); ++j)
		{
			if (!used[graph[j].first])
			{
				used[graph[j].first] = true;
				for (int tv : graph[j].second)
				{
					used[tv] = true;
				}
				++count;
			}
			if (count == s)
				return true;
		}
	}
	return false;
}

int main()
{
	int v, s, e;
	std::cin >> v >> s >> e;

	std::vector<std::pair<int, std::set<int> > > graph = buildGraph(v, e);

	if (canCoverVertices(graph, s))
		std::cout << "YES";
	else
		std::cout << "NO";
	return 0;
}
