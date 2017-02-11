/*
	PAT(A):1010. Radix (25)
	Date: 2016年2月24日 19:44:02
	Finished:2016年2月24日 22:44:33
*/
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

long long c2n[128];

inline void init()
{
	for(int i = 0; i < 10; ++i) c2n['0' + i] = i;
	for(int i = 10; i < 36; ++i) c2n['a' + i - 10] = i;
}

long long trans(const string &s, long long r, long long t)
{
	long long tmp = 0;
	for(long long i = 0 ; i < s.size(); ++i)
	{
		tmp = tmp * r + c2n[s[i]];
		if(tmp < 0 || tmp > t) return -1;	//溢出或者比另一个数大
	}
	return tmp;
}

long long bisearch(long long x, const string &str)
{
	long long r, l = -1;
	for(auto i = 0; i < str.size(); ++i) l = max(c2n[str[i]] + 1, l);
	r = max(l, x) + 1;//?
	while(l <= r)
	{
		long long mid = l + (r - l) / 2;
		long long tmp = trans(str, mid, x);
		if(tmp < 0) r = mid - 1;	//溢出或太大
		else if(tmp == x) return mid;
		else if(tmp < x) l = mid + 1;
		else r = mid - 1;
	}
	return -1;
}

int main()
{
	init();
	freopen("F:\\input.txt", "r", stdin);
	char n[2][11];
	int tag, radix;
	scanf("%s%s%d%d", n[0], n[1], &tag, &radix);
	if(string(n[0]) == string(n[1])) { printf("%d\n", radix); return 0;}
	long long deci = 0;
	string s(n[tag - 1]);
	for(long long i = 0; i < s.size(); ++i) deci = deci * radix + c2n[s[i]];
	long long ans = bisearch(deci, n[2 - tag]);
	if(ans < 0) puts("Impossible");
	else printf("%lld\n", ans);
	return 0;
}