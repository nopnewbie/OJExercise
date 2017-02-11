/*
	PAT(A):1105. Spiral Matrix (25)
	Date: 2016年3月8日 09:51:03
	Finished: 
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

const int maxn = 1e4 + 10;
int n, a[maxn], out[maxn][maxn], cnt;

inline int calc()
{
	int x = sqrt((float)n);
	while(n % x) --x;
	return x;
}

void myfill(int x1, int y1, int x2, int y2, int &idx)
{
	if(x1 > x2 || y1 > y2 || idx < 0)	return;
	for(int i = y1; i <= y2; ++i)			out[x1][i]	=	a[idx--];
	if(idx < 0) return;
	for(int i = x1 + 1; i <= x2; ++i)	out[i][y2]	=	a[idx--];
	if(idx < 0) return;
	for(int i = y2 - 1; i >= y1; --i)		out[x2][i]	=	a[idx--];
	if(idx < 0) return;
	for(int i = x2 - 1; i > x1; --i)			out[i][y1]	=	a[idx--];
	if(idx < 0) return;
	myfill(x1+1, y1 + 1, x2 - 1, y2 - 1, idx);
}

int main()
{
	freopen("F:\\input.txt", "r", stdin);
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) scanf("%d", a + i);
	sort(a, a + n);
	int col = calc();
	int row = n / col;
	myfill(0, 0, row - 1, col - 1, cnt = n - 1);
	for(int i = 0; i < row; ++i)
	{
		printf("%d", out[i][0]);
		for(int j = 1; j < col; ++j) printf(" %d", out[i][j]);
		puts("");
	}
	return 0;
}