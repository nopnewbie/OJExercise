/*
	PAT(B):1007. 素数对猜想 (20)
	Date: 2016年1月27日 21:45:08
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstring>
#include<cstring>
#include<cctype>
#include<algorithm>
using namespace std;
const int maxn = 10e5;
bool not_prime[maxn + 10] = {false};

int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
	freopen("F:\\input.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	for( int i = 2; i <= n; ++i )
		for( int j = 2; i * j <= n; ++j )	not_prime[i * j] = true;
	int cnt = 0;
	for( int i = 2; i + 2 <= n; ++i ) if( !not_prime[i] && !not_prime[i + 2] ) ++cnt;
	cout << cnt << endl;
	return 0;
}