/*
	PAT(A):1079. Total Sales of Supply Chain (25)
	Date: 2016年3月1日 14:15:47
	Finished:2016年3月1日 15:01:22
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 1e5 + 10;
unsigned n;
double ans = 0, p, r;
vector<unsigned> child[maxn];
int wt[maxn];

void dfs(unsigned s, double rate)
{
	if(child[s].empty()) ans +=  rate * wt[s] ;
	for(unsigned i = 0; i < child[s].size(); ++i)	dfs(child[s][i], rate * r);
}

int main()
{
	freopen("F:\\input.txt", "r", stdin);
	scanf("%u%lf%lf", &n, &p, &r);
	r = 1 + r / 100;
	for(unsigned i = 0, k; i < n; ++i)
	{
		scanf("%u", &k);
		if(k)
		{
			wt[i] = 1;	//非叶节点权重置为1
			for(unsigned j = 0, id; j < k; ++j)
			{
				scanf("%u", &id);
				child[i].push_back(id);
			}
		}
		else	scanf("%d", wt + i);		//读入叶子节点的权重(存货量)
	}
	dfs(0, 1);
	printf("%.1lf", ans * p);
	return 0;
}