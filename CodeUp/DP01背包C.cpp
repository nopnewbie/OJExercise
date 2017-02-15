/*
	CodeUp: 货币系统
	Category: DP-完全背包
*/

#define DEBUG
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int maxn = 10000 + 10;
long long v, n, dp[maxn], c[maxn];

int main()
{
#ifdef DEBUG
    freopen("F:\\input.txt", "r", stdin);
#endif // DEBUG
    while (~scanf("%lld%lld", &v, &n))
    {
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;

        for (int i = 1; i <= v; ++i)
        {
            scanf("%lld", c + i);
        }

        for (int i = 1; i <= v; ++i)
        {
            for (int j = c[i]; j <= n; ++j)
            {
                dp[j] = dp[j] + dp[j - c[i]];
            }
        }

        printf("%lld\n", dp[n]);
    }
    return 0;
}