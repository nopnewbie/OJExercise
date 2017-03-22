#define DEBUG

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <map>
using namespace std;

const int maxn = 10000 + 10;
bool up[maxn];
int n, m;


int main()
{
#ifdef DEBUG
	freopen("F:\\input.txt", "r", stdin);
#endif
    while (~scanf("%d%d", &n, &m))
    {
        memset(up, false, sizeof(up));
        for (int i = 0, a, b; i < m; ++i)
        {
            scanf("%d%d", &a, &b);
            while (a <= b)
            {
                up[a] = !up[a];
                ++a;
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            printf("%d", up[i]);
        }
        puts("");
    }
	return 0;
}

