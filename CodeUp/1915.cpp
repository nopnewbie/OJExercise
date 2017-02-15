/*
	CodeUp: 1915: 采药
	Category: DP:01背包
	Start: 2017年2月13日 19:38:02
    End: 2017年2月13日 20:21:52
*/

#define DEBUG

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int maxt = 1000 + 10;
const int maxm = 100 + 10;
int t, m;
int dp[maxt], c[maxm], w[maxm], sum[maxm];

inline void init()
{
    memset(dp, 0, sizeof(dp));
    sum[0] = 0;
}

int main()
{
#ifdef DEBUG
    freopen("F:\\input.txt", "r", stdin);
#endif // DEBUG

    while (~scanf("%d%d", &t, &m) && (t || m))
    {
        init();
        for (int i = 1; i <= m; ++i)
        {
            scanf("%d%d", c + i, w + i);
            sum[i] = sum[i - 1] + c[i];    //累计开销
        }

        int ans = 0;
        for (int i = 1; i <= m; ++i)
        {
            int bound = max(c[i], t - sum[m] + sum[i-1]);
            for (int v = t; v >= bound; --v)
            {
                dp[v] = max(dp[v], dp[v - c[i]] + w[i]);
            }
        }

        for (int i = 0; i <= t; ++i)
        {
            ans = max(ans, dp[i]);
        }

        printf("%d\n", ans);
    }

    return 0;
}