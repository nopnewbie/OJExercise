/*
	CodeUp:	2018.数列
	Date:2016年2月17日 13:01:27
*/
#include<iostream>
using namespace std;

int ans[22];

inline void init()
{
	ans[1] = 1;
	for(int i = 2; i < 22; ++i) ans[i] = ans[i - 1] + ans[i - 2];
}

int main()
{
	int n, m;
	init();
	while(~scanf("%d", &m))
	{
		for(int i = 0; i < m; ++i)
		{
			scanf("%d", &n);
			for(int j = 1 ; j <= n; ++j )
			{//控制行号
				for(int k = n - j; k > 0; --k) printf("  ");
				printf("0");
				for(int k = 1; k < 2*j - 1; ++k) printf(" %d", ans[k]);
				puts("");
			}
		}
	}
	return 0;
}