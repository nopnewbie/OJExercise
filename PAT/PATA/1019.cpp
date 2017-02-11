/*
	PAT(A):1019. General Palindromic Number (20)
	Date:2016Äê1ÔÂ19ÈÕ 16:05:01
*/
#include<iostream>
#include<algorithm>
#include<fstream>
#include<vector>
#define LOCAL
using namespace std ;

vector<unsigned> a ;

int main()
{
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
#endif
	int n, b ;
	cin >> n >> b ;
	while( n )
	{
		a.push_back( n%b ) ;
		n /= b ;
	}
	auto ans(a);
	reverse(ans.begin(), ans.end());
	if( a == ans ) cout << "Yes";
	else cout << "No";
	cout << endl;
	if( ans.empty() ) cout << 0;
	else
	{
		cout << ans[0];
		for( int i = 1; i < ans.size(); ++i )
			cout << " " << ans[i];
		cout << endl;
	}
	return 0 ;
}