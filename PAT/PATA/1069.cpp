/*
	PAT(A):1069. The Black Hole of Numbers (20)
	Date: 2016年1月22日 12:59:03
*/
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<cctype>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;
#define LOCAL

void print( const char s[] )
{
	char a[5] = {0}, b[5] = {0};
	strcpy(a, s); strcpy(b, s);
	sort(a, a+4, [](const char &x, const char &y){ return x > y; });
	sort(b, b+4);
//	int u = atoi(a), v = atoi(b);
	int u, v;
	sscanf(a, "%d", &u); sscanf(b, "%d", &v);
	printf("%04d - %04d = %04d\n", u, v, u - v);
	if( u == v || 6174 ==  (u - v) ) return;
	else
	{
		char buf[5];
		//itoa(u - v, buf, 10); //itoa非标准库函数
		sprintf(buf, "%04d", u - v);
		print(buf);
	}
}

int main()
{
#ifdef LOCAL
#define cin fin 
	ifstream fin("F:\\input.txt");
	freopen("F:\\input.txt", "r", stdin);
#endif

	char s[5] = {0};
	int n;
	scanf("%d", &n);
	sprintf(s, "%04d", n);
	print(s);
	return 0;
}