/*
	PAT(A): 1008.Elevator (20)
*/
#include<iostream>

using namespace std ;

int n ;

int main()
{
	int a, b = 0, sum = 0 ;
	cin >> n ;
	sum += n*5 ;
	for(int i = 0; i < n; ++i)
	{
		cin >> a ;
		if(a>b) sum += (a-b)*6 ;
		else sum += (b-a)*4 ;
		b = a ;
	}
	cout << sum <<endl ;
	return 0 ;
}