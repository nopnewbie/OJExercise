/*
	PAT(B):1014. 福尔摩斯的约会 (20)
	Date: 2016年1月28日 14:33:03
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstring>
#include<cctype>
using namespace std;
const string weekday[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
	freopen("F:input.txt", "r", stdin);
#endif
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	for( int i = 0, cnt = 0; i < s1.size() && i < s2.size() && cnt < 2; ++i ) 
		if(!cnt && s1[i] == s2[i] && isupper(s1[i]) && s1[i] < 'H') { printf("%s", weekday[s1[i]- 'A'].c_str()); ++cnt; }
		else if( cnt && s1[i] == s2[i] )
		{
			if( isdigit(s1[i]) ) { printf(" %02d:", s1[i] - '0'); ++cnt;}
			else if( isupper(s1[i]) && 'A' <= s1[i] && 'N' >= s1[i] ) { printf(" %02d:", 10 + s1[i]- 'A'); ++cnt;}
		}
	for( int i = 0; i < s3.size() && i < s4.size(); ++i ) 
		if( s3[i] == s4[i] && isalpha(s3[i]) ) {printf("%02d\n", i); break;}
	return 0;
}