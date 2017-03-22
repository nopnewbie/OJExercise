#define DEBUG

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <map>
using namespace std;

const int maxn = 100 + 10;
int fa[maxn];
int n, m;

void init()
{
    memset(fa, -1, sizeof(fa));
}

int Find(int x)
{
    return fa[x] < 0 ? x : (fa[x] = Find(fa[x]));
}

bool Union(const int x, const int y)
{
    int rt1 = Find(x);
    int rt2 = Find(y);
    if (rt1 == rt2)
        return false;
    else if (fa[rt1] <= fa[rt2])
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



int main()
{
#ifdef DEBUG
	freopen("F:\\input.txt", "r", stdin);
#endif
    while(~scanf("%d%d", &n, &m))
    {
        init();
        for (int i = 0, a, b; i < m; ++i)
        {
            scanf("%d%d", &a, &b);
            if (Union(a, b))
                --n;
        }
        printf("%d\n", --n);
    }
	return 0;
}

