/*
	PAT(A): 1020.Tree Traversals
*/
#include<iostream>
#include<fstream>
#include<queue>

#define cin fin 

using namespace std ;

const int MAXN = 30 + 5 ;
int n ;
int inOrd[MAXN], postOrd[MAXN] ;
int lch[MAXN], rch[MAXN] ;

int build( int L1, int R1, int L2, int R2 )
{//inOrd[L1,...,R1]; postOrd[L2,...,R2]
	if(L1>R1) return 0 ;
	int root = postOrd[R2] ;
	int p = L1 ;		
	while(inOrd[p] != root) ++p ;
	int cnt = p-L1 ;	//左子树节点个数
	lch[root] = build(L1, p-1, L2, L2+cnt-1) ;
	rch[root] = build(p+1, R1, L2+cnt,R2-1) ;
	return root ;
}

void bfs(int s)
{
	cout << s ;
	queue<int> q ;
	if(lch[s]) q.push(lch[s]) ;
	if(rch[s]) q.push(rch[s]) ;
	while( !q.empty() )
	{
		int r = q.front() ; q.pop() ;
		if(lch[r]) q.push(lch[r]) ;
		if(rch[r]) q.push(rch[r]) ;
		cout << ' ' << r ;
	}
	cout << endl ;
}

int main()
{
	ifstream fin("F:\\input.txt") ;
	cin >> n ;
	for(int i  = 0; i < n; ++i) cin >> postOrd[i] ;
	for(int i  = 0; i < n; ++i) cin >> inOrd[i] ;
	build(0, n-1, 0, n-1) ;
	bfs(postOrd[n-1]) ;
	return 0 ;
}
