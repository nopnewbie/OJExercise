/*
	PAT(T):1028. List Sorting (25)
	Date:2016Äê1ÔÂ16ÈÕ 18:18:08
*/
#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>
#include<vector>
#include<iomanip>
#define LOCAL
using namespace std ;

struct Info
{
	int ID, grade ;
	string name ;
} ;
bool cmp1( const Info &a, const Info &b  )
{
	return a.ID <  b.ID ;
}
bool cmp2( const Info &a, const Info &b  )
{
	if( a.name != b.name )
		return a.name <  b.name ;
	else 
		return a.ID < b.ID ;
}
bool cmp3( const Info &a, const Info &b  )
{
	if( a.grade != b.grade )
		return a.grade <  b.grade ;
	else 
		return a.ID < b.ID ;
}

bool (*cmp[3])( const Info &a, const Info &b ) = { cmp1, cmp2, cmp3 } ;

int main()
{
#ifdef LOCAL
#define cin fin 
	ifstream fin("F:\\input.txt");
#endif
	int n, c ;
	while( cin >> n >> c )
	{
		vector<Info> record(n) ;
		for( int i = 0; i < n; ++i )
		{
			cin >> record[i].ID >> record[i].name >> record[i].grade ;
		}
		sort( record.begin(), record.end(), cmp[c-1] ) ;
		for( int i = 0; i < record.size(); ++i )
		{
			printf("%06d %s %d\n", record[i].ID, record[i].name.c_str(), record[i].grade) ;
		}
	}
	return 0 ;
}