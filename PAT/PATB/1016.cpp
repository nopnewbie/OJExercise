/*
	PAT(B):1016. 部分A+B (15)
	Date: 2016年1月28日 16:51:36
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstring>
#include<cctype>
#include<algorithm>
using namespace std;

int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
	freopen("F:\\input.txt", "r", stdin);
#endif
	char a[11] = {0}, da, b[11]= {0}, db;
	scanf("%s %c %s %c", a, &da, b, &db);
	int len1 = strlen(a), len2 = strlen(b);
	char buf[11] = {0};
	int i, cnt, na = 0, nb = 0;
	for( i = 0, cnt = 0; i < len1; ++i ) if( da == a[i] ) buf[cnt++] = a[i];
	buf[cnt] = '\0';
	if(cnt) sscanf(buf, "%d", &na);
	for( i = 0, cnt = 0; i < len2; ++i ) if( db == b[i] ) buf[cnt++] = b[i];
	buf[cnt] = '\0';
	if(cnt) sscanf(buf, "%d", &nb);
	long long ans = na + nb;
	printf("%lld\n", ans );
	return 0 ;
}
