/*
	PAT(A):1038. Recover the Smallest Number (30)
	Date: 2016年2月19日 14:34:37
*/
#include<iostream>
#include<string>
#include<algorithm>
#include<fstream>
#include<vector>
using namespace std;

bool cmp(const string &a, const string &b )	{return a + b < b + a;}

int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
#endif
	unsigned n;
	cin >> n;
	vector<string> vstr(n);
	for(unsigned i = 0; i < n; ++i) cin >> vstr[i];
	sort(vstr.begin(), vstr.end(), cmp);
	string ans = "";
	for(auto i = 0; i < n; ++i) ans += vstr[i];
	unsigned st = 0;
	while(st < ans.size() - 1 && ans[st] == '0') ++st;
	cout << string(ans.begin() + st, ans.end()) << endl;
	return 0;
}