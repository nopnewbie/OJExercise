#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 10000 + 10;
int a[maxn], dp[maxn][2];

int main()
{
	freopen("F:\\input.txt", "r", stdin);
	int k;
	while (~scanf("%d", &k))
	{
		for (int i = 0; i < k; ++i)
		{
			scanf("%d", a + i);
			dp[i][0] = dp[i][1] = a[i];

		}
		int ansIndex = 0;	//最大连续子列和的尾节点指针
		for (int i = 1; i < k; ++i)
		{
			if (dp[i - 1][0] + a[i] > dp[i][0])
			{
				dp[i][0] = dp[i - 1][0] + a[i];
				dp[i][1] = dp[i - 1][1];
			}
			//else do nonthing
			ansIndex = dp[i][0] > dp[ansIndex][0] ? i : ansIndex;
		}
		if (dp[ansIndex][0] > 0)
		{
			printf("%d %d %d\n", dp[ansIndex][0], dp[ansIndex][1], a[ansIndex]);
		}
		else
		{
			printf("0 %d %d\n", a[0], a[k - 1]);
		}
	}
	return 0;
}