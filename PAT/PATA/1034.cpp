/*
	PAT(A):1034. Head of a Gang (30)
	Date: 2016年3月3日 10:47:06
	Finished: 2016年3月3日 14:15:17
	DFS
*/
#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

struct Edge
{
	string from, to;
	int wt;
	Edge(){}
	Edge(string f, string t, int w): from(f), to(t), wt(w){}
};
vector<Edge> edges;
map<string, int> wt;	//各节点权重
map<string, vector<int>> G;	//邻接表
map<string, bool> vis;
map<string, int> ans;
int n, k;

void dfs(string now, string &head, int &memNum, int &sum)
{
	if(vis[now]) return;
	vis[now] = true;
	++memNum;
	if(wt[now] > wt[head]) head = now;
	for(unsigned i = 0; i < G[now].size(); ++i)
	{
		const Edge &eg = edges[G[now][i]];
		sum += eg.wt;
		if(vis[eg.to]) continue;
		dfs(eg.to, head, memNum, sum);
	}
}

int main()
{
	freopen("F:\\input.txt", "r", stdin);
	scanf("%d%d", &n, &k);
	char a[4], b[4];
	for(int i = 0, w; i < n; ++i)
	{
		scanf("%s %s %d", a, b, &w);
		wt[a] += w;
		wt[b] += w;
		vis[a] = false;
		vis[b] = false;
		edges.push_back( Edge(a, b, w) );
		G[a].push_back(edges.size() - 1);
	}
	for(auto it = vis.begin(); it != vis.end(); ++it)
	{
		if(!(it->second))
		{
			string head = it->first;
			int memNum = 0, sum = 0;
			dfs(it->first, head, memNum, sum);
			if(memNum > 2 && sum > k ) ans[head] = memNum;
		}
	}
	printf("%d\n", ans.size());
	for(auto it = ans.begin(); it != ans.end(); ++it)	printf("%s %d\n", it->first.c_str(), it->second);
	return 0;
}