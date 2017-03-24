#define DEBUG

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <set>
using namespace std;

const int maxn = 500 + 5;
int dp[maxn][maxn];
int zero[maxn], ones[maxn];
int x, n, m;

int main()
{
#ifdef DEBUG
    freopen("F:\\input.txt", "r", stdin);
#endif // DEBUG
    string str;
    while (cin >> x >> n >> m)
    {
        memset(zero, 0, sizeof(zero));
        memset(ones, 0, sizeof(ones));
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < x; ++i)
        {
            cin >> str;
            for (const auto ch : str)
            {
                if ('0' == ch)
                    ++zero[i];
                else
                    ++ones[i];
            }
        }

        for (int i = zero[0]; i <= n; ++i)
            for (int j = ones[0]; j <= m; ++j)
            {
                dp[i][j] = 1;
            }
        for (int i = 1; i < x; ++i)
        {
            //for (int j = 0; j <= n; ++j)
            //{
            //    for (int k = 0; k <= m; ++k)
            //    {
            //        dp[i][j][k] = dp[i - 1][j][k];
            //        if (j >= zero[i] && k >= ones[i] && dp[i - 1][j - zero[i]][k - ones[i]] + 1 > dp[i][j][k])
            //            dp[i][j][k] = dp[i - 1][j - zero[i]][k - ones[i]] + 1;
            //    }
            //}
            for (int j = n; j >= zero[i]; --j)
                for (int k = m; k >= ones[i]; --k)
                    dp[j][k] = max(dp[j][k], dp[j - zero[i]][k - ones[i]] + 1);
        }
        cout << dp[n][m] << endl;
    }
    return 0;
}