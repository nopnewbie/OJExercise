/*
	最长回文子串
*/
#define DEBUG

#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>

using namespace std;

const int maxn = 5000 + 10;
string originString;
int dp[maxn][maxn];
int l, r;

struct Node
{
    char ch;
    int pos;
    Node(const char c, const int p) : ch(tolower(c)), pos(p) {}
};

vector<Node> S;

inline void init()
{
    l = r = 0;

    S.clear();
    for (int i = 0; i < originString.size(); ++i)
    {
        if (isalpha(originString[i]))
        {
            S.push_back({ originString[i],i });
        }
    }
    
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < S.size()-1; ++i)
    {
        dp[i][i] = 1;
        //dp[i][i + 1] = S[i].ch == S[i + 1].ch ? 1 : 0;
        if (S[i].ch == S[i + 1].ch)
        {
            dp[i][i + 1] = 1;
            if (!l && !r)
            {
                l = i;
                r = i + 1;
            }
        }
    }
    dp[S.size() - 1][S.size() - 1] = 1;
}

int main()
{
#ifdef DEBUG
    freopen("F:\\input.txt", "r", stdin);
#endif // DEBUG

    while (getline(cin, originString))
    {
        init();
        for (int len = 3; len <= S.size(); ++len)  //控制长度
        {
            bool flag = true;
            for (int i = 0; i + len - 1 < S.size(); ++i)
            {
                int j = i + len - 1;
                //dp[i][j] = S[i].ch == S[j].ch ? dp[i + 1][j - 1] : 0;
                if (S[i].ch == S[j].ch && dp[i + 1][j - 1])
                {
                    dp[i][j] = 1;
                    if (flag)
                    {
                        flag = false;
                        l = S[i].pos;
                        r = S[j].pos;
                    }
                }
            }
        }

        printf("%s\n", originString.substr(l, r - l + 1).c_str());

    }
    return 0;
}