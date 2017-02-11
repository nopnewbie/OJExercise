/*
	PAT(A):1104. Sum of Number Segments (20)
	Date: 2016Äê1ÔÂ21ÈÕ 21:31:29
*/
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<cctype>
#include<vector>
#include<algorithm>
using namespace std;
#define LOCAL

int main()
{
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
	freopen("F:\\input.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	double ans = 0, x;
	for( int i = 0; i < n; ++i ) 
	{ 
		cin >> x;
		ans += x*(i+1)*(n-i);
	}
	printf("%.2lf\n", ans);
	return 0;
}