/*
	牛客网PAT
		Build A Binary Search Tree(30)
		Date: 15.12.28
*/

#include<iostream>
#include<cstdlib>
#include<vector>
#include<queue>
#include<algorithm>
#include<fstream>

using namespace std ;

const int maxn = 100 + 10 ;

int lchild[maxn], rchild[maxn], data[maxn] ;
int N, index ;
vector<int> num ;

void Fill( int root )
{
	if( root < 0 )	return ;
	Fill( lchild[root] ) ;
	data[root] = num[index++] ;
	Fill( rchild[root] ) ;
	return ;
}
int main()
{
#define cin fin
	ifstream fin("F:\\Input.txt") ;
	cin >> N ;
	for( int i = 0; i < maxn; ++i ) lchild[i] = rchild[i] = data[i] = -1 ;
	for( int i = 0; i < N; ++i )
	{
		int r, l ;
		cin >> l >> r ;
		lchild[i] = l;
		rchild[i] = r ;
	}
	num.resize(N);
	for( int i = 0; i < N; ++i ) cin >> num[i] ;
	sort(num.begin(), num.end()) ;
	index = 0;
	Fill(0) ;
	//层序遍历
	queue<int> q ;
	vector<int> ans ;
	q.push(0) ;
	while( !q.empty() )
	{
		int u = q.front() ; q.pop() ;
		ans.push_back( data[u] ) ;
		if( lchild[u] > 0 ) q.push( lchild[u] ) ;
		if( rchild[u] > 0 ) q.push( rchild[u] ) ;
	}
	cout << ans[0] ;
	for( int i = 1; i < ans.size(); ++i ) cout << ' ' << ans[i] ;
	cout << endl ;
	return 0 ;
}






