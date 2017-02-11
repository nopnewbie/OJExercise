/*
	参考代码
	PAT(A):1103. Integer Factorization (30)
	Date: 2016年2月22日 15:05:49
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, k, p, maxFacSum = -1;
vector<int> fac, ans, tmp;

int power(int x)
{
	int ans = 1;
	for(int i = 0; i < p; ++i) ans *= x;
	return ans;
}
void init()
{
	int i = 0, temp = 0;
	while(temp <= n)	//i^p 未超过n时, 不断把i^p加入fac
	{
		fac.push_back(temp);
		temp = power(++i);
	}
}

void dfs(int index, int nowK, int sum, int facSum)
{
	if(sum == n && nowK == k)
	{
		if(facSum > maxFacSum)
		{
			ans = tmp;
			maxFacSum = facSum;
		}
		return;
	}
	if(sum > n || nowK > k) return;
	if(index > 0)	//fac[0]不选
	{
		tmp.push_back(index);
		dfs(index, nowK + 1, sum + fac[index], facSum + index);	
		tmp.pop_back();
		dfs(index - 1, nowK, sum, facSum);
	}
}

int main()
{
	freopen("F:\\input.txt", "r", stdin);
	scanf("%d%d%d", &n, &k, &p);
	init();
	dfs(fac.size() - 1, 0, 0, 0);
	if(-1 == maxFacSum) puts("Impossible");
	else
	{
		printf("%d = %d^%d", n, ans[0], p);
		for(auto i = 1; i < ans.size(); ++i) printf(" + %d^%d", ans[i], p);
	}
	return 0;
}