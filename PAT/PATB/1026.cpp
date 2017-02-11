/*
	PAT(B):1026. 程序运行时间(15)
	Date: 2016年1月30日 09:50:08
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstring>
#include<cctype>
#include<utility>
using namespace std;

int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
	freopen("F:\\input.txt", "r", stdin);
#endif
	int c1, c2, sec;
	cin >> c1 >> c2;
	c2 -= c1;
	if( c2 % 100 >= 50 ) sec = c2 / 100 + 1;
	else sec = c2 / 100;
	printf("%02d:%02d:%02d\n", sec / 3600, sec / 60 % 60, sec % 60);
	return 0;
}