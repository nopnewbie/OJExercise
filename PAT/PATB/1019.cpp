/*
	PAT(B):1019. 数字黑洞 (20)
	Date: 2016年1月28日 22:09:06
*/
#include<iostream>
#include<string>
#include<cstring>
#include<cctype>
#include<fstream>
#include<algorithm>
#include<utility>
using namespace std;

void print( char *str )
{
	char a[5], b[5];
	strcpy(a, str); strcpy(b, str);
	int len = strlen(a);
	sort(a, a + len, []( const char &a, const char &b ){ return a > b; });
	sort(b, b + len);
	int na, nb;
	sscanf(a, "%d", &na);	sscanf(b, "%d", &nb);
	printf("%04d - %04d = %04d\n", na, nb, na - nb);
	if( 6174 == na - nb || na == nb ) return;
	else
	{
		char s[5];
		sprintf(s, "%04d", na-nb);
		print(s);
	}
}

int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
	freopen("F:\\input.txt", "r", stdin);
#endif
	char str[5];
	int n;
	scanf("%d", &n);
	sprintf(str, "%04d", n);
	print(str);
	return 0;
}