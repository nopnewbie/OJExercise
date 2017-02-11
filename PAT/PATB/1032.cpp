/*
	PAT(B):1032. 挖掘机技术哪家强(20)
	Date: 2016年1月31日 13:36:04
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstring>
#include<cctype>
#include<utility>
using namespace std;

const int maxn = 1e5;
int school[maxn + 10] = {0};
int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
	freopen("F:\\input.txt", "r", stdin);
#endif
	int n, num = 0, max_score = -1;
	for(cin >> n; n; --n  )
	{
		int x, y;
		cin >> x >> y;
		if( (school[x] += y) > max_score ) {num = x; max_score = school[x];}
	}
	cout << num << " " << max_score << endl;
	return 0;
}