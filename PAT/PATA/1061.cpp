/*
	PAT(A)1061. Dating (20)
	Date: 2016年1月17日 16:43:08
*/
#include<iostream>
#include<fstream>
#include<string>
#include<cctype>
using namespace std ;
#define LOCAL
string weekday[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
int main()
{
#ifdef LOCAL
#define cin fin 
	ifstream fin("F:\\input.txt");
#endif
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4 ;
	for( unsigned i = 0, cnt = 0; i < s1.size() && i < s2.size(); ++i )
	{
		if( !cnt && s1[i] >= 'A' && s1[i] <= 'G' && s1[i] == s2[i] )	
		{
			printf("%s ", weekday[ s1[i] - 'A' ].c_str() ); //第一个相同的大写字母
			++cnt;
		}
		else if( 1 == cnt && s1[i] == s2[i]  )
		{
			if( isdigit( s1[i] ) ) { printf( "%02d:", s1[i] - '0' ); ++cnt; } 
			else if( isupper( s1[i] ) && s1[i] <= 'N' ) { printf("%02d:", s1[i] - 'A' + 10) ; ++cnt; }
		}
		if( cnt >= 2 ) break;
	}
	for( unsigned i = 0; i < s3.size() && i < s4.size(); ++i )
		if( isalpha( s3[i] ) && s3[i] == s4[i] ) { printf("%02d\n", i ) ; break; }
	return 0;
}