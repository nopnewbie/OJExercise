/*
	PAT(A)1054. The Dominant Color (20)
	Date: 2016年1月16日 13:38:35
*/
#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#define LOCAL 
using namespace std ;

struct node
{
	int cnt, index ;
	node(){}
	node( int c, int i ):cnt(c), index(i) {}
	bool operator < ( const node& a ) const
	{
		return cnt > a.cnt ;
	}
};
int main()
{
#ifdef LOCAL
#define cin fin
	//ifstream fin("F:\\input.txt");
	freopen("F:\\input.txt", "r", stdin) ;
#endif
	int M, N, x ;
	vector<node> ans;
	vector<int> a ;
	scanf("%d%d", &M, &N) ;
	for( int i = 0; i < M; ++i )
	{
		for( int j = 0; j < N; ++j )
		{
			scanf("%d", &x) ;	a.push_back(x);
		}
	}
	sort(a.begin(),a.end()) ;
	for( int i = 0; i < a.size(); ++i )
	{
		if( ans.empty() || ans.back().index != a[i] ) ans.push_back( node(1, a[i]) ) ;
		else ++ans.back().cnt ;
	}
	vector<char> dx(ans.size()) ;
	for( int i = 0; i < ans.size(); ++i ) dx[i] = i ;
	sort( ans.begin(), ans.end() ) ;
//	sort( dx.begin(), dx.end(), [ans](const char& a, const char& b)->bool{ return ans[a].cnt > ans[b].cnt ;} ) ;
//	printf("%d\n", ans[ dx[0] ]. index) ;
	printf("%d\n", ans[0]. index) ;
	return 0 ;
}