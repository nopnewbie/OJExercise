/*
	PAT(B):1048. 数字加密(20)
	Date: 2016年2月4日23:46:05
*/
#include<iostream>
#include<string>
#include<algorithm>
#include<fstream>
using namespace std;

const char n2c[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K'};

int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
#endif
	string a, b, ans;
	cin >> a >> b;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	if(a.size() < b.size()) for(int i = a.size(); i < b.size(); ++i ) a.push_back('0');
	else for(int i = b.size(); i < a.size(); ++i) b.push_back('0');
	for(int i = 0; i < a.size() && i < b.size(); ++i)
		if(i % 2) ans.push_back( (b[i] - a[i] + 10) % 10 + '0' );
		else ans.push_back( n2c[(a[i] - '0' + b[i] - '0') % 13] );
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
	return 0;
}