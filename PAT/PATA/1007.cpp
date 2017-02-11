/*
	PAT(A): 1007.Maximum Subsequence Sum (25)
	一个特殊情况。如，输入的是：
       4
      -1 0 0 -1
      那么我们输出的应该是： 0 0 0
*/
#include<iostream>
#include<algorithm>
#include<fstream>

#define cin fin

using namespace std ;

int a[10000+5] ;
int k ;

int main()
{
	ifstream fin("F:\\input.txt") ;
	int st=0, /*ed=0,*/ sum = 0, Maxsum = -1, MaxS=0, MaxE=0 ;
	bool flag = true ;
	cin >> k ;
	for( int i = 0; i < k; ++i )
	{
		cin >> a[i] ;
		if( a[i] >= 0 ) flag = false ;
		sum += a[i] ;
		if( sum > Maxsum ) 
		{
			Maxsum = sum ;
			MaxS = st ;
			MaxE = i ;
		}
		else if(sum < 0)
		{
			st = i+1 ;
			sum = 0 ;
		}
	}
	if(flag) cout << "0 " << a[0] << ' ' << a[k-1] << endl ;
	else
		cout << Maxsum << ' ' << a[MaxS] << ' ' << a[MaxE] << endl ;
	return 0 ;
}

