/*
	PAT(A):1003. Emergency (25)
	Date: 2016年3月8日 15:36:56
	Finished: 
	SPFA
*/
#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
#include<cstring>
using namespace std;

struct Edge
{
	int from, to, dist;
	Edge(int f = 0, int t = 0, int d = 0):from(f), to(t), dist(d){}
};
vector<Edge> eg;
const int maxn = 500 + 10;
const int INF = 0x3fffffff;
vector<int> G[maxn];
int dist[maxn], wt[maxn], num[maxn], hd[maxn];
set<int> pre[maxn];
int n, m, c1, c2;
int maxHands = 0;
bool spfa(int st)
{
	fill(dist, dist + n, INF);
	memset(num, 0, sizeof(num));
	memset(hd, 0, sizeof(hd));
	dist[st] = 0;
	hd[st] = wt[st];
	num[st] = 1;
	for (int i = 0; i < n - 1; ++i)	//n-1轮松弛操作
		for (int u = 0; u < n; ++u)
			for (int j = 0; j < G[u].size(); ++j)
			{
				const Edge &e = eg[G[u][j]];
				if (dist[e.to] > dist[u] + e.dist)
				{
					dist[e.to] = dist[u] + e.dist;
					hd[e.to] = hd[u] + wt[e.to];
					num[e.to] = num[u];
					pre[e.to].clear();
					pre[e.to].insert(u);
				}
				else if (dist[e.to] == dist[u] + e.dist)
				{
					if (hd[e.to] < hd[u] + wt[e.to])
						hd[e.to] = hd[u] + wt[e.to];
					pre[e.to].insert(u);
					num[e.to] = 0;
					for (auto it : pre[e.to]) num[e.to] += num[it];
				}
			}
	return true;
}

vector<int> tmpPath, bestPath;
int max_hands = 0, pathNum = 0;
void dfs(int v)
{
	if(v == c1)
	{
		++pathNum;
		tmpPath.push_back(v);
		int h = 0;
		for(int i = 0; i < tmpPath.size(); ++i) h += wt[tmpPath[i]];
		if(h > max_hands){ bestPath = tmpPath; max_hands = h; }
		tmpPath.pop_back();
		return;
	}
	tmpPath.push_back(v);
	for(auto i = pre[v].begin(); i != pre[v].end(); ++i)
	{
		dfs(*i);
	}
	tmpPath.pop_back();
}

int main()
{
	freopen("F:\\input.txt", "r", stdin);
	scanf("%d%d%d%d", &n, &m, &c1, &c2);
	for(int i = 0; i < n; ++i) scanf("%d", wt + i);
	for(int i = 0, a, b, d; i < m; ++i)
	{
		scanf("%d%d%d", &a, &b, &d);
		eg.push_back(Edge(a, b, d));
		G[a].push_back(eg.size() - 1);
		eg.push_back(Edge(b, a, d));
		G[b].push_back(eg.size() - 1);
	}
	spfa(c1);
	//dfs(c2);
	//printf("%d %d\n", pathNum, max_hands);
	printf("%d %d\n", num[c2], hd[c2]);
	return 0;
}