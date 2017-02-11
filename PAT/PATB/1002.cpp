/*
	PAT(B):1002. 写出这个数 (20)
	Date: 2016年1月27日 20:16:38
*/
#define LOCAL
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstring>
#include<cctype>
#include<algorithm>
using namespace std;
const string digit[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
int main()
{
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
	freopen("F:\\input.txt", "r", stdin);
#endif
	string s;
	cin >> s;
	int n = 0;
	for( int i = 0; i < s.size(); ++i )
	{
		n += s[i] - '0';
	}
	char num[6] = {0};
	//itoa( n, num, 10);
	sprintf(num, "%d", n);
	string ans(num);
	if( ans.empty() ) cout << "ans is empty" << endl;
	else 
	{
		cout << digit[ ans[0] - '0' ];
		for(int i = 1; i < ans.size(); ++i) cout << ' ' << digit[ ans[i]- '0' ];
		cout << endl;
	}
	return 0;
}