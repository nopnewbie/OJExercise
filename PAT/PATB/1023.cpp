/*
	PAT(B):1023. 组个最小数 (20)
	Date: 2016年1月29日 15:31:20
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
	freopen("F:\\input.txt", "r", stdin);
#endif
	int d[10] = {0};
	vector<int> ans, zero;
	for( int i = 0; i < 10; ++i )
	{
		cin >> d[i];
		if(i)	for( int j = 0; j < d[i]; ++j ) ans.push_back(i);
		else for( int j = 0; j < d[i]; ++j )	zero.push_back(i);
	}
	cout << ans[0];
	for(int i = 0; i < zero.size(); ++i) cout << zero[i];
	for(int i = 1; i < ans.size(); ++i) cout << ans[i];
	cout << endl;
	return 0;
}