/*
	HOJ:1496.Equations
	Date: 2016年2月14日 14:40:05
	Ps:	非map版
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<fstream>
using namespace std;

const int maxn = 30007;
int f[maxn], g[maxn];

int myHash(int k)
{
	int u = (k % maxn + maxn) % maxn;
	while( f[u] && g[u] != k ) u = (u + 1) % maxn;
	return u;
}

int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
#endif
	int a, b, c, d;
	while( cin >> a >> b >> c >> d )
	{
		if((a > 0 && b > 0 && c > 0 && d > 0) || (a < 0 && b < 0 && c < 0 && d < 0))
		{ cout << 0 << endl; continue; }
		memset(f, 0, sizeof(f));
		memset(g, 0, sizeof(g));
		for(int i = 1; i < 101; ++i)
			for(int j = 1; j < 101; ++j)
			{
				int key = a*i*i + b*j*j;
				int p = myHash(key);
				g[p] = key;
				++f[p];
			}
		int ans = 0;
		for(int i = 1; i < 101; ++i)
			for(int j = 1; j < 101; ++j)
			{
				int key = c*i*i + d*j*j;
				int p = myHash(-key);
				ans += f[p];
			}
		cout << (ans << 4) << endl;
	}
	return 0;
}