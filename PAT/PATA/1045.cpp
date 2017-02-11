/*
	PAT(A):1045. Favorite Color Stripe (30)
	start: 2017年2月11日 16:51:44
	end: 2017年2月11日 19:34:32

    Tip: LIS
*/
#define DEBUG

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<cstring>

using namespace std;

const int maxn = 10000 + 10;
int n, m, l;
map<int, int> color2Value;
vector<int> s;
int dp[maxn];

inline void read()
{
    scanf("%d%d", &n, &m);
    for (int i = 0, c; i < m; ++i)
    {
        scanf("%d", &c);
        color2Value[c] = i;
    }

    scanf("%d", &l);
    s.clear();
    for (int i = 0, c; i < l; ++i)
    {
        scanf("%d", &c);
        auto it = color2Value.find(c);
        if (it != color2Value.end())
            s.push_back(it->second);
        //if (it == color2Value.end())
        //    stripe[i].value = maxn;
        //else
        //    stripe[i].value = it->second;
    }
}


int main()
{
#ifdef DEBUG
    freopen("F:\\input.txt", "r", stdin);
#endif // DEBUG

    read();
    int ans = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        dp[i] = 1;
        for (int j = 0; j < i; ++j)
        {
            if (s[j] <= s[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }

    printf("%d\n", ans);


    return 0;
}