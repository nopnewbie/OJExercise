/*
	PAT(B):1009. 说反话 (20)
	Date: 2016年1月28日 09:48:58
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstring>
#include<cctype>
#include<algorithm>
#include<sstream>
using namespace std;

int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
	freopen("F:\\input.txt", "r", stdin);
#endif
	string line;
	getline(cin, line);
	stringstream ss(line);
	vector<string> ans;
	while( ss >> line ) ans.push_back( line );
	if( ans.empty() ) cout << "ans is empty" << endl;
	else
	{
		cout << ans.back();
		for( int i = ans.size() - 2; i >= 0; --i ) cout << ' ' << ans[i];
		cout << endl;
	}
	return 0;
}