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
int ShortestLine ;	//��¼��̶���
int NextOne ;	//���������һ�˵ı��

int main()
{
	ifstream fin("F:\\input.txt") ;
	cin >> N >> M >> K >> Q ;
	vector<int> proTime(K,-1) ;	
	vector<int> finTime(K, -1);	//�û����ʱ�䣬min
	myQ.resize(N) ;
	ShortestLine = 0 ;
	NextOne = N*M < K ? N*M : K ;	//��ʼ����һ���˵ı��,��0��ʼ���
	for( int i = 0 ; i < K; ++i )
	{
		cin >> proTime[i] ;//������û���ʱ
	}
	for( int i = 0, n =0 ; i < M && n < K; ++i )
	{
		for( int j = 0; j < N && n < K; ++j, ++n )	//���û����ܺ���,�Ų���
		{
			myQ[j].push( n ) ;	
		}
	}
	for( int i = 1 ;  ; ++i )	//ģ���Ŷ�
	{
		bool isDone = true ;	//�°��־
		for( int j = 0; j < N; ++j )
		{
			if( myQ[j].empty() ) continue ;
			isDone = false ;
			if( --proTime[ myQ[j].front() ] == 0 ) // ����ǿղŽ��в���
			{
				finTime[ myQ[j].front() ]  = i ;
				myQ[j].pop() ;
				if( i >= ShopHours )	// ���������ǲ����ڼ����Ŷ���,���������п�����Ȼ�ڷ���
				{	//�°�ʱ�䵽, �����в��ٷ���
					while( !myQ[j].empty() ) myQ[j].pop();	//��ն���
					continue ;
				}
				ShortestLine = myQ[ShortestLine].size() < myQ[j].size() ? ShortestLine : j ;	//��¼��ǰ��̶���
				if( NextOne < K && i < ShopHours)	
				{
					myQ[ShortestLine].push( NextOne++ ) ;	//��һ�������
				}
			}
		}
		if(isDone) break ;
	}
	//�Ŷ����, ��������
	for( int i = 0, n; i < Q; ++i )
	{
		cin >> n ;
		if( finTime[n-1] < 0 )	puts("Sorry") ;
		else	printf("%02d:%02d\n", 8+finTime[n-1]/60, finTime[n-1]%60) ;
	}
	return 0 ; 
}
