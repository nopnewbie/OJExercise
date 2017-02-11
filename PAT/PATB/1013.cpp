/*
	PAT(B):1013. 数素数 (20)
	Date: 2016年1月28日 11:45:22
*/
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<fstream>
#include<algorithm>
using namespace std;
const int maxn = 1 << 20;
vector<bool> prime(maxn + 10,true);
int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin 
	ifstream fin("F:\\input.txt");
#endif
	prime[0] = prime[1] = false;
	int x = sqrt((float)maxn) + 1;
	for( long long i = 2; i <= x ; ++i ) // x的x倍 >= maxn
		for( long long j = i * i ; j <= maxn; j += i ) prime[j] = false;
		/*i的1 ~ i 倍在之前就已经筛过了.*/
	int m, n;
	cin >> m >> n;
	vector<int> ans;
	for( int i = 2, cnt = 0; i <= maxn && cnt < n; ++i )	
		if(prime[i])
		{
			if(++cnt >=m)	ans.push_back( i );
		}
	for( int i = 0; i < ans.size(); ++i )
	{
		if( i % 10 ) cout << " ";
		cout << ans[i];
		if( 9 == i % 10 ) cout << endl;
	}
	return 0;
}