/*
	剪气球串
*/
#define DEBUG

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 1000000007;
int f[10];
bool t[10];
int n;

int main()
{
#ifdef DEBUG
    freopen("F:\\input.txt", "r", stdin);
#endif // DEBUG

    f[0] = 0;
    f[1] = 1;
    f[2] = 2;
    for (int i = 3; i < 10; ++i)
    {
        for (int j = 1; j < i; ++j)
        {
            f[i] = (f[i] + f[j] * f[i - j]) % maxn;
        }
    }
    while (~scanf("%d", &n))
    {
        memset(t, false, sizeof(t));
        int preEnd = 1, cur, ans = 0, i;
        for (i = 1; i <= n; ++i)
        {
            scanf("%d", &cur);
            if (t[cur])
            {
                ans = (ans + f[i - preEnd == 1 ? 0 : i - preEnd]) % maxn;
                preEnd = i;
                memset(t, false, sizeof(t));
                t[cur] = true;
            }
            else
            {
                t[cur] = true;
            }
        }
        ans = ans + (f[i - preEnd]) % maxn;
        printf("%d\n", ans);
    }
    return 0;
}