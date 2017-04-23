#define DEBUG
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int INF = 0x3fffffff;
const int maxn = 500 + 5;
int n, m, s, d;
int dist[maxn][2];
bool vis[maxn];
vector<int> graph[maxn];
int prv[maxn];

struct Edge
{
    Edge(int f, int t, int d, int c) : from(f), to(t), dist(d), cost(c) {}
    int from, to, dist, cost;
};
vector<Edge> edges;

void Dijikstra(const int src)
{
    fill(vis, vis + n, false);
    for (int i = 0; i < n; ++i) dist[i][0] = dist[i][1] = INF;
    dist[src][0] = dist[src][1] = 0;
    struct HeapNode
    {
        int u, d;
        HeapNode(int _u, int _d) :u(_u), d(_d) {}
        bool operator<(const HeapNode &rhs) const
        {
            return d > rhs.d;
        }
    };
    priority_queue<HeapNode> q;
    q.push({ src, 0 });
    while (!q.empty())
    {
        int u = q.top().u; q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (auto i : graph[u])
        {
            Edge &e = edges[i];
            if (dist[e.to][0] > dist[u][0] + e.dist)
            {
                dist[e.to][0] = dist[u][0] + e.dist;
                dist[e.to][1] = dist[u][1] + e.cost;
                prv[e.to] = u;
                q.push({ e.to, dist[e.to][0] });
            }
            else if (dist[e.to][0] == dist[u][0] + e.dist &&
                dist[e.to][1] > dist[u][1] + e.cost)
            {
                dist[e.to][1] = dist[u][1] + e.cost;
                prv[e.to] = u;
            }
        }
    }
}

inline void print_ans(const int src, const int des)
{
    vector<int> bestPath;
    int cur = des;
    while (cur != src)
    {
        bestPath.push_back(cur);
        cur = prv[cur];
    }
    printf("%d", src);
    for (auto iter = bestPath.crbegin(); iter != bestPath.crend(); ++iter)
        printf(" %d", *iter);
    printf(" %d %d\n", dist[des][0], dist[des][1]);
}

inline void addEdge(const int u, const int v, const int d, const int c)
{
    edges.push_back({ u, v, d, c });
    graph[u].push_back(edges.size() - 1);
}

inline void init()
{
    edges.clear();
    for (int i = 0; i < n; ++i) graph[i].clear();
}

int main()
{
#ifdef DEBUG
    freopen("F:\\input.txt", "r", stdin);
#endif // DEBUG
    while (~scanf("%d%d%d%d", &n, &m, &s, &d))
    {
        init();
        for (int i = 0, c1, c2, ds, c; i < m; ++i)
        {
            scanf("%d%d%d%d", &c1, &c2, &ds, &c);
            addEdge(c1, c2, ds, c);
            addEdge(c2, c1, ds, c);
        }

        Dijikstra(s);
        print_ans(s, d);
    }
    return 0;
}