/*
	PAT(B):1050. 螺旋矩阵(25)
	Date: 2016年1月30日 10:52:46
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

const int maxn = 1e4 ;
int a[maxn + 10][110];
int num[maxn + 10];
int m, n, N;
int main()
{
//#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
	freopen("F:\\input.txt", "r", stdin);
#endif
	memset(a, 0, sizeof(a));
	cin >> N;
	for( int i = 1; i * i <= N; ++i )	if( !(N % i) ) n = i;
	m = N / n;	//N可能是素数,所以m可能等于N.此时数组a要有至少N+1行
	for( int i = 0; i < N; ++i ) scanf("%d", num + i);
	sort(num, num + N, greater<int>());
	a[1][1] = num[0];
	for( int cnt = 0, x = 1, y = 1; cnt < N - 1; )
	{
		while( cnt < N && y + 1  <= n && !a[x][y + 1]) a[x][++y] = num[++cnt];
		while( cnt < N && x + 1 <= m && !a[x + 1][y]) a[++x][y] = num[++cnt];
		while( cnt < N && 1 < y && !a[x][y - 1]) a[x][--y] = num[++cnt];
		while( cnt < N && 1 < x && !a[x - 1][y]) a[--x][y] = num[++cnt];
	}
	for( int i = 1; i <= m; ++i )
	{
		printf("%d", a[i][1]);
		for( int j = 2; j <= n; ++j ) printf(" %d", a[i][j]);
		putchar('\n');
	}
	return 0;
}