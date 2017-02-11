/*
	PAT(A)1041. Be Unique (20)
	Date: 2016年1月19日 20:19:26
*/
#include<iostream>
#include<fstream>
#include<vector>
using namespace std ;

#define LOCAL
const unsigned maxn = 10000 + 10;
vector<unsigned> cnt(maxn,0);
int main()
{
#ifdef LOCAL
//#define cin fin
//	ifstream fin("F:\\input.txt");
	freopen("F:\\input.txt", "r", stdin);
#endif
	unsigned n; 
	scanf("%u", &n);
	vector<unsigned> in(n) ;
	for( int i = 0; i < n; ++i )
	{
		scanf("%u", &in[i]);
		++cnt[ in[i] ];
	}
	for( int i = 0; i < n; ++i )
	{
		if( 1 == cnt[ in[i] ] ) 
		{
			printf("%u\n", in[i]) ;
			return 0 ;
		}
	}
	puts("None");
	return 0;
}