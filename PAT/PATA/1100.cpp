#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<fstream>
#include<algorithm>

using namespace std ;

const char low[][6] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"} ;
const char high[][6] = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"} ;
int N ;

int main()
{
#define cin fin
	fstream fin("F:\\input.txt") ;
	cin >> N ;
	string str ;
	for( int i = 0; i < N; ++i )
	{
		cin >> str ;
		if(str[0] >= '0' && str[0] <= '9')
		{
			int num = 0 ;
			reverse( str.begin(), str.end() ) ;
			for(int j = 0; j < str.size(); ++j)
			{
				num += (str[j]-'0')*pow( (float)10, j ) ;
			}
			int l = num%13 ;
			int h = num/13 ;
			if(h) 
			{
				cout << high[h];
				if( l ) cout << ' ' << low[l] ;
				cout << endl ;
			}
			else	cout << low[l] << endl ;
		}
		else
		{
			int ans = 0 ;
			for( int j = 0; j < 13; ++j )
			{
				if( str == high[j] )
				{
					ans += 13*j ;	break ;
				}
				else if(str == low[j])
				{
					ans += j ;	break ;
				}
			}
			string s1 ;
			getline(cin, s1) ;
			if( !s1.empty() )
			{
				string s2(s1.begin()+1, s1.end()) ;
				for( int j = 0; j < 13; ++j )
				{
					if( s2 == low[j] )
					{
						ans += j ; break ;
					}
				}
			}
			cout << ans << endl ;
		}
	}
	return 0 ;
}