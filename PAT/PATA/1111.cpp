/*
	PAT(A):1111. Online Map (30)
	Date:2016年3月14日 20:11:57
	Finished: 2016年3月14日 20:54:04
*/
#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;

struct Edge
{
	int from, to, dist, time;
	Edge(int f = 0, int t = 0, int d = 0, int ti = 0):from(f), to(t), dist(d), time(ti){}
};
vector<Edge> eg;
const int maxn = 500 + 10;
const int INF = 0x3fffffff;
vector<int> G[maxn];
vector<int> pre_t[maxn], pre_d[maxn], fPath, sPath;
int m_dist[maxn], m_time[maxn];
int n, m, s, d;

void dDijkstra(int beg)
{
	vector<bool> done(n, false);
	fill(m_dist, m_dist + n, INF);
	fill(m_time, m_time + n, INF);
	typedef pair<int, int> pii;
	priority_queue<pii, vector<pii>, greater<pii>> q;
	q.push(make_pair(m_time[beg] = m_dist[beg] = 0, beg));
	while(!q.empty())
	{
		int u = q.top().second;	
		q.pop();
		if(done[u]) continue;
		for(int i = 0; i < G[u].size(); ++i)
		{
			const Edge &e = eg[G[u][i]];
			if(m_dist[e.to] > m_dist[u] + e.dist || (m_dist[e.to] == m_dist[u] + e.dist && m_time[e.to] > m_time[u] + e.time))
			{
				m_dist[e.to] = m_dist[u] + e.dist;
				m_time[e.to] = m_time[u] + e.time;
				q.push(make_pair(m_dist[e.to], e.to));
				pre_d[e.to].clear();
				pre_d[e.to].push_back(u);	//记录边的编号
			}
		}
	}
	for(int i = d; !pre_d[i].empty(); i = pre_d[i][0]) sPath.push_back(i);
	sPath.push_back(s);
	reverse(sPath.begin(), sPath.end());
}

void tDijkstra(int beg)
{
	vector<bool> done(n, false);
	fill(m_time, m_time + n, INF);
	typedef pair<int, int> pii;
	priority_queue<pii, vector<pii>, greater<pii>> q;
	q.push(make_pair(m_time[beg] = 0, beg));
	while(!q.empty())
	{
		int u = q.top().second;	
		q.pop();
		if(done[u]) continue;
		for(int i = 0; i < G[u].size(); ++i)
		{
			const Edge &e = eg[G[u][i]];
			if(m_time[e.to] > m_time[u] + e.time)
			{
				m_time[e.to] = m_time[u] + e.time;
				q.push(make_pair(m_time[e.to], e.to));
				pre_t[e.to].clear();
				pre_t[e.to].push_back(u);
			}
			else if(m_time[e.to] == m_time[u] + e.time)	pre_t[e.to].push_back(u);
		}
	}
}

vector<int> tmpPath;
void dfs(int x)
{
	if(x == s)
	{
		tmpPath.push_back(x);
		if(fPath.empty() || fPath.size() > tmpPath.size()) fPath = vector<int>(tmpPath.rbegin(), tmpPath.rend());
		tmpPath.pop_back();
		return;
	}
	for(int i = 0; i < pre_t[x].size(); ++i)
	{
		tmpPath.push_back(x);
		dfs(pre_t[x][i]);
		tmpPath.pop_back();
	}
}

int main()
{
	freopen("F:\\input.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	for(int i = 0, v1, v2, ow, d, t; i < m; ++i)
	{
		scanf("%d%d%d%d%d", &v1, &v2, &ow, &d, &t);
		eg.push_back(Edge(v1, v2, d, t));
		G[v1].push_back(eg.size() - 1);
		if(ow) continue;
		eg.push_back(Edge(v2, v1, d, t));
		G[v2].push_back(eg.size() - 1);
	}
	scanf("%d%d", &s, &d);
	dDijkstra(s);
	tDijkstra(s);	dfs(d);
	if(fPath == sPath)
	{
		printf("Distance = %d; Time = %d: %d", m_dist[d], m_time[d], fPath[0]);
		for(int i = 1; i < fPath.size(); ++i) printf(" -> %d", fPath[i]);
		puts("");
	}
	else
	{
		printf("Distance = %d: %d", m_dist[d], sPath[0]);
		for(int i = 1; i < sPath.size(); ++i) printf(" -> %d", sPath[i]);
		puts("");
		printf("Time = %d: %d", m_time[d], fPath[0]);
		for(int i = 1; i < fPath.size(); ++i) printf(" -> %d", fPath[i]);
		puts("");
	}
	return 0;
}