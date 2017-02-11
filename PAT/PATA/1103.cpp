/*
	PAT(A):1103. Integer Factorization (30)
	Date: 2016年2月22日 15:05:49
	Finished: 2016年2月23日 15:34:07
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;

int n, k, p;
vector<int> fac , ans, tmp;

int power(int x)
{
	int ans = 1;
	for(int i = 0; i < p; ++i) ans *= x;
	return ans;
}

void init()
{
	fac.push_back(0);
	int i = 1, temp = 1;
	while(temp  <= n)
	{
		fac.push_back(temp);
		temp = power(++i);
	}
}

void dfs(int sum, int _k, int idx)
{
	if(sum == n && _k == k)
	{
		ans = tmp;
		return;
	}
	if(sum > n || _k > k) return;
	tmp.push_back(idx);
	dfs(sum + fac[idx], _k+1, idx);
	tmp.pop_back();
	if(idx < fac.size() - 1 && sum + fac[idx + 1] <= n)  dfs(sum, _k, idx + 1);
}
int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
	freopen("F:\\input.txt", "r", stdin);
#endif
	scanf("%d%d%d", &n, &k, &p );
	init();
	dfs(0, 0, 1);
	if(ans.empty()) puts("Impossible");
	else
	{
		printf("%d = %d^%d", n, ans.back(), p);
		for(int i = ans.size() - 2; i >= 0; --i) printf(" + %d^%d", ans[i], p);
	}
	return 0;
}