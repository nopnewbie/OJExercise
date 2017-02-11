/*
	PAT(B):1017. A除以B (20)
	Date:2016年1月28日 18:37:11
	模拟竖式除法
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<list>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
#endif
	string s;
	int d;
	cin >> s >> d;
	for( int i = 0; i < s.size(); ++i ) s[i] -= '0';
	list<int> ans;
	int left = 0;
	for(int i = 0; i < s.size(); ++i )
	{
		int x = left * 10 +  s[i];
		ans.push_back(  x / d );
		if( left = x % d ) s[i] = left;	//有余数
	}
	while( !ans.empty() && !ans.front() ) ans.pop_front();
	if( ans.empty() ) cout << 0;
	else	for( auto it = ans.begin(); it != ans.end(); ++it ) cout << *it;
	cout << " " << left << endl;
	return 0;
}