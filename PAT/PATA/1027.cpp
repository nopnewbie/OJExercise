#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<fstream>

using namespace std ;

#define cin fin
ifstream fin("F:\\input.txt") ;

const char digt[13] = {'0' , '1','2', '3','4', '5', '6', '7', '8', '9', 'A', 'B', 'C'} ;
int main()
{
	int c ;
	stack<int> s ;
	vector<int> rgb ;
	while( cin >> c )
	{
		int begin = s.size() - 1 ;
		if(c < 13) rgb.push_back(0) ;
		do
		{
			s.push(c%13) ;
			c /= 13 ;
		}while( c ) ;
		while( !s.empty() ) 
		{
			rgb.push_back( s.top() ) ;
			s.pop() ;
		}
	}
	cout << '#' ;
	for( int i = 0; i < rgb.size(); ++i )
	{
		cout << digt[ rgb[i] ] ;
	}
	cout << endl ;
	return 0 ;
}