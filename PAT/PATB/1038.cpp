/*
	PAT(B):1038. 统计同成绩学生(20)
	Date: 2016年2月1日 19:52:11
*/
#include<iostream>
#include<fstream>
#include<map>
#include<algorithm>
using namespace std;
const int maxn = 1e5;
int table[maxn + 10] = {0};
int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
#endif
	int n;
	map<int, int> score_count;
	for (cin >> n; n; --n)
	{
		int x;
		cin >> x; 
//		++score_count[x];
		++table[x];
	}
	for(cin >> n; n; --n)
	{
		int x; 
		cin >> x;
		cout << /* score_count[x] */ table[x] << (n > 1 ? " " : "");
	}
	return 0;
}