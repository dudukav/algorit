#include <atomic>
#include <cstddef>
#include <iostream>
#include <utility>
#include <vector>
#include <tuple>

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

int		main()
{
		int n, m;
		std::cin >> n >> m;
		std::vector<std::vector<int> > graph(n);
		int v;
		for (size_t i = 0; i < n; ++i)
		{
			std::cin >> v;
			while(v != 0)
			{		
					--v;
					graph[i].push_back(v);
					std::cin >> v;
			}
		}

		std::vector<int> mt(m, -1);
		for (int v = 0; v < n; ++v)
		{
				std::vector<bool> used(n, false);
				Kuhn(graph, used, mt, v);
		}

		std::vector<std::pair<int, int> > answer;
		for (int i = 0; i < m; ++i)
		{
			if (mt[i] != -1)
			{
					answer.push_back(std::make_pair(mt[i] + 1, i + 1));
			}
		}

		std::cout << answer.size() << '\n';
		for (size_t i = 0; i < answer.size(); ++i)
		{
				std::cout << answer[i].first << ' ' << answer[i].second << '\n';
		}
		return 0;
}
