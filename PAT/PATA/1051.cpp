/*
	PAT(A):1051. Pop Sequence (25)
	Date: 2016年2月20日 13:51:07
	Finished: 2016年2月20日 15:12:03
*/
#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
#endif
	int m, n, k;
	cin >> m >> n >> k;
	vector<int> vint(n);
	for(int i = 0; i < k; ++i)
	{
		stack<int> stk;
		int j, u;
		for(j = 0; j < n; ++j) cin >> vint[j];
		j = u = 0;
		while(true)
		{
			while(stk.empty() || stk.size() <= m && stk.top() < vint[j] ) stk.push(++u);
			if(!stk.empty() && stk.size() <= m && stk.top() == vint[j] ) 
			{
				stk.pop(); ++j;
			}
			if(j >= n || u > n || stk.size() > m || (!stk.empty() && stk.top() > vint[j]) ) break;
		}
		cout << (stk.empty() ? "YES" : "NO") << endl;
	}
	return 0;
}