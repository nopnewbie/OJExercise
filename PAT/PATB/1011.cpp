/*
	PAT(B):1011. A+B和C (15)
	Date: 2016年1月28日 10:37:49
*/
#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
#endif
	int n;
	cin >> n;
	long long a, b, c;
	for( int i = 1; i <= n; ++i )
	{
		cin >> a >> b >> c;
		cout << "Case #" << i << ": " << ( (a + b > c) ? "true" : "false" ) << endl;
	}
	return 0;
}