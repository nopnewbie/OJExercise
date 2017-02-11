/*
	PAT(A): 1043.Is It a Binary Search Tree (25)
*/
#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<fstream>

using namespace std ;

#define cin fin

const int MAXN = 1000 + 5 ;
int n ;
int preIn[MAXN] ;
vector<int> pre1, pre2 ;
struct Node
{
	int data ;
	int lc, rc ;
	Node(int d): data(d), lc(-1), rc(-1)
	{}
	Node(){ lc = rc = -1 ; }
} ;
vector<Node> tree ;
vector<Node> tree2 ;

void insert( int root, int key )
{
	if( tree[root].data > key) 
	{//insert left
		if(tree[root].lc == -1)
		{
			tree.push_back(Node(key)) ;
			tree[root].lc = tree.size() - 1 ;
			return ;
		}
		insert(tree[root].lc, key) ;
	}
	else
	{
		if(tree[root].rc == -1)
		{
			tree.push_back(Node(key)) ;
			tree[root].rc = tree.size() - 1 ;
			return ;
		}
		insert(tree[root].rc, key) ;
	}
}

void insert2( int root, int key )
{//¹¹½¨¾µÏñBST
	if( tree2[root].data <= key) 
	{//insert left
		if(tree2[root].lc == -1)
		{
			tree2.push_back(Node(key)) ;
			tree2[root].lc = tree2.size() - 1 ;
			return ;
		}
		insert2(tree2[root].lc, key) ;
	}
	else
	{
		if(tree2[root].rc == -1)
		{
			tree2.push_back(Node(key)) ;
			tree2[root].rc = tree2.size() - 1 ;
			return ;
		}
		insert2(tree2[root].rc, key) ;
	}
}

void preOrd( int root, vector<Node>& t, vector<int>& pre  )
{
	int lc = t[root].lc, rc = t[root].rc ;
	if(lc == -1 && rc == -1)
	{
		pre.push_back(tree[root].data) ;
		return ;
	}
	pre.push_back(tree[root].data) ;
	if( lc > -1 ) preOrd(lc, t, pre) ;
	if( rc > -1 ) preOrd(rc, t, pre) ;
}

vector<int> postOrd ;
void postTraverse(int root, vector<Node>& t)
{
	int lc = t[root].lc, rc = t[root].rc ;
	if( lc == -1 && rc == -1 )
	{
		postOrd.push_back(t[root].data) ;
		return ;
	}
	if(lc > -1) postTraverse(lc, t);
	if(rc > -1) postTraverse(rc, t) ;
	postOrd.push_back(t[root].data) ;
}

bool cmp( vector<int>& p )
{
	for( int i = 0; i < n; ++i )
	{
		if( preIn[i] != p[i] ) return false ;
	}
	return true ;
}

int main()
{
	ifstream fin("F:\\input.txt") ;
	while(cin >> n )
	{
		tree.clear() ; tree2.clear() ;
		pre1.clear() ; pre2.clear() ;
		postOrd.clear() ;
		for(int i = 0; i < n; ++i) cin >> preIn[i] ;
		tree.resize(1) ;	tree2.resize(1) ;
		tree[0].data = tree2[0].data = preIn[0] ;
		for(int i = 1 ; i < n; ++i)
		{
			insert(0, preIn[i]) ;		insert2(0, preIn[i]) ;
		}
		preOrd(0, tree, pre1) ;
		preOrd(0, tree2, pre2) ;
		if( cmp(pre1) )
		{
			cout << "YES\n" ;
			postTraverse( 0, tree ) ;
			cout << postOrd[0] ;
			for(int i = 1; i < postOrd.size(); ++i) cout << ' ' << postOrd[i] ;
			cout << "\n" ;
		}
		else if( cmp(pre2) )
		{
			cout << "YES\n" ;
			postTraverse( 0, tree2 ) ;
			cout << postOrd[0] ;
			for(int i = 1; i < postOrd.size(); ++i) cout << ' ' << postOrd[i] ;
			cout << "\n" ;
		}
		else cout << "NO\n" ;
	}
	return  0;
}