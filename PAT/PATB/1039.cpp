/*
	PAT(B):1039. 到底买不买（20）
	Date: 2016年2月1日 20:05:01
*/
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<cctype>
#include<algorithm>
using namespace std;
int a[128] = {0}, b[128] = {0};
int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
#endif
	string s1, s2;
	cin >> s1 >> s2;
	for( int i = 0; i < s1.size(); ++i ) ++a[s1[i]];
	for( int i = 0; i < s2.size(); ++i) ++b[s2[i]];
	int surplus = 0, lack = 0;
	for( int i = 0; i < 128; ++i ) 
		if(a[i] >= b[i]) surplus += a[i] - b[i];
		else lack += b[i] - a[i];
	if(lack) cout << "No " << lack << endl;
	else cout << "Yes " << surplus << endl;
	return 0;
}