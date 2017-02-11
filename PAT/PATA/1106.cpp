/*
	PAT(A):1106. Lowest Price in Supply Chain (25)
	Date: 2016年3月1日 20:00:02
	Finished: 2016年3月1日 20:18:04
*/
#include<iostream>
#include<vector>
using namespace std;
 
const int maxn = 1e5 + 10;
int n, cnt;
double p, r, lp = maxn;
vector<int> child[maxn];

void dfs(int s, double rate)
{
	if(child[s].empty()) 
	{
		if(rate < lp)
		{
			lp = rate;	cnt = 1;
		}
		else if(rate == lp) ++cnt;
		return;
	}
	else if(rate > lp) return ;
	for(unsigned i = 0; i < child[s].size(); ++i) dfs(child[s][i], rate * r);
}

int main()
{
	freopen("F:\\input.txt", "r", stdin);
	scanf("%d%lf%lf", &n, &p, &r);
	r = 1 + r / 100;
	for(int i = 0, k; i < n; ++i)
	{
		scanf("%d", &k);
		if(k)
		{
			child[i].resize(k);
			for(int j = 0; j < k; ++j) scanf("%d", &child[i][j]);
		}
	}
	dfs(0, 1);
	printf("%.4lf %d", lp * p, cnt);
	return 0;
}