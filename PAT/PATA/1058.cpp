#include<iostream>
#include<fstream>

using namespace std ;

int a, b, c , d, e, f;
const int digit = 10e7 + 1;
int main()
{
	freopen("F:\\input.txt", "r", stdin) ;
	scanf("%d.%d.%d %d.%d.%d", &a, &b, &c, &d, &e, &f) ;
	printf("%d.%d.%d\n",  (a+d+ ( (b+e)+(c+f)/29 )/17 )%digit, ( (b+e)+(c+f)/29 )%17, (c+f)%29) ; 
	return 0 ;
}