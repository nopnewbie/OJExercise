/*
	PAT(A)1017. Queueing at Bank (25)
	测试用例:
6 1
11:30:39 11
21:09:34 27
04:31:39 47
16:26:24 27
21:29:55 7
18:27:05 58

对应输出应该为:
69.5
*/
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstdlib>


using namespace std ;

struct Customer
{
	int arrTime, proTime ;	//到达时间,与处理时间
	Customer(){}
	Customer( int a, int p ): arrTime(a), proTime(p) {}
} ;
struct queInfo
{
	int num , proTime ;
	queInfo(){}
	queInfo( int n, int p ): num(n), proTime(p) {}
} ;
vector< queue<queInfo> > wnds ;
vector<Customer> que ;
int N, K ;
const int startTime = 8*3600 ;
const int shopHours = 17*3600 ;

int main()
{
	freopen("F:\\input.txt", "r", stdin) ;
	int totalTime = 0 ;
	int hh, mm, ss, p ;
	int i, j, validN = 0 ;	// validN 为有效人数
	scanf("%d %d", &N, &K) ;
	wnds.resize(K) ;
	for( i = 0; i < N; ++i )
	{
		scanf("%d:%d:%d %d", &hh, &mm, &ss, &p) ;
		int atm = hh*3600+mm*60+ss ;
		if( atm <= shopHours )	que.push_back( Customer(atm, p > 60 ? 3600 : p*60 ) ) ;
	};
	validN = que.size() ;
	sort( que.begin(), que.end(), 
		[]( const Customer &c1, const Customer &c2  ){ return c1.arrTime <  c2.arrTime ; } ) ;
	//模拟排队
	for( i = 0; i < K && i < validN; ++i )
	{
		wnds[i].push( queInfo(i, que[i].proTime ) ) ;
	}
	int nextOne = i ;
	for( i = startTime+1; ; ++i )
	{
		bool allEmpty = true ;
		for( j = 0; j < K; ++j )
		{
			if( wnds[j].empty() )	continue ;
			allEmpty = false ;
			if( i >=que[ wnds[j].front().num ].arrTime && --wnds[j].front().proTime == 0 )
			{
				totalTime += i - que[ wnds[j].front().num ].arrTime  - que[ wnds[j].front().num ].proTime ;
				wnds[j].pop() ;
				if( nextOne < validN )
				{
					wnds[j].push( queInfo( nextOne , que[ nextOne ].proTime ) ) ;
					++nextOne ;
				}
			}
		}
		if( allEmpty ) break ;
	}
	printf("%.1lf\n", totalTime/60.0/validN) ;
	return 0 ;
}