/*
	牛客网PAT
		Tree Traversals Again (25)
		Date: 2016年1月7日 16:23:39
*/
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<fstream>
#include<cstring>

#define LOCAL

using namespace std ; 

//vector<int> rchild, lchild ;
int rchild[35], lchild[35] ;
vector<int> ans ;
void postOrd( int root )
{
	if( root <= 0 ) return ;
	postOrd( lchild[ root ] ) ;
	postOrd( rchild[ root ] ) ;
	ans.push_back( root ) ;
}
int main()
{
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt") ;
#endif
	int n, node, preNode, root ;
	stack<int> s ;
	string preOp, thisOp ;
	cin >> n; 
//	rchild.resize(n+1, -1) ; lchild.resize(n+1, -1) ;
	memset( lchild, -1, sizeof(lchild) ) ;	memset( rchild, -1, sizeof( rchild ) ) ;
	n <<= 1 ;
	cin >> preOp >> root ;	s.push(root) ;
	preNode = root ;
	for( int i = 1; i < n; ++i )
	{
		cin >> thisOp ;
		if( thisOp == "Push" ) 
		{
			cin >> node ;
			if( preOp == "Pop" ) rchild[ preNode ] = node ;
			if( preOp == "Push" ) lchild[ preNode ] = node ;
			s.push( node ) ; 
			preNode = node ;
		}
		else
		{
			preNode = s.top() ; s.pop() ;
		}
		preOp = thisOp ;
	}
	postOrd( root ) ;
	if( !ans.empty() )
	{
		cout << ans[0] ;
		for( int i = 1; i < ans.size(); ++i ) cout << ' ' << ans[i] ;
		cout << endl ;
	}
	return 0 ;
}