/*
	PAT(A): 1086. Tree Traversals Again (25)
	非重建法
*/
#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<fstream>

using namespace std ;

const string PUSH = "Push" ;
const string POP = "Pop" ;
int n ;
stack<int> node, subRoot ;
vector<int> outcome ;

int main()
{
#define cin fin
	ifstream fin( "F:\\input.txt" ) ;
	string priorOp, thisOp ;
	int x, root ;
	cin >> n ;
	cin >> priorOp >> root ;
	for( int i = 1; i < 2*n; ++i )
	{
		cin >> thisOp ;
		if( priorOp == PUSH )	
		{	
			if( thisOp == PUSH )	//连续的push 表示当前节点为前一节点的左孩子
			{
				cin >> x ; node.push( x ) ; outcome.push_back( x ) ;
			}
			if( thisOp == POP )	//push+pop 表示前一节点无左孩子
			{
				subRoot.push( node.top() ) ;
				node.pop() ;
			}
		}
	}
	return 0 ;
}