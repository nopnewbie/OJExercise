/*
	PAT(A):1023. Have Fun with Numbers (20)
	Date:2016年1月19日 16:33:18
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#define LOCAL
using namespace std ;

int main()
{
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt") ;
#endif
	vector<int> cnt_a(10), cnt_b(10);
	string a, b ;
	cin >> a ;
	for( decltype(a.size()) i = 0; i < a.size(); ++i ) ++cnt_a[ a[i]-='0' ];
	reverse(a.begin(), a.end()) ;
	int c = 0 ;	//c为进位,模拟竖式乘法
	for( decltype(a.size()) i = 0; i < a.size(); ++i )
	{
		b.push_back( (a[i] * 2 + c)%10 ) ;
		c = a[i]*2/10 ;
	}
	if( c ) b.push_back(c);
	reverse( b.begin(), b.end() );
	for( decltype(b.size()) i = 0; i < b.size(); ++i ) {++cnt_b[ b[i] ]; b[i] += '0';}
	cout << ( cnt_a == cnt_b ? "Yes" : "No" ) << endl;
	cout << b << endl;
	return 0 ;
}