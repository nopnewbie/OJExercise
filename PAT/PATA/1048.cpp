/*
	PAT(A):1048. Find Coins (25)
	Date: 2016年2月13日 21:59:15
*/
#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#include<cctype>
#include<algorithm>
#include<fstream>
using namespace std;

const int maxn = 500 + 10;
int coins[maxn] = {0};

int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
#endif
	int N, M;
	cin >> N >> M;
	for( int i = 0; i < N; ++i )
	{
		int x;
		cin >> x;	++coins[x];
	}
	bool flag = true;
	for(int i = 0; i < maxn; ++i )
	{
		if(M == (i << 1)) 
		{
			if(2 <= coins[i])
			{
				cout << i << " " << i << endl; 
				flag = false; 
				break;
			}
		}
		else if(M - i < maxn && coins[i] && coins[M - i]) 
		{ 
			cout << i << " " << M - i << endl; 
			flag = false;
			break;
		}
	}
	if(flag) cout << "No Solution" << endl;
	return 0;
}