/*
	PAT(B):1020. 月饼 (25)
	Date: 2016年1月28日 22:33:23
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstring>
#include<cctype>
#include<algorithm>
using namespace std;

struct Cake
{
	double amount, totalPrice;	//如果按照题目所说数量和总价都用int则有一个数据点过不了
	double perTonePrice;
	Cake():amount(0), totalPrice(0), perTonePrice(0){}
};

int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
	freopen("F:\\input.txt", "r", stdin);
#endif
	int n, d;
	cin >> n >> d;
	vector<Cake> cake(n);
	for( int i = 0; i < n; ++i )	cin >> cake[i].amount;
	for( int i = 0; i < n; ++i )	{ cin >> cake[i].totalPrice; cake[i].perTonePrice =cake[i].totalPrice /cake[i].amount; }
	sort( cake.begin(), cake.end(), []( const Cake &a, const Cake &b ){ return a.perTonePrice > b.perTonePrice; } );
	double ans = 0;
	for( int i = 0; i < cake.size() && d; ++i )
	{
		if( cake[i].amount <= d ) { d -= cake[i].amount; ans += cake[i].totalPrice; }
		else { ans += cake[i].perTonePrice * d; break;}
	} 
	printf("%.2lf\n", ans);
	return 0;
}