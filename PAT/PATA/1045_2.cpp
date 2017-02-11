/*
	PAT(A): 1045. Favorite Color Stripe (30)
	start: 2017年2月11日 19:36:02
	end: 
*/
#define DEBUG

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int maxn = 10000 + 10;
const int maxc = 200 + 10;

int n, m, l;
int c[maxc], s[maxn];
int dp[maxc][maxn];

inline void read()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
        scanf("%d", c + i);

    scanf("%d", &l);
    for (int i = 1; i <= l;++i)
        scanf("%d", s + i);
}

inline void init()
{
    memset(dp, 0, sizeof(dp));
    //for (int i = 0; i <= m; ++i)
    //    dp[i][0] = 0;
    //for (int i = 0; i <= l; ++i)
    //    dp[0][i] = 0;
}

int main()
{
#ifdef DEBUG
    freopen("F:\\input.txt", "r", stdin);
#endif // DEBUG
    
    read();
    init();

    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= l; ++j)
        {
            dp[i][j] = (c[i] == s[j] ? 1 : 0) + max(dp[i - 1][j - 1], max(dp[i - 1][j], dp[i][j - 1]));
        }
    }
    printf("%d\n", dp[m][l]);
    return 0;
}