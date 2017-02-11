/*
	PAT(B):1021. 个位数统计 (15)
	Date: 2016年1月29日 11:25:50
*/
#include<iostream>
#include<string>
using namespace std;

int main()
{
	int d[10] = {0};
	string num;
	cin >> num;
	for(char i : num) ++d[ i-'0'];
	for( int i = 0; i < 10; ++i ) if( d[i] ) cout << i << ':' << d[i] << endl;
	return 0;
}