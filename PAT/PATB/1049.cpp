/*
	PAT(B):1049. 数列的片段和(20)
	Date: 2016年2月5日 00:33:37
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;

int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
#endif
	int n;
	double ans = 0;
	cin >> n;
	vector<double> vd(n,0);
	for(int i = 0; i < n; ++i)
	{
		double x;
		cin >> x;
		ans += x * (n - i) * (i + 1);
	}
	printf("%.2f\n", ans);
	return 0;
}