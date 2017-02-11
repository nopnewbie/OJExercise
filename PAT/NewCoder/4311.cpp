/*
	牛客网PAT
		Rational Sum (20)
		Date: 2016年1月4日09:01:19
*/
#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>

#define LOCAL

using namespace std ;

long long GCD( long long x, long long y )
{// Greatest Common Divisior of x and y
	return y?GCD(y, x % y) : x ;
}

long long LCM( long long x, long long y )
{//Least Common Multipule
	long long u = GCD( x, y ) ;
	return x*y/u ;
}

int main()
{
#ifdef LOCAL
	freopen("F:\\input.txt", "r", stdin) ;
#endif
	int n ;
	long long a1, b1, a2, b2, integer = 0 ;
	while( scanf("%d", &n) != EOF)
	{
		integer = 0 ;
		scanf("%lld/%lld", &a1, &b1) ;
		for( int i = 1; i < n; ++i )
		{
			scanf("%lld/%lld", &a2, &b2) ;
			long long aa = a1*b2 + a2*b1 ;
			long long bb = b1*b2 ;
			long long gcd = GCD( aa, bb ) ;
			a1 = aa / gcd ;
			b1 = bb / gcd ;
			integer += a1/b1 ;
			a1 %= b1 ;
		}
		if( integer ) printf("%lld", integer) ;
		if( a1)
		{
			if( integer ) putchar(' ') ;
			if( (a1 > 0 && b1 < 0) || (a1 < 0 && b1 > 0) ) putchar('-') ;
			printf("%lld/%lld", abs(a1), abs(b1) ) ;
		}
		else if( !integer ) printf("0") ;
		putchar('\n') ;
	}
	return 0;
}