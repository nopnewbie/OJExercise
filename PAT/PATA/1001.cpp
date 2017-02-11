/*
	Pat A: 1001.A+B Format (20)
*/
#include<iostream>
#include<cstdlib>

using namespace std ;

int a, b, c ;
char d[10] ;

int main()
{
	freopen("F:\\input.txt", "r", stdin) ;
	while(~scanf("%d%d", &a, &b))
	{
		int i ;
		c = a + b ;
		if (!c) puts("0") ;
		else
		{
			if(c < 0) 
			{
				printf("-") ;
				c = ~c + 1 ;
			}
			for( i = 1; c > 0; ++i )
			{
				if(!(i%4)) d[i++] = ',' ;
				d[i] = c%10 + '0' ;
				c /= 10 ;
			}
			while(i>0) printf("%c", d[--i]) ;	
			printf("\n") ;
		}
	}
	return 0 ;
}
