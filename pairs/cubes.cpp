#include <atomic>
#include <cstddef>
#include <iostream>
#include <new>
#include <utility>
#include <vector>
#include <set>

bool	Kuhn(std::vector<std::vector<int> >& graph, std::vector<bool>& used, std::vector<int>& mt, int v) 
{
		if (used[v])
				return false;
		used[v] = true;
		for (size_t i = 0; i < graph[v].size(); ++i)
		{
				if (mt[graph[v][i]] == -1 || Kuhn(graph, used, mt, mt[graph[v][i]]))
				{
						mt[graph[v][i]] = v;
						return true;
				}
		}
		return false;
}

bool	Contains(std::set<char>& cube, char s)
{
		for (char c : cube)
		{
				if (c == s) 
						return true;
		}
		return false;
}

int		main()
{
		int n;
		std::cin >> n;
		std::string name;
		std::cin >> name;
		std::vector<std::vector<int> > graph(n);
		for (size_t i = 0; i < n; ++i)
		{
				std::set<char> cube;
				for (size_t j = 0; j < 6; ++j)
				{
						char s;
						std::cin >> s;
						cube.insert(s);
				}
				for (size_t j = 0; j < name.size(); ++j)
				{
						if (Contains(cube, name[j]))
								graph[i].push_back(j);
				}
		}
		std::vector<int> mt(name.size(), -1);
		for (int v = 0; v < n; ++v)
		{
				std::vector<bool> used(n, false);
				Kuhn(graph, used, mt, v);
		}

		std::vector<int> answer;
		for (int i = 0; i < name.size(); ++i)
		{
			if (mt[i] != -1)
			{
					answer.push_back(mt[i] + 1);
			}
		}

		if (answer.size() != name.size())
		{
				std::cout << "NO";
				return 0;
		}

		std::cout << "YES" << '\n';
		for (int i : answer)
		{
				std::cout << i << ' ';
		}

		return 0;
}

