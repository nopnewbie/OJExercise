/*
	PAT(A):1048. Find Coins (25)
	Date: 2016年2月26日 21:00:44
	Finished:
	双指针
*/
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 1e5 + 10;
int a[maxn];

int main()
{
	freopen("F:\\input.txt", "r", stdin);
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i) scanf("%d", a + i);
	sort(a, a + n);
	int p = 0, q = n - 1;
	while(p < q)
	{
		if(a[p] + a[q] > m) --q;
		else if(a[p] + a[q] < m) ++p;
		else 
		{
			printf("%d %d\n", a[p], a[q]);
			return 0;
		}
	}
	puts("No Solution");
	return 0;
}