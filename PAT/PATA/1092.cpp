/*
	PAT(A):1092. To Buy or Not to Buy (20)
	Date: 2016Äê1ÔÂ21ÈÕ 20:47:16
*/
#include<iostream>
#include<fstream>
#include<cstring>
#include<algorithm>
#include<cctype>
using namespace std;
#define LOCAL
const int maxn = 1<<10;
char s1[maxn], s2[maxn];
int tag1[128], tag2[128];
int main()
{
#ifdef LOCAL
#define cin fin 
	ifstream fin("F:\\input.txt");
	freopen("F:\\input.txt", "r", stdin);
#endif
	while( scanf("%s %s", s1, s2) != EOF ) 
	{
		int len1 = strlen(s1), len2 = strlen(s2);
		int ex = 0, need = 0;
		memset( tag1, 0, sizeof(tag1) );
		memset( tag2, 0, sizeof(tag2) );
		for( int i = 0; i < len1; ++i ) ++tag1[ s1[i] ];
		for( int i = 0; i < len2; ++i )	 ++tag2[ s2[i] ];
		for( int i = 0; i < 128; ++i )
		{
			if( tag1[i] < tag2[i] ) need += tag2[i] - tag1[i];
			else ex += tag1[i] - tag2[i];
		}
		if( need ) printf("No %d\n", need);
		else printf("Yes %d\n", ex);
	}
	return 0;
}