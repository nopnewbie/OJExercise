/*
	PAT(A) 1014.Waiting in Line (30)
*/
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<fstream>

#define fin cin

using namespace std ;

const int ShopHours = 540 ;
int N, M, K, Q ;
vector< queue<int> > myQ ;
int ShortestLine ;	//记录最短队列
int NextOne ;	//队伍中最后一人的编号

int main()
{
	ifstream fin("F:\\input.txt") ;
	cin >> N >> M >> K >> Q ;
	vector<int> proTime(K,-1) ;	
	vector<int> finTime(K, -1);	//用户完成时间，min
	myQ.resize(N) ;
	ShortestLine = 0 ;
	NextOne = N*M < K ? N*M : K ;	//初始化下一个人的编号,从0开始编号
	for( int i = 0 ; i < K; ++i )
	{
		cin >> proTime[i] ;//读入各用户耗时
	}
	for( int i = 0, n =0 ; i < M && n < K; ++i )
	{
		for( int j = 0; j < N && n < K; ++j, ++n )	//若用户可能很少,排不满
		{
			myQ[j].push( n ) ;	
		}
	}
	for( int i = 1 ;  ; ++i )	//模拟排队
	{
		bool isDone = true ;	//下班标志
		for( int j = 0; j < N; ++j )
		{
			if( myQ[j].empty() ) continue ;
			isDone = false ;
			if( --proTime[ myQ[j].front() ] == 0 ) // 队伍非空才进行操作
			{
				finTime[ myQ[j].front() ]  = i ;
				myQ[j].pop() ;
				if( i >= ShopHours )	// 这条队列是不用在继续排队了,但其他队列可能仍然在服务
				{	//下班时间到, 本队列不再服务
					while( !myQ[j].empty() ) myQ[j].pop();	//清空队列
					continue ;
				}
				ShortestLine = myQ[ShortestLine].size() < myQ[j].size() ? ShortestLine : j ;	//记录当前最短队列
				if( NextOne < K && i < ShopHours)	
				{
					myQ[ShortestLine].push( NextOne++ ) ;	//下一个人入队
				}
			}
		}
		if(isDone) break ;
	}
	//排队完成, 处理请求
	for( int i = 0, n; i < Q; ++i )
	{
		cin >> n ;
		if( finTime[n-1] < 0 )	puts("Sorry") ;
		else	printf("%02d:%02d\n", 8+finTime[n-1]/60, finTime[n-1]%60) ;
	}
	return 0 ; 
}
