/*
	PAT(A):1093. Count PAT's (25)
	Date: 2016年2月23日 18:36:29
	Finished:
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

const int maxn = 1000000007;

int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
	freopen("F:\\input.txt", "r", stdin);
#endif
	string s;
	cin >> s;
	int p = 0, pa = 0, pat = 0;
	for(int i = 0; i < s.size(); ++i)
	{
		if('P' == s[i]) p = (p + 1) % maxn;
		else if('A' == s[i]) pa = (pa + p) %maxn ;
		else pat = (pat + pa) % maxn;
	}
	cout << pat << endl;
	return 0;
}