/*
	PAT(A):1099. Build A Binary Search Tree (30)
*/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<fstream>

using namespace std ;

const int maxn = 100 + 5 ;
int N; 
struct Node
{
	int data ;
	int left, right ;
} ;
Node tree[maxn] ;
int node[maxn] ;
int cnt ;

void Fill( int root )
{
	if( root < 0 ) return ;
	int lc = tree[root].left ;
	int rc = tree[root].right ;
	Fill( lc ) ;
	tree[ root ].data = node[ cnt++ ] ;
	Fill( rc ) ;
	return  ;
}

int main()
{
#define cin fin
	ifstream fin( "F:\\input.txt" ) ;
	cin >> N ;
	int lc, rc ;
	for( int i = 0; i < N; ++i )
	{
		cin >> lc >> rc ;
		tree[i].left = lc ;	tree[i].right = rc ;
	}
	for( int i = 0; i < N; ++i ) cin >> node[i] ;
	sort( node, node+N ) ;	
	cnt = 0 ;	Fill( 0 ) ;
	//≤„–Ú±È¿˙ ‰≥ˆ
	queue<Node> Q ;	Q.push( tree[0] ) ;
	vector<int> outcome ;
	while( !Q.empty() )
	{
		Node x = Q.front() ; Q.pop() ;
		outcome.push_back( x.data ) ;
		if( x.left > -1 ) Q.push( tree[ x.left ] ) ;
		if( x.right > -1 ) Q.push( tree[ x.right ] ) ;
	}
	cout << outcome[0] ;
	for( int i = 1; i < outcome.size(); ++i ) cout << ' ' << outcome[i] ;
	cout << endl ;
	return 0 ;
}
