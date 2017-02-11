/*
	最长不降子列(LIS,Longest Increasing Sequence)
*/

#include<iostream>
//#include<fstream>
#include<vector>

using namespace std;

#define DEBUG

const int maxn = 1000 + 10;
int n, a[maxn];// dp[maxn];
vector<vector<int>> dp[maxn];


int main()
{
#ifdef DEBUG
    freopen("F:\\input.txt", "r", stdin);
#endif // DEBUG

    while (~scanf("%d", &n) && n)
    {
        vector<vector<int>> ans;

        for (int i = 0; i < n; ++i)  scanf("%d", a + i);
        dp[0].push_back(vector<int>(1,a[0]));
        ans = dp[0];

        int maxLen = 1;
        for(int i = 1; i < n; ++i)
        {
            dp[i].clear();
            dp[i].push_back(vector<int>(1,a[i]));

            for (int j = 0; j < i; ++j)
            {
                if (a[j] < a[i] && dp[j].front().size() + 1 > dp[i].front().size())
                {
                    dp[i].clear();
                    dp[i] = dp[j];
                    for (auto& seq : dp[i])
                    {
                        seq.push_back(a[i]);
                    }

                    if (dp[i].front().size() > ans.front().size())
                    {
                        ans.clear();
                        ans = dp[i];
                    }
                    else if (dp[i].front().size() == ans.front().size())
                    {
                        for (const auto& seq : dp[i])
                            ans.push_back(seq);
                    }

                    maxLen = maxLen > dp[i].front().size() ? maxLen : dp[i].front().size();
                }
            }
        }      

        printf("%d\n", maxLen);
        for (auto& seq : ans)
        {
            for (int i = 0; i < seq.size(); ++i)
            {
                if (i)   printf(" %d", seq[i]);
                else printf("%d", seq[i]);
            }
            puts("");
        }
    }

    return 0;
}
