/*
	PAT(A)1077. Kuchiguse (20)
	Date: 2016Äê1ÔÂ20ÈÕ 21:55:12
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
using namespace std;
#define LOCAL
int main()
{
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
#endif
	string s, ans;
	int n;
	for(cin >> n, cin.get(), getline(cin, ans); n-1; --n)
	{
		getline(cin, s);
		int i = ans.size() - 1, j = s.size() - 1;
		while( i >= 0 && j >= 0 && ans[i] == s[j] ){ --i; --j; }
		ans = s.substr( j + 1 ) ;
		if( ans.empty() ) { cout << "nai" << endl; return 0;}
	}
	cout << ans << endl;
	return 0;
}

