/*
	CodeUp: 2119.搬寝室
	Category: DP-01背包
	Start: 2017年2月13日 22:52:04
	End: 
*/
#define DEBUG

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int maxn = 2000 + 10;
const int INF = (1 << 30) + 10;
int n, k;
int dp[maxn][maxn/2], f[maxn];

inline void init()
{
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= k; ++j)
            dp[i][j] = j ? INF : 0;

    int dx = (f[2] - f[1]);
    dp[2][1] = dx * dx;
        
}

int main()
{
#ifdef DEBUG
    freopen("F:\\input.txt", "r", stdin);
#endif // DEBUG

    while (~scanf("%d%d", &n, &k) && (n || k) )
    {
        for (int i = 1; i <= n; ++i)
            scanf("%d", f + i);
        sort(f + 1, f + n + 1);

        init();

        for (int i = 3; i <= n; ++i)
        {
            int upperBound = min(i / 2, k);
            for (int j = 1; j <= upperBound; ++j)
            {
                int dx = f[i] - f[i - 1];
                dp[i][j] = min(dp[i - 1][j], dp[i - 2][j - 1] + dx * dx); //是否取最后一对值的方差
            }
        }

        printf("%d\n", dp[n][k]);

    }

    return 0;
}