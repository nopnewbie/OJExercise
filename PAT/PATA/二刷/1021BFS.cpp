#define DEBUG

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;
const int maxn = 10000 + 10;
int n, depth[maxn], fa[maxn];
vector<int> graph[maxn];
set<int> deepestRoots;

int find(int x)
{
    return fa[x] < 0 ? x : (fa[x] = find(fa[x]));
}

bool merge(int x, int y)
{
    int rt1 = find(x);
    int rt2 = find(y);
    if (rt1 == rt2) return false;
    if (fa[rt1] < fa[rt2])
    {
        fa[rt1] += fa[rt2];
        fa[rt2] = rt1;
    }
    else
    {
        fa[rt2] += fa[rt1];
        fa[rt1] = rt2;
    }
    return true;
}

int bfs(int src)
{
    typedef pair<int, int> PII;
    queue<PII> q;
    vector<bool> vis(n + 1, false);
    q.emplace(src, 0);
    int maxDepth = 0;
    while (!q.empty())
    {
        int u = q.front().first;
        int d = q.front().second;
        q.pop();
        vis[u] = true;
        depth[u] = d;
        maxDepth = max(d, maxDepth);
        for (auto v : graph[u])
            if (vis[v]) continue;
            else q.emplace(v, d + 1);
    }
    for (int i = 1; i <= n; ++i)
        if (depth[i] == maxDepth)
            deepestRoots.insert(i);
    return maxDepth;
}

int main()
{
#ifdef DEBUG
    freopen("F:\\input.txt", "r", stdin);
#endif // DEBUG

    while (~scanf("%d", &n))
    {
        fill(fa, fa + n + 1, -1);
        for (int i = 1; i <= n; ++i) graph[i].clear();
        int u, v, coponent = n;
        for (int i = 0; i < n - 1; ++i)
        {
            scanf("%d%d", &u, &v);
            if (merge(u, v)) --coponent;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        if (coponent > 1)
            printf("Error: %d components\n", coponent);
        else
        {
            for (int i = 0, start = 1; i < 2; ++i)
            {
                bfs(start);
                start = *deepestRoots.begin();
            }
            for (auto i : deepestRoots)
                printf("%d\n", i);
        }
    }
    return 0;
}