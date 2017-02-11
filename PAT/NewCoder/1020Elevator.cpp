/*
	牛客网PAT
		Elevator (20)
		Date: 15.12.28
*/
#include<iostream>
#include<fstream>

using namespace std ;

int main()
{
#define cin fin
	ifstream fin("F:\\input.txt") ;
	int n, a = 0, b; 
	cin >> n;  
	int ans =  n*5 ;
	for( int i = 0; i < n; ++i, a = b )
	{
		cin >> b ;
		if( a < b ) ans += (b-a)*6 ;
		else ans += (a-b)*4 ;
	}
	cout << ans << endl ;
	
	return 0 ;
}