/*
	CodeUp: 装箱问题
*/
#define DEBUG

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 20000 + 10;
int v, n;
int c[maxn],dp[maxn], sum[maxn];

int main()
{
#ifdef DEBUG
    freopen("F:\\input.txt", "r", stdin);
#endif // DEBUG
    while (~scanf("%d%d", &v, &n))
    {
        memset(dp, 0, sizeof(dp));
        sum[0] = 0;

        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", c + i);
            sum[i] = sum[i - 1] + c[i];
        }

        int ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            int bound = max(c[i], v - sum[n] + sum[i - 1]);
            for (int j = v; j >= bound; --j)
            {
                dp[j] = max(dp[j], dp[j - c[i]] + c[i]);

                if (dp[j] <= v && dp[j] > ans)
                    ans = dp[j];
            }
        }

        printf("%d\n", v - ans);
    }
    return 0;
}