/*
	PAT(A):1048. Find Coins (25)
	Date: 2016年2月13日 21:59:15
	Finished:
	二分查找
*/
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 1e5 + 10;
int a[maxn];

inline int bisearch(int left, int right, int x)
{
	int mid;
	while(left < right)
	{
		mid = left + (right - left) / 2;
		if(a[mid] < x) left = mid + 1;
		else right = mid;
	}
	return left;
}

int main()
{
	freopen("F:\\input.txt", "r", stdin);
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i) scanf("%d", a + i);
	sort(a, a + n);
	bool flag = true;
	for(int i = 0; i < n; ++i)
	{
		int j = /*bisearch(i + 1, n, m - a[i])*/lower_bound(a + i + 1, a+n, m - a[i]) - a;
		if(j < i || j >= n || a[j] + a[i] != m) continue;
		printf("%d %d\n", a[i], a[j]);
		flag = false;
		break;
	}
	if(flag) puts("No Solution");
	return 0;
}