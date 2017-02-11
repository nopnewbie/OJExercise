/*
	PAT(A): 1003. Emergency (25)
*/
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>
#include<fstream>

#define fin cin

using namespace std ;

const int MAXN = 500 + 5 ;
const int INF = 1 << 20 ;
int n, m, c1, c2 ;
int dist[MAXN] ;
int ways[MAXN] ;
int team[MAXN] ;
int most[MAXN] ;
bool vis[MAXN] ;

struct Edge
{
	int from, to, dst ;
	Edge( int f, int t, int d ):
	from(f), to(t), dst(d)
	{}
	Edge()
	{from = to = dst = 0;}
} ;

vector<Edge> egs ;
vector<int> G[MAXN] ;

struct HeapNode
{
	int u, d ;
	HeapNode(int _u, int _d):
	u(_u), d(_d)
	{}
	bool operator< (const HeapNode& a) const
	{
		return d > a.d ;
	}
};


void Dijkstra( int s )
{
	memset(vis, false, sizeof(vis)) ;
	memset(most, 0, sizeof(most)) ;
	for(int i = 0; i < n; ++i) { dist[i] = INF ; ways[i] = 1 ; }
	most[s] = team[s]; dist[s] = 0 ;
	priority_queue<HeapNode> q ;
	q.push( HeapNode(s, dist[s]) ) ;
	while( !q.empty() )
	{
		int u = q.top().u ; q.pop() ;
		if(vis[u]) continue ;
		vis[u] = true ;
		for( int i = 0; i < G[u].size(); ++i )
		{
			Edge& e = egs[G[u][i]] ;
			if( dist[e.to] > dist[e.from] + e.dst )
			{
				dist[e.to] = dist[e.from] + e.dst ;
				ways[e.to] = ways[e.from] ; most[e.to] = most[e.from] + team[e.to] ;
				q.push( HeapNode(e.to, dist[e.to]) ) ;
			}
			else if(dist[e.to] == dist[e.from] + e.dst)
			{
				ways[e.to] += ways[e.from] ;
				most[e.to] = max(most[e.to], most[e.from] + team[e.to]) ;
			}
		}
	}
}

int main()
{
	ifstream fin("F:\\input.txt") ;
	int f, t, d ;
	cin >> n >> m >> c1 >> c2 ;
	for( int i = 0; i < n; ++i ) cin >> team[i] ;
	for( int i = 0 ; i < m; ++i )
	{
		cin >> f >> t >> d ;
		egs.push_back(Edge(f, t, d)) ;
		G[f].push_back(egs.size()-1) ;	//ÎÞÏòÍ¼
		
		egs.push_back(Edge(t, f, d)) ;
		G[t].push_back(egs.size()-1) ;
	}
	Dijkstra(c1) ;
	printf("%d %d\n", ways[c2], most[c2]) ;
	return 0 ;
}