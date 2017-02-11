/*
	PAT(A):1085. Perfect Sequence (25)
	Date: 2016年2月24日 15:16:47
	Finished:2016年2月24日 19:41:54
	二分法
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 100000 + 10;
long long a[maxn];

int main()
{
	freopen("F:\\input.txt", "r", stdin);
	long long n, p;
	scanf("%lld%lld", &n, &p);
	for(int i = 0; i < n; ++i) scanf("%lld", a + i);
	sort(a, a + n);
	int ans = 1;
	for(int i = 0, j; i < n; ++i) if((j = upper_bound(a + i, a + n, a[i] * p) - a - i) > ans) ans = j;
	printf("%d\n", ans);
	return 0;
}