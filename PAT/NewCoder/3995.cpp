/*
	牛客网PAT 3995
		Product of Polynomials (25)
		Date: 15.12.28
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#define LOCAL
using namespace std ;

const int maxn = 2000 + 10 ;
const double zero = 1.e-8 ;
double c1[maxn], c2[maxn], c3[maxn] ;
bool nonzero[maxn] ;

int main()
{
#ifdef LOCAL
	freopen( "F:\\input.txt", "r", stdin ) ;
#endif
	memset(c1, 0, sizeof(c1) ) ;
	memset(c2, 0, sizeof(c2) ) ;
	memset(c3, 0, sizeof(c3) ) ;
	int n, e , max1 = -1 , max2 = -1;
	double c ;
	scanf( "%d", &n ) ;
	for( int i = 0; i < n; ++i )
	{
		scanf("%d %lf", &e, &c) ;
		c1[e] = c ; max1 = max1 > e ? max1 : e ;
	}
	scanf( "%d", &n ) ;
	for( int i = 0; i < n; ++i )
	{
		scanf("%d %lf", &e, &c) ;
		c2[e] = c ; max2 = max2 > e ? max2 : e ;
	}
	int cnt = 0 ;
	for( int i = 0; i <= max1; ++i )
		for( int j= 0; j <= max2; ++j )
		{
			c3[i+j] += c1[i]*c2[j] ;
		}
	for( int i = 0; i <= max1+max2; ++i ) if( abs( c3[i] ) > zero ) ++cnt ;
	printf( "%d", cnt ) ;
	for( int i = max1 + max2; i >= 0; --i ) if( abs( c3[i] ) > zero ) printf( " %d %.1lf", i, c3[i] ) ;
	putchar('\n') ;
	return 0 ;
}