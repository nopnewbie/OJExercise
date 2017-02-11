/*
	PAT(B):1027. 打印沙漏(20)
	Date: 2016年1月30日 10:12:25
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

int a[1001] = {0}, b[1001] = {0};

int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
#endif
	a[1] = b[1] = 1;
	for( int i = 2; i < 1001; ++i ) { a[i] += a[i - 1] +  i * 4 -2; b[i] = (i * 2 - 1);}
	int x;
	char ch;
	cin >> x >> ch;
	int level = 1;
	while( a[level] <= x ) ++level;
	--level;	//三角形的高度
	for( int i = level; i > 0; --i )
	{
		for( int j = 0; j < level - i; ++j ) putchar(' ');
		for( int j = 0; j < b[i]; ++j ) putchar(ch);
		putchar('\n');
	}
	for( int i = 2; i <= level; ++i )
	{
		for( int j = 0; j < level - i; ++j ) putchar(' ');
		for( int j = 0; j < b[i]; ++j ) putchar(ch);
		putchar('\n');
	}
	printf("%d", x - a[level]);
	return 0;
}