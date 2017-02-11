/*
	PAT(B):1006. 换个格式输出整数 (15)
	Date: 2016年1月27日 21:30:34
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
#endif
	int a, b, c, n;
	cin >> n;
	a = n / 100;
	b = n / 10 % 10;
	c = n % 10;
	if( a )
	{
		for( int i = 0; i < a; ++i ) putchar('B');
		for( int i = 0; i < b; ++i ) putchar('S');
		for( int i = 1; i <= c; ++i ) putchar('0' + i);
	}
	else if( b )
	{
		for( int i = 0; i < b; ++i ) putchar('S');
		for( int i = 1; i <= c; ++i ) putchar('0' + i);
	}
	else if( c )	for( int i = 1; i <= c; ++i ) putchar('0' + i);
	if(a || b || c) putchar('\n');
	return 0;
}