/*
	PAT(B):1018. 锤子剪刀布 (20)
	Date: 2016年1月28日 21:33:58
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<fstream>
using namespace std;

struct Player
{
	int c, j, b, win[128], lose, draw;
	Player(){ c = j = b = lose = draw = 0; for( int i = 0; i < 128; ++i ) win[i] = 0;}
};
int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
	freopen("F:\\input.txt", "r", stdin);
#endif
	Player x, y;
	int n;
	for( cin >> n; n; --n )
	{
		string a, b;
		cin >> a >> b;
		if( a == b ) { ++x.draw; ++y.draw; }
		else if( ("C" == a && "J" == b) || ("J" == a && "B" == b) || ("B" == a && "C" == b))	{++x.win[a[0]]; ++y.lose;}
		else { ++x.lose; ++y.win[b[0]]; }
	}
	printf("%d %d %d\n", x.win['C'] + x.win['J'] + x.win['B'], x.draw, x.lose);
	printf("%d %d %d\n", y.win['C'] + y.win['J'] + y.win['B'], y.draw, y.lose);
	if( x.win['B'] >= x.win['C'] && x.win['B'] >= x.win['J'] ) putchar('B');
	else if( x.win['C'] > x.win['B'] && x.win['C'] >= x.win['J'] ) putchar('C');
	else putchar('J');
	putchar(' ');
	if( y.win['B'] >= y.win['C'] && y.win['B'] >= y.win['J'] ) putchar('B');
	else if( y.win['C'] > y.win['B'] && y.win['C'] >= y.win['J'] ) putchar('C');
	else putchar('J');
	putchar('\n');
	return 0;
}