#include <iostream>
#include <vector>
#include <queue>

const int INF = 1e9;

std::vector<std::vector<int> > capacity, flow; 
std::vector<int> p; 
std::vector<int> distance; 
std::vector<std::vector<int> > graph; 

bool	bfs(int s, int t) 
{

		distance.assign(graph.size(), INF);
		distance[s] = 0;
		std::queue<int> Q;
		Q.push(s);
		while (!Q.empty()) 
		{
				int u = Q.front();
				Q.pop();
				for (int v : graph[u]) 
				{
						if (flow[u][v] < capacity[u][v] && distance[v] == INF) 
						{
								distance[v] = distance[u] + 1;
								Q.push(v);
						}
				}
		}

		return distance[t] != INF;
}

int		dfs(int u, int t, int minC) 
{
		if (u == t || minC == 0)
		{
				return minC;
		}
		for (int& i = p[u]; i < graph[u].size(); ++i) 
		{
				int v = graph[u][i];
				if (distance[v] == distance[u] + 1) 
				{
						int delta = dfs(v, t, std::min(minC, capacity[u][v] - flow[u][v]));
						if (delta != 0) 
						{
								flow[u][v] += delta;
								flow[v][u] -= delta;
								return delta;
						}
				}
		}
		return 0;
}

int		findMaxFlow(int s, int t) 
{
		int maxFlow = 0;
		while (bfs(s, t)) 
		{
				p.assign(graph.size(), 0);
				int f = dfs(s, t, INF);
				while (f != 0) 
				{
						maxFlow += f;
						f = dfs(s, t, INF);
				}
		}
		return maxFlow;
}

int main() 
{
		int n, m;
		std::cin >> n >> m;
		capacity.resize(n, std::vector<int>(n, 0));
		flow.resize(n, std::vector<int>(n, 0));
		graph.resize(n);

		for (size_t i = 0; i < m; ++i) {
				int u, v, c;
				std::cin >> u >> v >> c;
				--u;
				--v;
				graph[u].push_back(v);
				graph[v].push_back(u);
				capacity[u][v] = c;
		}

		int maxFlow = findMaxFlow(0, n - 1);
		std::cout << maxFlow;
}

