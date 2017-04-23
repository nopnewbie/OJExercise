#define DEBUG
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

const int INF = 0x3fffffff;
const int maxn = 500 + 10;
int cmax, n, sp, m;
int bikes[maxn], dist[maxn];
bool vis[maxn];
vector<int> graph[maxn];
vector<int> paths[maxn];
struct Edge
{
    Edge(int f, int t, int d) :from(f), to(t), dist(d) { }
    int from, to, dist;
};
vector<Edge> edges;

void Dijikstra(const int src)
{
    fill(vis, vis + n + 1, false);
    fill(dist, dist + n + 1, INF);
    dist[src] = 0;
    typedef pair<int, int> PII;
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.emplace(0, src);
    while (!q.empty())
    {
        int u = q.top().second; q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (auto i : graph[u])
        {
            Edge &e = edges[i];
            if (dist[e.to] > dist[u] + e.dist)
            {
                dist[e.to] = dist[u] + e.dist;
                q.emplace(dist[e.to], e.to);
                paths[e.to].clear();
                paths[e.to].push_back(u);
            }
            else if (dist[e.to] == dist[u] + e.dist)
            {
                paths[e.to].push_back(u);
            }
        }
    }
}

int bringTo, takeBack;
vector<int> tmpPath, bestPath;
void getPath(int cur)
{
    tmpPath.push_back(cur);
    if (cur == 0)
    {
        int left = 0, need = 0;
        for (auto iter = tmpPath.crbegin() + 1; iter != tmpPath.crend(); ++iter)
        {
            left += bikes[*iter] - cmax / 2;
            if (left < 0)
            {
                need -= left;
                left = 0;
            }
        }
        if (bringTo > need) // 需要带去更少的车
        {
            bringTo = need;
            takeBack = left;
            bestPath = tmpPath;
        }
        else if (bringTo == need && takeBack > left)   // 需要带回更少的车
        {
            takeBack = left;
            bestPath = tmpPath;
        }
    }
    else
    {
        for (auto prv : paths[cur])
            getPath(prv);
    }
    tmpPath.pop_back();
}

void print_ans()
{
    printf("%d %d", bringTo, bestPath.back());
    for (auto iter = bestPath.crbegin() + 1; iter != bestPath.crend(); ++iter)
        printf("->%d", *iter);
    printf(" %d\n", takeBack);
}

inline void addEdge(const int from, const int to, const int dist)
{
    edges.emplace_back(from, to, dist);
    graph[from].push_back(edges.size() - 1);
}

inline void init()
{
    bringTo = takeBack = INF;
    edges.clear();
    bestPath.clear();
    for (int i = 0; i <= n; ++i)
    {
        graph[i].clear(); 
        paths[i].clear();
    }   
}

int main()
{
#ifdef DEBUG
    freopen("F:\\input.txt", "r", stdin);
#endif // DEBUG
    while (~scanf("%d%d%d%d", &cmax, &n, &sp, &m))
    {
        init();
        for (int i = 1; i <= n; ++i) scanf("%d", bikes + i);
        int u, v, t;
        for (int i = 0; i < m; ++i)
        {
            scanf("%d%d%d", &u, &v, &t);
            addEdge(u, v, t);
            addEdge(v, u, t);
        }
        
        Dijikstra(0);
        getPath(sp);
        print_ans();
    }


    return 0;
}
/*
    本题要注意的有以下几点：
    1. 在路程一样短的情况下，优先考虑要从源点带车少的路径。比如第一个点就小于cmax/2，那么就应该从源点带cmax/2 - s[1].bikes辆车
    2. 从源点到终点调整车的数量，不回头。 即当前车不够，只能从源点拿，而不会等到终点看有没有剩余车，回头调整。最后有余，直接带回。
*/