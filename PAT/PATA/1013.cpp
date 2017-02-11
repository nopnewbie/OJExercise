/*
	PAT(A): 1013.Battle Over Cities (25)
*/
#include<iostream>
#include<cstring>
#include<fstream>

#define cin fin

using namespace std ;

int N, M, K ;
const int maxn = 1000 + 5 ;
struct Way
{
	int a, b;
} way[maxn*maxn] ;
int set[maxn] ;

int Find( int x )
{
	return  set[x] < 0 ? x : set[x] = Find(set[x]) ;
}

bool Union( int x, int y )
{
	int r1 = Find(x) ;
	int r2 = Find(y) ;
	if(r1 == r2) return false ;
	if(set[r1] < set[r2])
	{
		set[r1] += set[r2] ;
		set[r2] = r1 ;
	}
	else
	{
		set[r2] += set[r1] ;
		set[r1] = r2 ;
	}
	return true ;
}

int main()
{
	ifstream fin("F:\\input.txt") ;
	cin >> N >> M >> K ;
	for( int i = 0; i < M; ++i )	cin >> way[i].a >> way[i].b ;
	while( K-- )
	{
		memset(set, -1, sizeof(set)) ;
		int c, cnt = 0 ;
		cin >> c ;
		for( int i = 0 ; i < M; ++i )
		{
			if( way[i].a == c || way[i].b == c ) continue ;
			Union(way[i].a, way[i].b) ;
		}
		for( int i = 1; i <= N; ++i )
		{
			if( i == c ) continue ;
			if( set[i] < 0 ) ++cnt ;
		}
		cout << (cnt? (cnt-1) : 0 )  << endl ;
	}
	return 0 ;
}