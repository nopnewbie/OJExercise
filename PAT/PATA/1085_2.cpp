/*
	PAT(A):1085. Perfect Sequence (25)
	Date: 2016年2月25日 14:49:17
	Finished:2016年2月25日 15:14:56
	双指针
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1e5 + 10;
long long a[maxn];

int main()
{
	freopen("F:\\input.txt", "r", stdin);
	long long n, p;
	scanf("%lld%lld", &n, &p);
	for(int i = 0; i < n; ++i) scanf("%lld", a + i);
	sort(a, a + n);
	int ans = 0;
	for(int i = 0, j = 0; i < n && j < n; )
	{
		if(a[i] * p < a[j]) ++i;
		else
		{
			ans = max(ans, j - i + 1);
			++j;
		}
	}
	printf("%d\n", ans);
	return 0;
}