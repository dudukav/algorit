#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 1000;
const int INF = 1e9;

int n, m, s, t;
int ptr[MAXN], dist[MAXN];
vector<int> graph[MAXN];
struct Edge {
    int from, to, cap, flow;
};

vector<Edge> edges;

void add_edge(int from, int to, int cap) {
    Edge e1 = {from, to, cap, 0};
    Edge e2 = {to, from, 0, 0};
    graph[from].push_back(edges.size());
    edges.push_back(e1);
    graph[to].push_back(edges.size());
    edges.push_back(e2);
}

bool bfs() {
    queue<int> q;
    q.push(s);
    memset(dist, -1, sizeof(dist));
    dist[s] = 0;
    while (!q.empty() && dist[t] == -1) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < graph[u].size(); ++i) {
            int id = graph[u][i];
            int v = edges[id].to;
            if (dist[v] == -1 && edges[id].flow < edges[id].cap) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist[t] != -1;
}

int dfs(int u, int flow) {
    if (u == t || !flow) {
        return flow;
    }
    for (; ptr[u] < graph[u].size(); ++ptr[u]) {
        int id = graph[u][ptr[u]];
        int v = edges[id].to;
        if (dist[v] == dist[u] + 1) {
            int pushed = dfs(v, min(flow, edges[id].cap - edges[id].flow));
            if (pushed) {
                edges[id].flow += pushed;
                edges[id ^ 1].flow -= pushed;
                return pushed;
            }
        }
    }
    return 0;
}

int dinic() {
    int flow = 0;
    while (bfs()) {
        memset(ptr, 0, sizeof(ptr));
        while (int pushed = dfs(s, INF)) {
            flow += pushed;
        }
    }
    return flow;
}

int main() {
    cin >> n >> m >> a >> h;
    --s, --t;
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        --u, --v;
        add_edge(u, v, c);
        add_edge(v, u, 0);
    }
    cout << dinic() << endl;
    return 0;
}

