/*
	PAT(A)1050. String Subtraction (20)
	Date:2016年1月19日 21:00:30
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std ;
#define LOCAL
int main()
{
#ifdef LOCAL
#define cin fin 
	ifstream fin("F:\\input.txt");
#endif
	string s1, s2; 
	vector<vector<int>> pos(128) ;
	getline(cin,s1); getline(cin, s2) ;
	for( unsigned i = 0; i < s1.size(); ++i )
	{
		pos[ s1[i] ].push_back(i) ;
	}
	for( unsigned i = 0; i < s2.size(); ++i )
	{
		for( unsigned j = 0; j < pos[s2[i]].size(); ++j ) s1[ pos[s2[i]][j] ] = -1 ;
	}
	for( unsigned i = 0; i < s1.size(); ++i ) if( s1[i] > -1 ) cout << s1[i];
	cout << endl ;
	return 0 ;
}