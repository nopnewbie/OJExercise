/*
	PAT(A):	1064. Complete Binary Search Tree (30)
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

using namespace std ;

const int maxn = 1000+ 5 ; 
int N ;
int node[maxn], tree[maxn] ;
int cnt ;

void Fill( int root )
{
	if( root > N-1 ) return ;
	int lc = 2*root + 1 ;
	int rc = 2*root + 2 ;
	Fill( lc ) ;
	tree[ root ] = node[cnt++] ;
	Fill( rc ) ;
	return ;
}

int main()
{
#define cin fin
	ifstream fin( "F:\\input.txt" ) ;
	cin >> N ;
	for( int i = 0; i < N; ++i ) cin >> node[i] ;
	sort( node, node+N ) ;
	Fill( 0 ) ;	cnt = 0 ;
	cout << tree[0] ;
	for( int i = 1; i < N; ++i ) cout << ' ' << tree[i] ;
	cout << endl ;
	return 0 ;
}

/*
	���������������¼�������:
		1. ��������������������������
		2. ��ȫ�����������������ʾ, ����������Ϊ�����˳�����.
	����ֻ��Ҫ������������������к�, ������ݹ�����ķ�ʽ�������������鼴��
*/