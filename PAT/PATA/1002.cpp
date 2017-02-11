/*
	PAT(A): 1002.A+B for Polynomials (25)
	注意浮点陷阱
*/
#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>

#define cin fin

using namespace std ;

const double MINN = 0.0000001 ;
double a[1001] ;
int k ;

int main()
{
	ifstream fin("F:\\input.txt") ;
	int e, maxE = -1, cnt = 0 ; 
	double c ;
	for( int i = 0; i < 2; ++i )
	{
		cin >> k ;
		for( int j = 0; j < k ; ++j )
		{
			cin >> e >> c ;
			a[e] += c ; maxE = e > maxE ? e : maxE ;
		}
	}
	for(int i = maxE; i >= 0; --i)
	{
		if( abs(a[i]) > MINN )
		{
			++cnt ;
		}
	}
	printf("%d", cnt) ;
	for(int i = maxE; i >= 0; --i)
	{
		if( abs(a[i]) > MINN )
		{
			printf(" %d %.1lf", i, a[i]) ;
		}
	}
	printf("\n") ;
	return 0 ;
}