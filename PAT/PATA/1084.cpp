/*
	PAT(A):1084. Broken Keyboard (20)
	Date: 2016年1月21日 20:00:09
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include<cctype>
#include<cstring>
using namespace std;
#define LOCAL
bool lost[128+10];
int main()
{
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
	freopen("F:\\input.txt", "r", stdin);
#endif
	char s1[85] = {}, s2[85] = {};
	scanf("%s %s", s1, s2);
	int i, j, len1 = strlen(s1), len2 = strlen(s2) ;
	memset( lost, false, sizeof(lost) );
	for( i = j = 0; i < len1 && j < len2;  )
	{
		if( s2[j] != s1[i] )	
		{
			if( !lost[ tolower(s1[i]) ] && !lost[ toupper( s1[i] ) ] )
			{//没输出过
				lost[ tolower(s1[i]) ] = lost[ toupper( s1[i] ) ] = true;
				putchar( isalpha(s1[i]) ? toupper(s1[i]) : s1[i] );
			}
			++i;
		}
		else { ++j; ++i; }
	}
	while( i < len1 )
	{
		if( s2[j] != s1[i] )	
		{
			if( !lost[ tolower(s1[i]) ] && !lost[ toupper( s1[i] ) ] )
			{//没输出过
				lost[ tolower(s1[i]) ] = lost[ toupper( s1[i] ) ] = true;
				putchar( isalpha(s1[i]) ? toupper(s1[i]) : s1[i] );
			}
			++i;
		}
	}
	putchar('\n');
	return 0;
}