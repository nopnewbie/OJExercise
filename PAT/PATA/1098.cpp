/*
	PAT(A): 1098. Insertion or Heap Sort (25)
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<fstream>

using namespace std ;

int N ; 

int main()
{
#define cin fin 
	ifstream fin( "F:\\input.txt" ) ;
	cin >> N ;
	int i, j ;
	vector<int> seq1(N), seq2(N) ;
	for( i = 0; i < N; ++i )		cin >> seq1[i] ;	//��ԭʼ����
	for( i = 0; i < N; ++i )		cin >> seq2[i] ;	//��������������
	// isInsertation
	bool isInsert = true ;
	for( i = 1; i < N; ++i )
	{
		if( seq2[ i-1 ] < seq2[i] )	continue ;
		break ;
	}	//��ʱ, iӦ��ָ���һ������Ԫ��
	for( j = i; j < N; ++j )
	{
		if( seq2[ j ] == seq1[j] ) continue ;
		isInsert = false ;		
		break ;
	}
	if( isInsert )
	{//�ǲ���, ������һ�ֵ���
		int tmp = seq2[i], k ;
		for( k = i; k > 0; --k )
		{
			if( tmp < seq2[k-1] ) seq2[k] = seq2[k-1] ;
			else break ;
		}// ��ʱ, kӦ��ָ��
		seq2[k] = tmp ;
		//sort( seq2.begin(), seq2.begin()+i+1 ) ;	//�����ñ������������ϲ��ŵ���
		cout << "Insertion Sort" << endl ;
	}
	else
	{//����
		sort( seq1.begin(), seq1.end() ) ;
		for( i = N-1; i >= 0 && seq2[i] == seq1[i]; --i ) ;	//iָʾ�˵�ǰ�ѵı߽�, �Ѵ�СΪi+1
		int tmp = seq2[i] ;
		seq2[i] = seq2[0] ;
		seq2[0] = tmp ;	//�˺�ѵĹ�ģ��С1, ��С��Ϊi
		int child ;
		for( j = 0; 2*j+1 < i ; j = child )
		{
			child = j*2 + 1;	//ָ������
			if( child+1 < i && seq2[child+1] > seq2[child] ) ++child ;	 //ָ�����ĺ���
			if( seq2[child] > tmp ) seq2[j] = seq2[child] ;
			else break ;
		}
		seq2[j] = tmp ;
		cout << "Heap Sort" << endl ;
	}
	cout << seq2[0] ;
	for( i = 1; i < N; ++i ) cout << ' ' << seq2[i] ;
	cout << endl ;
	return 0;
}
