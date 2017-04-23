/*
	HOJ:1398.Square Coins
	Date: 2016年2月22日 14:13:58
	母函数
*/
#include<iostream>
#include<fstream>
using namespace std;

const int maxn = 300 + 10;
int c1[maxn], c2[maxn];
int ans[maxn];

inline void init()
{
	for(int i = 0; i < maxn; ++i) c1[i] = c2[i] = 0;
	for(int i = 0; i <= 17; ++i) c1[i*i] = 1;
	for(int i = 1; i <= 17; ++i)
	{
		for(int j = 0; j <= 17; ++j )
			for(int k = )
	}
}

int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
#endif
	int n;
	init();
	while(cin >> n && n)	cout << ans[n] << endl;
	return 0;
}