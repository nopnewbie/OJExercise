/*
	PAT(A): 1068. Find More Coins (30)
	Category: DP-背包
	Start: 2017年2月15日 20:02:34
*/
#define DEBUG
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

const int maxn = 10000 + 10;
int n, m, dp[maxn], c[maxn];
bool choice[maxn][110], flag[maxn];

inline void init()
{
    memset(dp, 0, sizeof(dp));
}

int main()
{
#ifdef DEBUG
    freopen("F:\\input.txt", "r", stdin);
#endif // DEBUG
    while (~scanf("%d%d", &n, &m))
    {
        init();
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", c + i);
//            sum[i] = sum[i - 1] + c[i];
        }
        
        sort(c + 1, c + n + 1);

        for (int i = 1; i <= n; ++i)
        {
            //int bound = max(c[i], m - sum[n] + sum[i - 1]);
            //vector<int> tmp;
            for (int v = m; v >= c[i]; --v)
            {
                dp[v] = max(dp[v], dp[v - c[i]] + c[i]);
                if (dp[v] == dp[v - c[i]] + c[i])
                    choice[i][v] = true;    //选取第i件物品
            }
        }

        if (m != dp[m])
        {
            puts("No Solution");
        }
        else
        {
            int k = 1, v = m, num = 0;
            while (k <= n)
            {
                if (choice[k][v])   //选择了第k件物品
                {
                    flag[k] = true;
                    v -= c[k]; //前k-1件物品剩余容量
                    ++num;
                }
                else
                {
                    flag[k] = false;
                }
                ++k;
            }

            for (int i = 1; i <= n; ++i)
            {
                if (flag[i])
                {
                    printf("%d", c[i]);
                    if (--num) printf(" ");
                }
            }
            puts("");
        }

    }
    return 0;
}