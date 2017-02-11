/*
	PAT(B):1005. 继续(3n+1)猜想 (25)
	Date: 2016年1月27日 20:44:49
*/
#define LOCAL
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstring>
#include<cctype>
#include<algorithm>
using namespace std;
const int maxn = 1 << 16;
int tag[maxn + 10] = {0};
int main()
{
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
	freopen("F:\\inpu.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	vector<int> num(n), ans;
	for( int i = 0; i < n; ++i ) 
	{
		int x, y;
		cin >> x; 
		num[i] = x;		y = x;
		while( 1 != x )
		{
			if( x % 2 && !tag[(3 * x + 1) >> 1] ) x = (3 * x + 1) >> 1;
			else if( !(x %2) && !tag[x>>1] ) x >>= 1;
			else break;
			tag[x] = y;
			y = x;
		}
	}
	for( int i = 0; i < n; ++i ) if( !tag[num[i]] ) ans.push_back(num[i]);
	sort( ans.begin(), ans.end(), greater<int>() );
	if( ans.empty() ) cout << "ans is empty" << endl;
	else
	{
		cout << ans[0];
		for( int i = 1; i < ans.size(); ++i ) cout << " " << ans[i];
		cout << endl;
	}
	return 0;
}