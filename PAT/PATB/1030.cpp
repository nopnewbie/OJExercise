/*
	PAT(B):1030. 完美数列(25)
	Date: 2016年1月30日 16:00:50
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 1e5;
long long a[maxn + 10] = {0};
int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
	freopen("F:\\input.txt", "r", stdin);
#endif
	long long n, p;
	scanf("%lld %lld", &n, &p);
	for( int i = 0; i < n; ++i ) scanf("%d", a + i);
	sort(a, a + n);
	int ans = 1;
	for( int i = 0; i < n ; ++i )
	{
		for( int j = i + ans - 1; j < n; ++j ) 
			if( a[j] <= p * a[i] ) ans = ans > j - i + 1 ? ans : j - i + 1;
			else break;
	}
	printf("%d\n", ans);
	return 0;
}