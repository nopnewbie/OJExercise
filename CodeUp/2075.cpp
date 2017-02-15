/*
	CodeUp: 2075.点菜问题
	Category: DP-01背包
	Start:2017年2月13日 20:23:14
	End: 
*/

#define DEBUG

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int maxc = 1000 + 10;
const int maxn = 100 + 10;

int t, n;

int dp[maxc];
int c[maxn]; //每道菜的花销
int w[maxn]; //每道菜的评分
int sum[maxn]; //前n道菜的累计花销

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

    while (~scanf("%d%d", &t, &n))
    {
        init();
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d%d", c + i, w + i);
            sum[i] = sum[i - 1] + c[i];
        }

        int ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            int bound = max(c[i], t - sum[n] + sum[i - 1]);
            for (int v = t; v >= bound; --v)
            {
                dp[v] = max(dp[v], dp[v - c[i]] + w[i]);
                ans = max(ans, dp[v]);
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}