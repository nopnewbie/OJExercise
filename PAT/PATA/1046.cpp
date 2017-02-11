/*
	PAT(A) 1046. Shortest Distance (20)
	hint:容易超时
	参考解决方案: http://blog.csdn.net/tiantangrenjian/article/details/13769011
*/
#include<iostream>
#include<fstream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std ;

const int MAXN = 10e5 + 5;
int C, N, M ;
int d[MAXN] ;
int main()
{
#define cin fin
	ifstream fin( "F:\\input.txt" ) ;
	cin >> N ;
	C = 0 ; d[1] = 0 ;
	for( int i = 1; i <= N; ++i ) 
	{
		int dst ;
		cin >> dst ;	C += dst ;	//计算总长
		d[i+1] = C ;	//d[i]表示当前节点与第一个节点的距离
	}
	cin >> M ;
	int u, v ;
	for( int i = 1; i <= M; ++i )
	{
		int dist ;
		cin >> u >> v ;
		dist = abs( d[u]-d[v] ) ;
		cout << (dist < C - dist ?  dist : C - dist) << endl ;
	}
	return 0 ; 
}