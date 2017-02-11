/*
	PAT(B):1008. 数组元素循环右移问题 (20)
	Date: 2016年1月27日 22:05:56
*/
#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
using namespace std;

int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
#endif
	int n, m;
	cin >> n >> m;
	vector<int> num(n);
	for( int i = 0; i < n; ++i ) cin >> num[i];
	m %= n;
	cout << num[ (n - m) % n ];
	for(int i = 1; i < n; ++i) cout << ' ' << num[(n - m + i) % n];
	cout <<endl;
	return 0;
}