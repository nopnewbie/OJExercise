/*
	PAT(B):1001. 害死人不偿命的(3n+1)猜想 (15)
	Date: 2016年1月27日 14:15:24
*/
#define LOCAL
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cstring>
#include<cctype>
#include<algorithm>
using namespace std;

int main()
{
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
	freopen("F:\\inpu.txt", "r", stdin);
#endif
	int n, cnt;
	cin >> n;
	for( cnt = 0; 1 != n; ++cnt )
		if( n % 2 ) n = (3 * n + 1) >> 1;
		else n >>= 1;
	cout << cnt << endl;
	return 0;
}