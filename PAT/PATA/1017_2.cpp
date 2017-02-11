#include<iostream>
#include<algorithm>
#include<vector>
#include<fstream>

using namespace std ;

const int startTime = 8*3600 ;
const int endTime = 17*3600 ;
struct Customer
{
	int arrTime, proTime ;
	int waitTime ;
	Customer(){}
	Customer( int a, int p ): arrTime(a), proTime(p), waitTime(0) {}
} ;

int main()
{
	freopen("F:\\input.txt", "r", stdin) ;
	int N, K ;
	scanf("%d %d", &N, &K ) ;
	vector<int> windows(K, startTime) ;	//���崰��,����ʼ�������ڿ��Կ�ʼ���������ʱ��
	vector<Customer> cust ;
	int hh, mm, ss, p ;
	int i, j ;
	for( i = 0; i < N; ++i )
	{
		scanf("%d:%d:%d %d", &hh, &mm, &ss, &p) ;
		int atm = hh*3600 + mm*60 + ss ;
		if(atm > endTime) continue ;
		cust.push_back( Customer(atm, p < 60 ? p*60 : 3600 ) ) ;
	}
	sort( cust.begin(), cust.end(), [](const Customer &a, const Customer &b){ return a.arrTime < b.arrTime ; } ) ;
	int minWin = endTime ;
	for( i = 0; i < cust.size() && i < K; ++i )
	{
		if( windows[i] > cust[i].arrTime ) 
		{
			cust[i].waitTime = windows[i] - cust[i].arrTime ;
			windows[i] += cust[i].proTime ;
		}
		else
		{//���ڿ�����һ��ʱ��
			windows[i] = cust[i].arrTime + cust[i].proTime ;
		}
		if( windows[i] < minWin )
		{
			minWin = windows[i];	j = i ;	//ָ�����Ĵ���
		}
	}
	while( i < cust.size() )
	{
		if( windows[j] > cust[i].arrTime ) 
		{
			cust[i].waitTime = windows[j] - cust[i].arrTime ;
			windows[j] += cust[i].proTime ;
		}
		else
		{//���ڿ�����һ��ʱ��
			windows[j] = cust[i].arrTime + cust[i].proTime ;
		}
		minWin = windows[0] ;	//����Ѱ��������Է���Ĵ���
		j = 0 ;
		for(  int k = 0; k < K; ++k )
		{
			if( windows[k] < minWin )
			{
				minWin = windows[k] ;
				j = k ;
			}
		}
		++i ;
	}
	float total = 0; 
	for( i = 0; i < cust.size() ; ++i ) total += cust[i].waitTime ;
	printf("%.1lf\n", total/60/cust.size()) ;
	return 0 ;
}