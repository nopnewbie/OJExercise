#define DEBUG
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<fstream>
using namespace std;

const int maxn = 1000 + 10;
int dp[maxn][maxn];

int main()
{
#ifdef DEBUG
#define cin fin
	fstream fin("F:\\input.txt");
#endif // DEBUG
	string s;
	while (getline(cin, s))
	{
		memset(dp, 0, sizeof(dp));
		//±ß½ç
		int ans = 1;
		for (int i = 0; i < s.size(); ++i)
		{
			dp[i][i] = 1;
			if (i < s.size() - 1)
				if (s[i] == s[i + 1])
				{
					dp[i][i + 1] = 1;
					ans = 2;
				}
		}

		for (int L = 3; L <= s.size(); ++L)
		{
			for (int i = 0; i + L - 1 < s.size(); ++i)
			{
				int j = i + L - 1;	//ÓÒ¶Ëµã
				if (s[i] == s[j] && dp[i + 1][j - 1])
				{
					dp[i][j] = 1;
					ans = L;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}