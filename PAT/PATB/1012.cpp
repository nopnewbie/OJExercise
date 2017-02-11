/*
	PAT(B):1012. 数字分类 (20)
	Date: 2016年1月28日 11:00:37
*/
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<cctype>
#include<fstream>
#include<algorithm>
using namespace std;
const double zero = 10e-7;
int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
	freopen("F:\\input.txt", "r", stdin);
#endif
	int n, a1 = 0, a2 = 0, a3 = 0, a5 = -1, cnt_a4 = 0;
	double a4 = 0;
	vector<int> v;
	for( cin >> n; n; --n )
	{
		int x;
		cin >> x;
		int left = x % 5;
		if( !left && !(x % 2) ) a1 += x;
		if( 1 == left ) v.push_back(x);
		if( 2 == left ) ++a3;
		if( 3 == left ) { ++cnt_a4; a4 += x; }
		if( 4 == left ) a5 = a5 > x ? a5 : x;
	}
	for( int i = 0; i < v.size(); ++i )
	{
		if( i % 2 ) a2 -= v[i];
		else a2 += v[i];
	}
	if( a1 ) printf("%d", a1); else printf("N");
	if( !v.empty() ) printf(" %d", a2); else printf(" N");
	if( a3 ) printf(" %d", a3); else printf(" N");
	if( cnt_a4) printf(" %.1lf", a4 / cnt_a4); else printf(" N");
	if( a5 > 0) printf(" %d\n", a5); else printf(" N\n");
	return 0;
}