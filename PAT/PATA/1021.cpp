/*
	PAT(A): 1021. Deepest Root (25)
	ע����Ŀ����n-1����, Ҫô��һ���������нڵ����,Ҫô������ͨͼ,���Կ����ò��鼯
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<fstream>
#include<cstring>

using namespace std ;

const int maxn = 10e4 + 5; 
int N ;
int a[maxn] ;	//�ڵ����״̬��, 0 δ����, 1,���ʹ��ýڵ㼫������, -1���ڷ���
int deepth[maxn] ;
struct Edge
{
	int from, to ;
	Edge() {}
	Edge( int f, int t ): from(f), to(t) {}
} ;
vector<Edge> edges ;
vector<int>G[maxn] ;		//����ͼ
int v[maxn] ;

void InitSet()
{
	memset(v, -1, sizeof(v)) ;
	return ;
}

int Find( int x )
{
	return v[x] < 0 ? x : v[x] = Find( v[x] ) ;
}

bool Union( int x, int y )
{
	int r1 = Find(x) ;
	int r2 = Find(y) ;
	if ( r1 == r2 ) return false ;
	if( v[r1] <= v[r2] )
	{
		v[r1] += v[r2] ;
		v[r2] = r1 ;
	}
	else if( v[r2] < v[r1] )
	{
		v[r2] += v[r1] ;
		v[r1] = r2 ;
	}
	return true ;
}

void bfs( int s )
{
	memset( a, 0, sizeof(a) ) ;
	queue<int> q ;
	vector<int> dp(N+1, 0) ;
	q.push(s) ;	a[s] = 1 ;
	while( !q.empty() )
	{
		int u = q.front() ; q.pop() ;
		for( int i = 0; i < G[u].size(); ++i )
		{
			Edge e = edges[ G[u][i] ] ;
			if( a[e.to] ) continue ;
			q.push(e.to) ; a[e.to] = 1 ;
			dp[e.to] = dp[u] + 1 ;
			deepth[s] = deepth[s] > dp[e.to] ? deepth[s] : dp[e.to] ;	//����������
		}
	}

}

bool cmp( const int &a, const int &b )
{
	if( deepth[a] != deepth[b] ) return deepth[a] > deepth[b] ;
	else	return a < b ;
}

int main()
{
#define cin fin
	ifstream fin("F:\\input.txt") ;
	int  from, to ;
	memset( a, 0, sizeof(a) ) ;
	cin >> N ;
	for( int i = 0; i < N-1; ++i )
	{
		cin >> from >> to ;
		edges.push_back( Edge( from, to ) ) ;
		G[from].push_back( edges.size()-1 ) ;
		edges.push_back( Edge( to, from ) ) ;	//����ͼ
		G[to].push_back( edges.size()-1 ) ;
	}
	int loopCount = 0 ;
	InitSet() ;
	for( int i = 0; i < edges.size() ; i+=2 )	
		if( !Union(edges[i].from, edges[i].to) )	++loopCount ;
	//for( int i = 1; i <= N; ++i ) if( v[i] < 0 ) ++loopCount ;
	if( loopCount )	//�л�
		cout << "Error: "<< loopCount + 1 << " components" << endl  ;
	else
	{
		for( int i = 1; i <= N; ++i ) bfs(i) ;
		vector<int> outPut(N+1) ;
		for( int i = 1; i <= N; ++i ) outPut[i] = i ;
		sort( outPut.begin()+1, outPut.end(), cmp ) ;
		for( int i = 1; i <= N ; ++i )
		{
			if( deepth[ outPut[i] ] != deepth[ outPut[1] ] ) break ;
			cout << outPut[i] << endl ;
		}
	}
	return 0 ;
}