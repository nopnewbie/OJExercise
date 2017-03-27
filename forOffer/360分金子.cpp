/*
	分金子:
    dp[L][R]含义为“从[L,R]范围内可以取得的最多黄金数量”。
    对于dp[L][R]这一次取，可以从两端取，也就是取第L个或者第R个。分别考虑两种情况：
    1. 取左边，则下一个人只能在[L+1,R]上取, 可以取得最大值为dp[L+1][R]；
    2. 取右边，则下一个人只能在[L,R-1]上取,可以取得最大值为dp[L][R-1]；
    记sum(x,y)表示[x,y]之间元素之和。
    那么，对于情况1来说，本次取能得到的最大值应该是sum(L,R) - min(dp[L+1][R],dp[L][R-1]);
    边界：
    1.只有一个元素，毫无疑问，直接取。故dp[i][i] = a[i];
    2. 只有两个元素，取大的那一个。dp[i][i+1] = max(a[i],a[i+1]);
*/
#define DEBUG

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 500 + 10;
int dp[maxn][maxn], sum[maxn];
int t, n;

int main()
{
#ifdef DEBUG
    freopen("F:\\input.txt", "r", stdin);
#endif // DEBUG
    while (~scanf("%d", &t))
    {
        int n, tmp;
        for (int ii = 1; ii <= t; ++ii)
        {
            scanf("%d", &n);
            memset(dp, 0, sizeof(dp));
            for (int i = 1; i <= n; ++i)
            {
                scanf("%d", &tmp);
                sum[i] = sum[i - 1] + tmp;
                dp[i][i] = tmp; // 边界1
                dp[i-1][i] = max(dp[i-1][i-1], tmp);
            }

            for (int len = 3; len <= n; ++len)
            {
                for (int i = 1; i + len - 1 <= n; ++i)
                {
                    int j = i + len - 1;
                    dp[i][j] = sum[j] - sum[i - 1] - min(dp[i + 1][j], dp[i][j - 1]);
                }
            }
            printf("Case #%d: %d %d\n", ii, dp[1][n], sum[n] - dp[1][n]);
        }

    }
    return 0;
}