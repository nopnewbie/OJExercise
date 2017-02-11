/*
	PAT(A): 1004. Counting Leaves (30)
	图, bfs
*/

#include<iostream>
#include<fstream>
#include<queue>
#include<vector>
#include<cstring>

#define cin fin

using namespace std ;

const int MAXN = 100 + 5 ;
bool vis[MAXN] ;
int leaf[MAXN] ;

vector<int> G[MAXN] ;

struct Lv
{
	int u, lv ;
	Lv(): u(0), lv(0)
	{}
	Lv( int _u, int _lv ) : u(_u), lv(_lv)
	{}
} ;

int bfs(int s)
{
	int maxLv = 0 ;
	memset(vis, false, sizeof(vis)) ;
	queue<Lv> q ;
	q.push( Lv(s,0) ) ;
	while( !q.empty() )
	{
		int u = q.front().u ;
		int lv = q.front().lv ; q.pop() ;
		if(vis[u]) continue ; vis[u] = true ;
		if(!G[u].size()) ++leaf[lv] ;
		else
		{
			for( int i = 0; i < G[u].size(); ++i )	q.push(Lv(G[u][i], lv+1 ) );
		}
		maxLv = maxLv > lv ? maxLv : lv ;
	}
	return maxLv ;
}

int main()
{
	ifstream fin("F:\\input.txt") ;
	int n, m, p, ch, k ;
	cin >> n >> m ;
	for( int i = 0; i < m; ++i )
	{
		cin >> p >> k ;
		for( int j = 0; j < k; ++j )
		{
			cin >> ch ;
			G[p].push_back(ch) ;
		}
	}
	int h = bfs(1) ;
	cout << leaf[0] ;
	for( int i = 1; i <= h; ++i ) cout << ' ' << leaf[i] ;
	cout << endl ;
	return 0 ;
}



