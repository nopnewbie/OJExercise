/*
	PAT(A).1042. Shuffling Machine (20)
	Date: 2016Äê1ÔÂ16ÈÕ 15:37:56
*/
#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>
#define LOCAL
using namespace std;
const int maxn = 54 ;
const string s[] = {"S1","S2","S3","S4","S5","S6","S7","S8","S9","S10","S11","S12","S13",
	"H1","H2","H3","H4","H5","H6","H7","H8","H9","H10","H11","H12","H13",
	"C1","C2","C3","C4","C5","C6","C7","C8","C9","C10","C11","C12","C13",
	"D1","D2","D3","D4","D5","D6","D7","D8","D9","D10","D11","D12","D13","J1", "J2"} ;
int index[maxn] ;
struct node
{
	string ss ;
	int ind ;
	bool operator < ( const node& a ) const
	{ 
		return ind < a.ind ;
	}
} ans[maxn];
int main()
{
#ifdef LOCAL
#define cin fin 
	ifstream fin("F:\\input.txt");
#endif
	int k ;
	cin >> k ;
	for( int i = 0; i < maxn; ++i ) cin >> index[i] ;
	for( int i = 0; i < maxn; ++i ) { ans[i].ss = s[i]; ans[i].ind = index[i];}
	for( int i = 0; i < k; ++i ) 
	{
		sort( ans,ans+maxn) ;
		for( int j = 0; j < maxn; ++j ) ans[j].ind = index[j] ;
	}
	for( int i = 0; i < maxn; ++i )
	{
		if( i ) cout << " ";
		cout << ans[i].ss ;
	}
	cout << endl ;
	return 0 ;
}

