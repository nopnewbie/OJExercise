/*
	PAT(B):1010. 一元多项式求导 (25)
	Date: 2016年1月28日 10:12:40
*/
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<cctype>
#include<algorithm>
#include<fstream>
#include<utility>
using namespace std;

typedef pair<int, int> pairInt;
int a[2000 + 10] = {0};

int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
	freopen("F:\\input.txt", "r", stdin);
#endif
	 int c, e;
	 vector<pairInt> ans;
	 while( cin >> c >> e )
	 {
		 if( e ) ans.push_back( pairInt(e - 1, e * c) );
	 }
	 if( ans.empty() ) cout << "0 0" << endl;
	 else 
	 {
		 sort( ans.begin(), ans.end(), []( const pairInt &a, const pairInt &b ){ return a.first > b.first; } );
		 cout << ans[0].second << " " << ans[0].first;
		 for( int i = 1; i < ans.size(); ++i ) cout << " " << ans[i].second << " " << ans[i].first;
		 cout << endl;
	 }
	return 0;
}