/*
	PAT(A): 1011. World Cup Betting (20)
*/
#include<iostream>
#include<iomanip>
#include<fstream> 

#define cin fin

using namespace std ;

float c[3][3] ;
int pt[3] ;
char s[3] = {'W', 'T', 'L'} ;
int main()
{	
	ifstream fin("F:\\input.txt") ;
	float sum = 1 ;
	for( int i = 0; i < 3; ++i )
	{
		float maxd = c[i][0] ;
		int idx = 0 ;
		for( int j = 0; j < 3; ++j )
		{
			cin >> c[i][j] ;
			if( maxd < c[i][j] )
			{
				maxd = c[i][j] ;
				idx = j ;
			}
		}
		pt[i] = idx ;
		sum *= maxd ;
	}
	sum = (sum*0.65-1)*2 ;
	printf("%c %c %c %.2lf\n", s[pt[0]], s[pt[1]], s[pt[2]], sum) ;
	return 0 ;
}
