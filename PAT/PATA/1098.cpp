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
	for( i = 0; i < N; ++i )		cin >> seq1[i] ;	//读原始数据
	for( i = 0; i < N; ++i )		cin >> seq2[i] ;	//读部分排序数据
	// isInsertation
	bool isInsert = true ;
	for( i = 1; i < N; ++i )
	{
		if( seq2[ i-1 ] < seq2[i] )	continue ;
		break ;
	}	//此时, i应该指向第一个逆序元素
	for( j = i; j < N; ++j )
	{
		if( seq2[ j ] == seq1[j] ) continue ;
		isInsert = false ;		
		break ;
	}
	if( isInsert )
	{//是插排, 进行下一轮迭代
		int tmp = seq2[i], k ;
		for( k = i; k > 0; --k )
		{
			if( tmp < seq2[k-1] ) seq2[k] = seq2[k-1] ;
			else break ;
		}// 此时, k应该指向
		seq2[k] = tmp ;
		//sort( seq2.begin(), seq2.begin()+i+1 ) ;	//可以用本条语句代替以上插排迭代
		cout << "Insertion Sort" << endl ;
	}
	else
	{//堆排
		sort( seq1.begin(), seq1.end() ) ;
		for( i = N-1; i >= 0 && seq2[i] == seq1[i]; --i ) ;	//i指示了当前堆的边界, 堆大小为i+1
		int tmp = seq2[i] ;
		seq2[i] = seq2[0] ;
		seq2[0] = tmp ;	//此后堆的规模缩小1, 大小变为i
		int child ;
		for( j = 0; 2*j+1 < i ; j = child )
		{
			child = j*2 + 1;	//指向左孩子
			if( child+1 < i && seq2[child+1] > seq2[child] ) ++child ;	 //指向最大的孩子
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
