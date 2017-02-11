/*
	PAT(A):1096. Consecutive Factors (20)
	Date: 2016年1月22日 14:05:26
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstring>
#include<cctype>
#include<algorithm>
using namespace std;
#define LOCAL
bool isprime( long long n )
{
	for( long long i = 2; i * i <= n; ++i)
	{
		if( !(n % i) ) return false;
	}
	return true;
}
int main()
{
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
	freopen("F:\\input.txt", "r", stdin);
#endif
	long long n;
	cin >> n;
	if( isprime(n) ) { printf("1\n%lld\n",n); return 0; }	//素数的单独判定, 否则最后一个测试点的大素数会超时
	vector<int> ans;
	for( int i = 1; i < 13; ++i )
	{
		for( int j = 2; j*j <= n; ++j )
		{
			long long tmp = 1;
			for( int k = j; k < i+j && tmp <= n; ++k ) tmp *= k;
			if( tmp > n )  break;// 当前的j*(j+1)*...*(j+i-1)都大于n了, 后续的j就更不用算了,直接跳出内层循环,使得++i
			if( !(n % tmp) && i > ans.size() ) 
			{
				ans.resize(0);
				for( int k = j; k < i + j; ++k  ) ans.push_back(k) ;
			}
		}
	}
	if( ans.empty() ) printf("1\n%lld", n);
	else
	{
		printf("%d\n%d",ans.size(), ans[0] );
		for( int i = 1; i < ans.size(); ++i ) printf("*%d",ans[i]);
		putchar('\n');
	}
	return 0;
}
