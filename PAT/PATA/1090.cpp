/*
	PAT(A):1090. Highest Price in Supply Chain (25)
	Date: 2016年3月1日 15:06:05
	Finished: 2016年3月1日 15:24:18
*/
#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

const int maxn = 1e5 + 10;
int n;
double p, r;
pair<double, int> ans;
vector<int> child[maxn];

void dfs(int s, double rate)
{
	if(child[s].empty())
	{
		if(rate == ans.first) ++ans.second;
		else if(rate > ans.first) { ans.first = rate;	ans.second = 1;}
		return;
	}
	for(unsigned i = 0; i < child[s].size(); ++i) dfs(child[s][i], rate * r);
}

int main()
{
	freopen("F:\\input.txt", "r", stdin);
	scanf("%d%lf%lf", &n, &p, &r);
	int root;
	for(int i = 0, id; i < n; ++i)
	{
		scanf("%d", &id);
		if(id >= 0)	child[id].push_back(i);
		else root = i;
	}
	r = 1 + r / 100;
	dfs(root, 1);
	printf("%.2lf %d\n", ans.first * p, ans.second);
	return 0;
}
