#define DEBUG
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

const int maxn = 1000 + 10;
typedef pair<int, int> Edge;
vector<Edge> edges;
int fa[maxn];
int n, m, k;

inline void init()
{
    edges.clear();
}

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


int repair(int city)
{
    fill(fa, fa + n + 1, -1);
    int ans = n - 1;
    for (const auto &e : edges)
    {
        if (e.first == city || e.second == city) continue;
        if (merge(e.first, e.second))
        {
            --ans;
        }
    }
    return --ans;
}

int main()
{
#ifdef DEBUG
    freopen("F:\\input.txt", "r", stdin);
#endif // DEBUG
    while (~scanf("%d%d%d", &n, &m, &k))
    {
        init();
        for (int i = 0, u, v; i < m; ++i)
        {
            scanf("%d%d", &u, &v);
            edges.emplace_back(u, v);
        }
        for (int i = 0, c; i < k; ++i)
        {
            scanf("%d", &c);
            printf("%d\n", repair(c));
        }
    }
    return 0;
}