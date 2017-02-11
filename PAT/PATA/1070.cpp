/*
	PAT(A):1070. Mooncake (25)
	Date: 2016年3月6日 16:53:34
	Finished: 2016年3月6日 18:16:53
*/
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 1000 + 10;

struct Info
{
	double stock, price, total;
	bool operator < (const Info &rhs) const
	{
		return price > rhs.price;
	}
}cake[maxn];

int n, d;

int main()
{
	freopen("F:\\input.txt", "r", stdin);
	scanf("%d %d", &n, &d);
	for(int i = 0; i < n; ++i) scanf("%lf", &cake[i].stock);
	for(int i = 0; i < n; ++i) 
	{
		scanf("%lf", &cake[i].total); 
		cake[i].price = cake[i].total / cake[i].stock; 
	}
	sort(cake, cake + n);
	double ans = 0;
	for(int i = 0; i < n; ++i)
	{
		if(cake[i].stock < d)
		{
			ans += cake[i].total;
			d -= cake[i].stock;
		}
		else 
		{
			ans += cake[i].price * d;
			break;
		}
	}
	printf("%.2lf\n", ans);
	return 0;
}