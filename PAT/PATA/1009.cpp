/*
	PAT(A): 1009.Product of Polynomials (25)
	浮点数检测是否为零应注意: 在与精度比较前应该取绝对值
*/
#include<iostream>
#include<fstream>
#include<algorithm>

#define LOCAL

using namespace std ;

const int maxn = 1000 + 5 ;
const double zero = 1e-12 ;
float c[2][maxn] , c1[2*maxn];

int main()
{
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt") ;
#endif
	int k, n, maxExp = -1 ;
	float a ;
	for( int i = 0; i < 2 ; ++i )
	{
		cin >> k ;
		for( int j = 0; j < k; ++j )
		{
			cin >> n >> a ;
			c[i][n] = a ;
			maxExp = maxExp > n ? maxExp : n ;
		}
	}
	for( int i = 0; i <= maxExp; ++i )
	{
		for( int j = 0; j <= maxExp; ++j )
		{
			c1[i+j] += c[0][i] * c[1][j] ;
		}
	}
	int cnt = 0 ; 
	for( int i = 0; i <= 2*maxExp; ++i )
	{
		if(abs(c1[i]) > zero) ++cnt ;
	}
	printf("%d", cnt) ;
	for( int i = 2*maxExp; i >= 0; --i ) if( abs(c1[i]) > zero ) printf(" %d %.1f", i, c1[i]) ;
	printf("\n") ;
	return 0 ;
}