/*
	PAT(A):	1065. A+B and C (64bit) (20)
	Data: 2016Äê1ÔÂ7ÈÕ 18:22:49
*/
#include<iostream>
#include<string>
#include<algorithm>
#include<fstream>
#include<sstream>



using namespace std ;

const long long mid = 2 << 62 ;

int main()
{
//#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt") ;
#endif
	int T ;
	cin >> T ;
	for( int i = 1; i <= T; ++i )
	{
		long long a, b, c, ans ;
		bool flag = true ; //ture:a+b > c; false: a+b <= c
		cin >> a >> b >> c ;
		ans = a + b ;
		if( a < 0 &&
			b < 0 && 
			a + b >= 0) { flag = false ; }//Overflow, a+b<c
		else if( a > 0 && 
			b > 0 && 
			a + b <= 0 ) { flag = true ; } //Overflow, a+b>c
		else flag = ( ans > c ) ;
		cout << "Case #"<< i <<": " << (flag ? "true" : "false") << endl ;
	}
	return 0 ;
}