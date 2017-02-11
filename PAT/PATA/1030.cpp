/*
	PAT(A):1030. Travel Plan (30)
	Date: 2016年3月4日 00:04:03
	Finished: 2016年3月4日 01:20:06
*/
#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;

struct Edge
{
	int from, to, dist, toll;
	Edge(int f = 0, int t = 0, int d = 0, int tol = 0):from(f), to(t), dist(d), toll(tol){}
};

const int maxn = 500 + 10;
const int INF = maxn;
int n, s, d, m;
vector<Edge> edges;
vector<int> G[maxn];
int dist[maxn], cost[maxn], path[maxn];
bool vis[maxn];
void Dijkstra(int s)
{
	fill(dist, dist + n, INF);
	fill(cost, cost + n, INF);
	fill(vis, vis + n, false);
/*
	vector<bool> inq(n, false);	这不是树。
	因为priority_queue不允许修改优先级，
	而到节点u的最短距离可能会变小可能要重复入队
*/
	dist[s] = cost[s] = 0;
	typedef pair<int, int> PII;
	priority_queue< PII, vector<PII>, greater<PII>> q;
	q.push(make_pair(dist[s], s));
	while(!q.empty())
	{
		int u = q.top().second;
		q.pop();
		vis[u] = true;	//出队才是处理完毕
		for(unsigned i = 0; i < G[u].size(); ++i)
		{
			Edge &e = edges[G[u][i]];
			if(vis[e.to]) continue;	//已经处理过,直接丢弃
			if(dist[u] + e.dist < dist[e.to])
			{
				dist[e.to] = dist[u] + e.dist;
				cost[e.to] = cost[u] + e.toll;
				q.push(make_pair(dist[e.to], e.to));
				path[e.to] = u;
			}
			else if(dist[u] + e.dist == dist[e.to] && cost[u] + e.toll < cost[e.to])
			{
				cost[e.to] = cost[u] + e.toll;
				q.push(make_pair(dist[e.to], e.to));
				path[e.to] = u;
			}
		}
	}
}

int main()
{
	freopen("F:\\input.txt", "r", stdin);
	scanf("%d%d%d%d", &n, &m, &s, &d);
	for(int i = 0, f, t, d, c; i < m; ++i)
	{
		scanf("%d%d%d%d", &f, &t, &d, &c);
		edges.push_back(Edge(f,t,d,c));
		G[f].push_back(edges.size() - 1);
		edges.push_back(Edge(t, f, d, c));
		G[t].push_back(edges.size() - 1);
	}
	Dijkstra(s);
	vector<int> ans;
	ans.push_back(d);
	for(int i = d; path[i] != s; i = path[i]) ans.push_back(path[i]);
	reverse(ans.begin(), ans.end());
	printf("%d", s);
	for(int i = 0; i < ans.size(); ++i)	printf(" %d", ans[i]);
	printf(" %d %d\n", dist[d], cost[d]);
	return 0;
}