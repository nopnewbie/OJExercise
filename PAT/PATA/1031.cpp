/*
	PAT(A)1031. Hello World for U (20)
	Date: 2016年1月20日 21:04:10
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std ;

#define LOCAL
char ans[1024] = {} ;
int main()
{
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
#endif
	int  n1, n2, n3, cnt = 0 ;
	string s;
	cin >> s;
	n1 = n3 = (s.size() + 2) / 3;
	n2 = s.size() - 2 * n1 + 2 ;
	for( int i = 0; i < n1-1; ++i )
	{
		ans[cnt++] = s[i] ;
		for( int j = 0; j < n2 - 2; ++j ) ans[cnt++] = ' ';
		ans[cnt++] = s[s.size() - 1 - i];
		ans[cnt++] = '\n';
	}
	for( int i = n1 - 1; i < n1 + n2 - 1; ++i ) ans[cnt++] = s[i];
	ans[cnt++] = '\n';	ans[cnt] = '\0';
	cout << ans;
	return 0 ;
}