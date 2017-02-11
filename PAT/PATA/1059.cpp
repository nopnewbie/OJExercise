/*
	PAT(A):1059. Prime Factors (25)
	Date: 2016年2月29日 14:22:34
	Finished:
*/
#include<iostream>
#include<cmath>
using namespace std;

const int maxn = 1e5 + 10;
bool p[maxn];
struct fact
{
	int x, cnt;
}f[10];

inline void init()
{
	p[0] = p[1] = true;
	int x = sqrt((float)maxn) + 1;
	for(int i = 2; i <= x; ++i)
		for(int j = i * i; j < maxn; j += i) p[j] = true;
}

int main()
{
	freopen("F:\\input.txt", "r", stdin);
	init();
	int n, num = -1;
	scanf("%d", &n);
	if(1 == n)	{puts("1=1"); return 0;}
	printf("%d=", n);
	int x = sqrt((float)n) + 1;
	for(int i = 2; i <= x;)
	{
		if(p[i] || n % i) { ++i; continue; }
		if(-1 == num || f[num].x != i) f[++num].x = i;
		++f[num].cnt;
		n /= i;
	}
	if(n > 1)
	{
		f[++num].x = n;
		++f[num].cnt;
	}
	for(int i = 0; i <= num; ++i)
	{
		if(i) putchar('*');
		printf("%d", f[i].x);
		if(f[i].cnt > 1) printf("^%d", f[i].cnt);
	}
	return 0;
}