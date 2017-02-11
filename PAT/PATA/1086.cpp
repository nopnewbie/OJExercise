/*
	PAT(A): 1086. Tree Traversals Again (25)
	重建法
*/
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<fstream>
#include<stack>
#include<vector>

using namespace std ;

const string POP = "Pop" ;
const string PUSH = "Push" ;
const int maxn = 30 + 5 ;
int rchild[maxn], lchild[maxn] ;
int n ;
stack<int> node ;
vector<int> outcome ;

void postOrd( int r )
{
	if( r < 0 ) return ;
	postOrd( lchild[r] ) ;
	postOrd( rchild[r] ) ;
	outcome.push_back(r) ;
}

int main()
{
#define cin fin
	ifstream fin("F:\\input.txt") ;
	cin >> n ;
	string priorOp, thisOp ;
	int x, root, subRoot ;
	memset( lchild, -1, sizeof(lchild) ) ;
	memset( rchild, -1, sizeof(rchild) ) ;
	cin >> priorOp >> root ;
	node.push( root ) ;
	for( int i = 1; i < 2*n; ++i )
	{//重建二叉树
		cin >> thisOp ;
		if( thisOp == PUSH )
		{
			cin >> x ;
			if( priorOp == PUSH )	//左孩子
				lchild[ node.top() ] = x ;
			else 
				rchild[ subRoot ] = x ;
			node.push( x ) ;	priorOp = thisOp ;
		}
		else
		{
			subRoot = node.top() ; node.pop() ;
			priorOp = thisOp ;
		}
	}
	postOrd( root ) ;
	cout << outcome[0] ;
	for( int i = 1; i < outcome.size() ; ++i )
		cout << ' ' << outcome[i] ;
	cout << endl ;
	return 0 ;
}