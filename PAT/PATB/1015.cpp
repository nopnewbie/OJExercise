/*
	PAT(B):1015. 德才论 (25)
	Date: 2016年1月28日 15:04:12
*/
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<algorithm>
#include<cstring>
#include<cctype>
using namespace std;

struct Stu
{
	int id, d, c, total;
	Stu(){}
	Stu( int _id, int _d, int _c ):id(_id), d(_d), c(_c), total(_d + _c){}
	bool operator < (const Stu &a) const
	{
		if( total != a.total )	return total > a.total; 
		else if( d != a.d ) return d > a.d;
		else return id < a.id;
	}
};

int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
	freopen("F:\\input.txt", "r", stdin);
#endif
	int n, l , h;
	cin >> n >> l >> h;
	vector<Stu> rank1, rank2, rank3, rank4;
	int id, d, c;
	for( int i = 0; i < n; ++i )
	{
		cin >> id >> d >> c;
		if( d >= h && c >= h ) rank1.push_back( Stu(id, d, c) );
		else if( d >= h && c < h && c >= l ) rank2.push_back( Stu(id, d, c) );
		else if( d >= l && c >= l) 
		{
			if( d >= c ) rank3.push_back( Stu(id, d, c) );
			else rank4.push_back( Stu(id, d, c) );
		}	
	}
	sort(rank1.begin(), rank1.end());	sort(rank2.begin(), rank2.end());
	sort(rank3.begin(), rank3.end());	sort(rank4.begin(), rank4.end());
	printf( "%d\n", rank1.size() + rank2.size() + rank3.size() + rank4.size() );
	for( int i = 0; i < rank1.size(); ++i ) printf("%08d %d %d\n", rank1[i].id, rank1[i].d, rank1[i].c);
	for( int i = 0; i < rank2.size(); ++i ) printf("%08d %d %d\n", rank2[i].id, rank2[i].d, rank2[i].c);
	for( int i = 0; i < rank3.size(); ++i ) printf("%08d %d %d\n", rank3[i].id, rank3[i].d, rank3[i].c);
	for( int i = 0; i < rank4.size(); ++i ) printf("%08d %d %d\n", rank4[i].id, rank4[i].d, rank4[i].c);
	return 0;
}