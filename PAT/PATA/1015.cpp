/*
	PAT(A): 1015.Reversible Primes (20)
*/
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<fstream>

using namespace std ;

#define fin cin

bool isPrime( int x )
{
	if( x < 2 ) return false ;
	if( x == 2 ) return true ;
	for( int i = 2; i*i <= x; ++i )
	{//素数判断i*i <= x 等号不能忘记
		if( !(x%i) ) return false ;
	}
	return true ;
}

int main()
{
	ifstream fin("F:\\input.txt") ;
	int n, d ;
	while(cin >> n && n >= 0)
	{
		cin>> d ;
		if(!isPrime(n)) 
		{
			puts("No") ;
			continue ;
		}
		vector<int> num ;
		do
		{
			num.push_back(n%d) ;
		}while( n/=d ) ;
		for( int i = num.size()-1, tmp = 1 ; i >= 0; --i, tmp *= d )
		{
			n += num[i]*tmp ;
		}
		if(isPrime(n)) puts("Yes") ;
		else puts("No") ;
	}
	return 0 ;
}