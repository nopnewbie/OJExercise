#define DEBUG

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;

typedef long long LL;

const LL KB = 1024;
LL dp[4096 * 50+10], a[55], sum;
LL n;

inline void init()
{
    memset(dp, 0, sizeof(dp));
    sum = 0;
}

int main()
{
#ifdef DEBUG
    freopen("F:\\input.txt", "r", stdin);
#endif // DEBUG
    while (~scanf("%lld", &n))
    {
        init();
        LL len;
        for (LL i = 1; i <= n; ++i)
        {
            scanf("%lld", &len);
            a[i] = len / KB;
            sum += a[i];
        }
        const LL vol = sum / 2;

        for (LL i = a[1]; i <= vol; ++i)
            dp[i] = a[1];
        for (LL i = 2; i <= n; ++i)
            for (LL j = vol; j >= a[i]; --j)
                dp[j] = max(dp[j], dp[j - a[i]] + a[i]);
        
        LL maxLen = max(dp[vol], sum - dp[vol]);
        printf("%lld\n", maxLen * KB);
    }
	return 0;
}