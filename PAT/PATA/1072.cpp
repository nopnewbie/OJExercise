/*
	1072. Gas Station (30)
	小结:
	2015年9月2日 15:39:24
		题目很繁琐, 关键在于理解题意,建模。
		其实就是求单源最短路径 Dijikstra 可解决
		不过不知哪里出错, 最后一个case 过不了
	10 5 255 15
1 1 10
1 2 10
1 3 10
1 4 10
1 5 10
1 6 10
1 7 10
1 8 10
1 9 10
1 10 10
1 G1 10
1 G2 10
1 G3 10
1 G4 10
1 G5 10
2 1 10
2 2 10
2 3 10
2 4 10
2 5 10
2 6 10
2 7 10
2 8 10
2 9 10
2 10 10
2 G1 10
2 G2 10
2 G3 10
2 G4 10
2 G5 10
3 1 10
3 2 10
3 3 10
3 4 10
3 5 10
3 6 10
3 7 10
3 8 10
3 9 10
3 10 10
3 G1 10
3 G2 10
3 G3 10
3 G4 10
3 G5 10
4 1 10
4 2 10
4 3 10
4 4 10
4 5 10
4 6 10
4 7 10
4 8 10
4 9 10
4 10 10
4 G1 10
4 G2 10
4 G3 10
4 G4 10
4 G5 10
5 1 10
5 2 10
5 3 10
5 4 10
5 5 10
5 6 10
5 7 10
5 8 10
5 9 10
5 10 10
5 G1 10
5 G2 10
5 G3 10
5 G4 10
5 G5 10
6 1 10
6 2 10
6 3 10
6 4 10
6 5 10
6 6 10
6 7 10
6 8 10
6 9 10
6 10 10
6 G1 10
6 G2 10
6 G3 10
6 G4 10
6 G5 10
7 1 10
7 2 10
7 3 10
7 4 10
7 5 10
7 6 10
7 7 10
7 8 10
7 9 10
7 10 10
7 G1 10
7 G2 10
7 G3 10
7 G4 10
7 G5 10
8 1 10
8 2 10
8 3 10
8 4 10
8 5 10
8 6 10
8 7 10
8 8 10
8 9 10
8 10 10
8 G1 10
8 G2 10
8 G3 10
8 G4 10
8 G5 10
9 1 10
9 2 10
9 3 10
9 4 10
9 5 10
9 6 10
9 7 10
9 8 10
9 9 10
9 10 10
9 G1 10
9 G2 10
9 G3 10
9 G4 10
9 G5 10
10 1 10
10 2 10
10 3 10
10 4 10
10 5 10
10 6 10
10 7 10
10 8 10
10 9 10
10 10 10
10 G1 10
10 G2 10
10 G3 10
10 G4 10
10 G5 10
G1 1 10
G1 2 10
G1 3 10
G1 4 10
G1 5 10
G1 6 10
G1 7 10
G1 8 10
G1 9 10
G1 10 10
G1 G1 10
G1 G2 10
G1 G3 10
G1 G4 10
G1 G5 10
G2 1 10
G2 2 10
G2 3 10
G2 4 10
G2 5 10
G2 6 10
G2 7 10
G2 8 10
G2 9 10
G2 10 10
G2 G1 10
G2 G2 10
G2 G3 10
G2 G4 10
G2 G5 10
G3 1 10
G3 2 10
G3 3 10
G3 4 10
G3 5 10
G3 6 10
G3 7 10
G3 8 10
G3 9 10
G3 10 10
G3 G1 10
G3 G2 10
G3 G3 10
G3 G4 10
G3 G5 10
G4 1 10
G4 2 10
G4 3 10
G4 4 10
G4 5 10
G4 6 10
G4 7 10
G4 8 10
G4 9 10
G4 10 10
G4 G1 10
G4 G2 10
G4 G3 10
G4 G4 10
G4 G5 10
G5 1 10
G5 2 10
G5 3 10
G5 4 10
G5 5 10
G5 6 10
G5 7 10
G5 8 10
G5 9 10
G5 10 10
G5 G1 10
G5 G2 10
G5 G3 10
G5 G4 10
G5 G5 10

对应输出应该为:
G1
10.0 10.0
*/
#include<iostream>
#include<fstream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdlib>

using namespace std ;

struct Edge
{
	int from, to ;
	long long dist ;
	Edge(){}
	Edge( int f, int t, long long dst ): from(f), to(t), dist(dst)
	{}
} ;
struct HpNode
{
	int u, d ;
	HpNode(){}
	HpNode( int _u, int _d ) : u(_u), d(_d)
	{}
	bool operator < ( const HpNode &x ) const
	{
		return d > x.d ;
	}
} ;
struct Station
{
	int num ;
	double avrDst, minDst; ;
	Station(){}
	Station( int n, double m, double avr ): num( n ), minDst(m), avrDst(avr)
	{}
} ;
const int MAXN = 1000 +10 + 5 ;
const int INF	=	1 << 30 ;
int d[MAXN] ;
bool visit[MAXN] ;
int path[MAXN] ;
vector<Edge> edges ;
vector<int> G[MAXN] ;
int N, M, K, Ds ;

void Dijikstra( int s )
{
	priority_queue<HpNode> Q ;
	memset( visit, false, sizeof(visit) ) ;
	memset( path, -1, sizeof(path) ) ;
	for( int i = 1; i <= N+M; ++i ) d[i] = INF ;
	d[s] = 0 ; 
	Q.push( HpNode( s, d[s] ) ) ;
	while( !Q.empty() )
	{	 
		int u = Q.top().u, dst = Q.top().d ;	Q.pop() ;
		if( visit[u] ) continue ;
		visit[u] = true ;
		for( int i = 0; i < G[u].size(); ++i )
		{
			Edge x = edges[ G[u][i] ] ;
			if( d[u] < INF && x.dist < INF && d[x.to] > d[u] + x.dist )
			{
				d[x.to] = d[u] + x.dist ;
				path[x.to] = u ;
				Q.push( HpNode(x.to, d[x.to]) ) ;
			}
		}
	}
}

int main()
{
	freopen("F:\\input.txt", "r", stdin) ;
	scanf("%d %d %d %d", &N, &M, &K, &Ds) ;
	char from[3], to[3] ;
	int dst ;
	for( int i = 0; i < K; ++i )
	{
		int u, v ;
		scanf("%s %s %d", from, to, &dst ) ;
		if( from[0] != 'G' )	u = from[0] - '0' ;	//是民居
		else u = from[1] - '0' + N ;		//是煤气站
		if( to[0] != 'G' )	v = to[0] - '0' ;
		else v = to[1] - '0' + N ;
		//添加边,注意是无向图
		edges.push_back( Edge( u, v, dst ) ) ;
		G[u].push_back( edges.size()-1 ) ;

		edges.push_back( Edge( v, u, dst ) ) ;
		G[v].push_back( edges.size()-1 ) ;
	}
	vector<Station> ans ;
	for( int i = N+1; i <= N+M; ++i )
	{
		double totalDst = 0 ;
		int minDst = INF ;
		bool flag = true ;
		Dijikstra( i ) ;
		for( int j = 1; j <= N; ++j )
		{
			if( d[j] > Ds) 
			{//该站不符合要求
				flag = false ;	break ;
			}
			minDst = minDst < d[j] ? minDst : d[j] ;
			totalDst += d[j] ;
		}
		if( flag )	ans.push_back( Station( i-N, minDst, totalDst/N  ) ) ;
	}
	if( !ans.empty() )
	{
		sort( ans.begin(), ans.end(), []( const Station& a, const Station& b )->bool
		{//按要求排序
			if( a.minDst != b.minDst ) return a.minDst > b.minDst ;
			else if( a.avrDst != b.avrDst ) return a.avrDst < b.avrDst ;
			else return a.num < b.num ;
		} ) ;
		printf( "G%d\n%.1lf %.1lf\n", ans[0].num, ans[0].minDst, ans[0].avrDst  ) ;
	}
	else printf("No Solution\n") ;
	return 0 ;
}
