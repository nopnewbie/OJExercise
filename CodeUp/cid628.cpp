/*
	最长公共子列(LCS, Longgest Common Sequence)
*/

#define DEBUG
#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn = 100 + 10;
int dp[maxn][maxn];
char A[maxn], B[maxn];
int lenA, lenB;
string strA, strB;

inline void init()
{
	sprintf(A + 1, "%s", strA.c_str());
	sprintf(B+1, "%s", strB.c_str());
	lenA = strA.size();
	lenB = strB.size();
	
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= lenA; ++i)
		dp[0][i] = 0;

    for(int i = 0; i <= lenB; ++i)
        dp[i][0] = 0;
}

int main()
{
#ifdef DEBUG
    freopen("F:\\input.txt", "r", stdin);
#endif // DEBUG
    
    while (cin >> strA >> strB)
    {
        init();
        for(int i = 1; i <= lenB; ++i)
            for (int j = 1; j <= lenA; ++j)
            {
                if (B[i] == A[j])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }

        printf("%d\n", dp[lenB][lenA]);
    }
    return 0;
}
