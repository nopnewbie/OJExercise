/*
	PAT(A)1101. Quick Sort (25)
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<fstream>

using namespace std ;

vector<int> num, leftBiggest, rightSmallest ;
int N ;

int main()
{
#define fin cin
	ifstream fin("F:\\input.txt") ;
	cin >> N ;
	num.resize(N) ;	leftBiggest.resize(N) ;	rightSmallest.resize(N) ;
	for( int i = 0; i < N; ++i )		cin >> num[i] ;
	leftBiggest[0] = num[0] ;
	rightSmallest[N-1]= num[N-1] ;
	for( int i = 1; i < N; ++i )		
		leftBiggest[i] = num[i] >= leftBiggest[i-1] ? num[i] : leftBiggest[i-1] ;
	for( int i = N-2; i >=0; --i )  
		rightSmallest[i] = num[i] <= rightSmallest[i+1] ? num[i] : rightSmallest[i+1] ;
	vector<int> ans ;
	for( int i = 0; i < N; ++i )
	{
		if( num[i] >= leftBiggest[i] && num[i] <= rightSmallest[i] )		
			ans.push_back( num[i] ) ;
	}
	cout << ans.size() << endl ;
	if( !ans.empty() )
	{
		sort(ans.begin(), ans.end() ) ;
		cout <<  ans[0] ;
		for(int i = 1; i < ans.size(); ++i)	cout << ' ' << ans[i] ;
	}
	cout << endl ;
	return 0 ;
}
