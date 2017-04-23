#define DEBUG
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 100 + 10;
double dp[maxn], p[maxn];
int n;

inline void init()
{
    fill(dp, dp + n + 1, 0.0);
    dp[0] = 1 - p[1];
    dp[1] = p[1];
}

int main()
{
#ifdef DEBUG
    freopen("F:\\input.txt", "r", stdin);
#endif // DEBUG
    while (~scanf("%d", &n))
    {
        for (int i = 1; i <= n; ++i)
        {
            scanf("%lf", p + i);
            p[i] /= 100;
        }

        init();
        for (int i = 2; i <= n; ++i)
        {
            for (int j = i; j >= 0; --j)
            {
                dp[j] = dp[j - 1] * p[i] + dp[j] * (1 - p[i]);
            }
        }

        int lestRight = ceil(n*0.6);
        double sum = 0;
        for (int i = lestRight; i <= n; ++i)
            sum += dp[i];
        printf("%.5lf\n", sum);
    }
    return 0;
}