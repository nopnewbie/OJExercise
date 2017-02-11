/*
	PAT(A):1032. Sharing (25)
	Date: 2016年2月21日 21:11:09
	Finished: 2016年2月21日 21:20:31
	哈希法
*/
#include<iostream>
using namespace std;

const int maxn = 1e5 + 10;
int nxt[maxn];
bool f[maxn];

int main()
{
//	freopen("F:\\input.txt", "r", stdin);
	int ad1, ad2, n;
	scanf("%d%d%d",&ad1, &ad2, &n);
	for(int i = 0; i < n; ++i)
	{
		int a, c;
		char b;
		scanf("%d %c %d", &a, &b, &c);
		nxt[a] = c;
	}
	for(int now = ad1; now > -1; now = nxt[now]) f[now] = true;
	for(int now = ad2; now > -1; now = nxt[now])
	{
		if(f[now]) 
		{
			printf("%05d\n", now);
			return 0;
		}
	}
	puts("-1");
	return 0;
}