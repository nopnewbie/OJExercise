/*
	PAT(B):1022. D进制的A+B (20)
	Date: 2016年1月29日 11:40:00
*/
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<list>
#include<cstring>
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
	long long a, b, d;
	cin >> a >> b >> d;
	a += b;
	list<long long> ans;
	while( a )
	{
		ans.push_front(a % d);
		a /= d;
	}
	if(ans.empty()) cout << 0;
	else	for( auto it = ans.begin(); it != ans.end(); ++it ) cout << *it;
	cout << endl;
	return 0;
}