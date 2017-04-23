#define DEBUG
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;

const int maxn = 10000 + 1;
const int INF = 0x3fffffff;
vector<int> graph[maxn];
int fa[maxn];
int vis[maxn];
int n;
set<int> deepestRoots;

int find(int x)
{
    return fa[x] < 0 ? x : (fa[x] = find(fa[x]));
}

bool merge(int x, int y)
{
    int rt1 = find(x);
    int rt2 = find(y);
    if (rt1 == rt2)
        return false;
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

void dfs(int src, int lv, int &maxLv)
{
    vis[src] = lv;
    maxLv = max(lv, maxLv);
    for (auto i : graph[src])
    {
        if (vis[i] == -1)   // 该点未访问过
            dfs(i, lv + 1, maxLv);
    }
}

inline void init()
{
    fill(fa, fa + n + 1, -1);
    fill(vis, vis + n + 1, -1);
}
int main()
{
#ifdef DEBUG
    freopen("F:\\input.txt", "r", stdin);
#endif // DEBUG
    while (~scanf("%d", &n))
    {
        init();
        int u, v, cnt = n;
        for (int i = 0; i < n - 1; ++i)
        {
            scanf("%d%d", &u, &v);
            // 无向图
            graph[u].push_back(v);
            graph[v].push_back(u);
            if (merge(u, v)) --cnt;
        }
        if (cnt > 1)
        {
            printf("Error: %d components\n", cnt);
        }
        else
        {
            int depth = 0;
            for (int i = 0, s = 1; i < 2; ++i)
            {
                fill(vis, vis + n + 1, -1);
                dfs(s, 0, depth);
                for (int i = 1; i <= n; ++i)
                    if (vis[i] == depth)
                        deepestRoots.insert(i);
                s = *deepestRoots.begin();
            }
            for (auto i : deepestRoots)   printf("%d\n", i);
        }
    }
    return 0;
}