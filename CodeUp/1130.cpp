/*
	CodeUp: 1130.拔河
	Category: 01背包
	Start:2017年2月26日 21:30:40
	
*/
#define DEBUG

#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 100 + 10;
int n;
int w[maxn], dp[maxn][maxn/2][450*50+10];

int main()
{
#ifdef DEBUG
    freopen("F:\\input.txt", "r", stdin);
#endif // DEBUG
    while (~scanf("%d", &n))
    {
        int sum = 0;
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; ++i) 
        {
            scanf("%d", w + i);
            sum += w[i];
        }

        const int V1 = n / 2;
        const int V2 = sum / 2;

        dp[0][1][w[0]] = w[0];
        for (int i = 1; i < n; ++i) 
        {
            for (int j = 1; j <= V1; ++j) 
            {
                for (int k = 0; k <= V2; ++k)
                {
                    
                    dp[i][j][k] = dp[i - 1][j][k];
                    if (w[i] < V2 && dp[i][j][k] < dp[i - 1][j - 1][k - w[i]] + w[i])
                    {
                        dp[i][j][k] = dp[i - 1][j - 1][k - w[i]] + w[i];
                    }
                        
                }
            }
        }

        printf("%d %d\n", dp[n - 1][V1][V2], sum - dp[n - 1][V1][V2]);

    }
    return 0;
}