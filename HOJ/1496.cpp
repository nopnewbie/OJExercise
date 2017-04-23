/*
	HOJ:1496.Equations
	Date: 2016年2月14日 14:40:05
*/
#include<iostream>
#include<map>
#include<algorithm>
#include<fstream>
using namespace std;

int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
#endif
	int a, b, c, d;
	while(cin >> a >> b >> c >> d)
	{
		if( (a > 0 && b > 0 && c > 0 && d > 0) || (a < 0 && b < 0 && c < 0 && d < 0))
		{	cout << 0 << endl;	continue; }
		map<int, int> myMap;
		for(int i = 1; i < 101; ++i)
			for(int j = 1; j < 101; ++j)
				++myMap[a*i*i + b*j*j + 1000000];
		int ans = 0;
		for(int i = 1; i < 101; ++i)
			for(int j = 1; j < 101; ++j)
				ans += myMap[1000000 - c*i*i - d*j*j];
		cout << ans * 16 << endl;
	}
	return 0;
}