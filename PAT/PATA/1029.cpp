/*
	PAT(A):1029. Median (25)
	Date: 2016年2月26日 19:43:19
	Finished:2016年2月26日 20:23:19
	双指针
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const long long INF = 0x0fffffffffffffff;

int main()
{
	freopen("F:\\input.txt", "r", stdin);
	long n1, n2;
	scanf("%ld", &n1);
	vector<long long> v1(n1+1), v2;
	v1[n1] = INF;
	for(long i = 0; i < n1; ++i) scanf("%lld", &v1[i]);
	scanf("%ld", &n2);
	v2.resize(n2+1);
	v2[n2] = INF;
	for(long i = 0; i < n2; ++i) scanf("%lld", &v2[i]);
	long long i = 0, j = 0, mid = (n1 + n2 - 1) / 2, ans = 0;
	while( i + j <= mid)
	{
		if(v1[i] <= v2[j]) ans = v1[i++];
		else ans = v2[j++];
	}
	printf("%lld\n", ans);
	//sort(vl.begin(), vl.end());
	//printf("%ld\n", vl[(n2 - 1) / 2]);
	return 0;
}