/*
	PAT(B):1036. 跟奥巴马一起编程(15)
	Date: 2016年2月1日 19:30:59
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
	char ch;
	int n;
	cin >> n >> ch;
	string s(n, ch), s2(n, ' ');
	s2[0] = s2[s2.size()-1] = ch;
	cout << s << endl;
	for(int i = 0; i < (n + 1) / 2 - 2; ++i) cout << s2 << endl;
	cout << s << endl;
	return 0;
}