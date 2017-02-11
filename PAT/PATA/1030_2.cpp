/*
	PAT(A):1030. Travel Plan (30)
	Date:2016年3月17日 09:27:02
	Finished: 
	bellman-ford / spfa
*/
#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
#include<cstring>
using namespace std;

int n, m, s, d;
const int maxn = 500 + 10;
const int INF = 0x3fffffff;
int dist[maxn], cost[maxn], pre[maxn];
struct Edge
{
	int from, to, dist, cost;
	Edge(int f = 0, int t = 0, int d = 0, int c = 0):from(f), to(t), dist(d), cost(c){}
};
vector<Edge> eg;
vector<int> G[maxn];
vector<int> path;
void spfa(int x)
{
	fill(dist, dist + n, INF);
	fill(cost, cost + n, INF);
	memset(pre, -1, sizeof(pre));
	cost[x] = dist[x] = 0;
	queue<int> q;
	q.push(x);
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		for (int i = 0; i < G[u].size(); ++i)
		{
			const Edge &e = eg[G[u][i]];
			if (dist[e.to] > dist[u] + e.dist || (dist[e.to] == dist[u] + e.dist && cost[e.to] > cost[u] + e.cost) )
			{
				dist[e.to] = dist[u] + e.dist;
				cost[e.to] = cost[u] + e.cost;
				q.push(e.to);
				pre[e.to] = u;
			}
		}
	}
	int p = d;
	while (p > -1)
	{
		path.push_back(p);
		p = pre[p];
	}
}

int main()
{
	freopen("F:\\input.txt", "r", stdin);
	scanf("%d%d%d%d", &n, &m, &s, &d);
	for (int i = 0, u, v, dis, c; i < m; ++i)
	{
		scanf("%d%d%d%d", &u, &v, &dis, &c);
		eg.push_back(Edge(u, v, dis, c));
		G[u].push_back(eg.size() - 1);
		eg.push_back(Edge(v, u, dis, c));
		G[v].push_back(eg.size() - 1);
	}
	spfa(s);
	for (int i = path.size() - 1; i >= 0; --i) printf("%d ", path[i]);
	printf("%d %d\n", dist[d], cost[d]);
	return 0;
}
