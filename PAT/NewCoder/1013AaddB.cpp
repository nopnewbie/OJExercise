/*
	牛客网PAT
		A+B Format (20)
		Date: 15.12.28
*/

#include<iostream>
#include<algorithm>
#include<fstream>
#include<string>

using namespace std ;

int main()
{
#define cin fin
	ifstream fin( "F:\\input.txt" ) ;
	long long a, b ;
	long long c, d ;
	cin >> a >> b ;
	a += b ;		b = abs(a) ;
	string ss ;
	for( int i = 0; i < 7; ++i )
	{
//		if(i && !(i%3) ) ss.push_back(',') ;
		ss.push_back( b%10+'0' ) ;
		b /= 10 ;
	}
	for( int i = ss.size()-1; i >=0 ; --i )
	{
		if( ss[i] != '0' ) break ;
		else ss.pop_back() ;
	}
	string ans ;
	for( int i = 0 , j = 0; i < ss.size(); ++i, ++j )
	{
		if( j == 3)
		{
			ans.push_back(',') ;
			j = 0 ;
		}
		ans.push_back(ss[i]) ;
	}
	reverse( ans.begin(), ans.end() ) ;
	if( a < 0 ) cout << '-' ;
	for( int i = 0; i < ans.size(); ++i ) cout << ans[i] ;
	cout << endl ;
	return 0 ;
}