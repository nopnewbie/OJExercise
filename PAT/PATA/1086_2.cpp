/*
	PAT(A): 1086. Tree Traversals Again (25)
	���ؽ���
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
			if( thisOp == PUSH )	//������push ��ʾ��ǰ�ڵ�Ϊǰһ�ڵ������
			{
				cin >> x ; node.push( x ) ; outcome.push_back( x ) ;
			}
			if( thisOp == POP )	//push+pop ��ʾǰһ�ڵ�������
			{
				subRoot.push( node.top() ) ;
				node.pop() ;
			}
		}
	}
	return 0 ;
}