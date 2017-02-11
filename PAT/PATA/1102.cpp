/*
	PAT(A): 1102. Invert a Binary Tree (25)
*/
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<string>
#include<fstream>

using namespace std ;

int N ;
int lc[13], rc[13], fa[13] ;
vector<int> ians, lans ;

void bfs( int rt )
{
	queue<int> q ;
	q.push(rt) ;
	while( !q.empty() )
	{
		int x = q.front() ; q.pop() ;
		if( lc[x] >= 0 ) q.push(lc[x]) ;
		if( rc[x] >= 0 ) q.push(rc[x]) ;
		lans.push_back(x) ;
	}
	return ;
}

void dfs( int rt )
{
	if( rt < 0 ) return ;
	dfs( lc[rt] ) ;
	ians.push_back(rt) ;
	dfs( rc[rt] ) ;
	return ;
}

int main()
{
#define cin fin
	ifstream fin("F:\\input.txt") ;
	for( int i = 0; i < 13; ++i ) lc[i] = rc[i] = fa[i] = -1 ;
	cin >> N ;
	string node ;
	for( int i = 0; i < N; ++i )
	{
		cin >> node ;
		if( node[0] >= '0' && node[0] <= '9'  )
		{
			rc[i] = node[0] - '0' ;
			fa[ node[0] - '0' ] = i ;
		}
		cin >> node ;
		if( node[0] >= '0' && node[0] <= '9'  )
		{
			lc[i] = node[0] - '0' ;
			fa[ node[0] - '0' ] = i ;
		}
	}
	int root ;
	for( int i = 0; i < N; ++i ) 
		if( fa[i] < 0 )
		{
			root = i ; break ;
		}
	dfs(root) ; bfs(root) ;
	cout << lans[0];
	for( int i = 1; i < lans.size(); ++i ) cout << ' ' << lans[i] ;
	cout << endl ;
	cout << ians[0];
	for( int i = 1; i < ians.size(); ++i ) cout << ' ' << ians[i] ;
	cout << endl ;
	return 0 ;
}
