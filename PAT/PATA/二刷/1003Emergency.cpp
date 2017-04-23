#define DEBUG
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int INF = 0x3fffffff;
const int maxn = 500 + 10;
int n, m, c1, c2;
int teams[maxn];

struct Edge
{
    Edge() = default;
    Edge(int f, int t, int d) : from(f), to(t), dist(d) {}
    int from, to, dist;
};

vector<Edge> edges;
vector<int> graph[maxn];    // 记录边的编号 graph[i] 表示从i出发的边的编号，利用该编号到edges中去寻找
bool vis[maxn];
vector<int> parent[maxn];   // parent[i]从起点走到i的最短路径上的前一个节点的集合。
vector<vector<int>> paths;
int dist[maxn][2];             // 从起点到节点i的最短路径长度, 以及在最短距离下可以获得的最大队伍数量

inline void addEdge(const int from, const int to, const int distance)
{
    edges.emplace_back(from, to, distance);
    graph[from].push_back(edges.size() - 1);
}

inline void init()
{
    memset(teams, 0, sizeof(teams));
    paths.clear();
    edges.clear();
    for (auto &u : graph) u.clear();
    for (auto &p : parent) p.clear();
}

void Dijikstra(const int s)
{
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < n; ++i)
    {
        dist[i][0] = INF; dist[i][1] = -1;
    }
    dist[s][0] = 0; dist[s][1] = teams[s];
    struct HeapNode
    {
        int u, d;
        HeapNode(int _u, int _d) :u(_u), d(_d) {}
        bool operator< (const HeapNode &rhs) const
        {
            return d > rhs.d;
        }
    };
    priority_queue<HeapNode> q;
    q.emplace(s, 0);
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
                dist[e.to][1] = dist[e.from][1] + teams[e.to];
                parent[e.to].clear();
                parent[e.to].push_back(u);
                q.emplace(e.to, dist[e.to][0]);
            }
            else if (dist[e.to][0] == dist[u][0] + e.dist)
            {
                dist[e.to][1] = max(dist[e.from][1] + teams[e.to], dist[e.to][1]);
                parent[e.to].push_back(u);
            }
        }
    }
}

void getPath(int cur, vector<int> &p)
{
    p.push_back(cur);
    if (cur == c1)
    {
        paths.push_back(p);
    }
    else
    {
        for (auto prv : parent[cur])
        {
            getPath(prv, p);
        }
    }
    p.pop_back();
}

void print_ans()
{
    vector<int> tmp;
    getPath(c2, tmp);
    printf("%d %d\n", paths.size(), dist[c2][1]);
}

int main()
{
#ifdef DEBUG
    freopen("F:\\input.txt", "r", stdin);
#endif // DEBUG
    while (~scanf("%d%d%d%d", &n, &m, &c1, &c2))
    {
        init();

        for (int i = 0; i < n; ++i) scanf("%d", teams + i);
        for (int i = 0, f, t, l; i < m; ++i)
        {
            scanf("%d%d%d", &f, &t, &l);
            addEdge(f, t, l);
            addEdge(t, f, l);
        }
        Dijikstra(c1);
        print_ans();
    }
    return 0;
}