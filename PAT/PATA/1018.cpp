/*
	PAT(A):1018. Public Bike Management (30)
	Date: 2016年3月4日 11:05:17
	Finished: 
*/
#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;

struct Edge
{
	int from, to, time;
	Edge(int f = 0, int t = 0, int tm = 0):from(f), to(t), time(tm){}
};
vector<Edge> edges;
const int maxn = 500 + 10;
const int INF = 1e9;
int cmax, n, sp, m;
int bike[maxn], minTime[maxn];	//各站现有车辆
bool done[maxn];
vector<int> G[maxn], pre[maxn];
vector<int> tmpPath, bestPath;
int send = INF, take = INF;

void Dijkstra(int s)
{
	fill(done, done + n + 1, false);
	fill(minTime, minTime + n + 1, INF);
	typedef pair<int, int> pii;
	priority_queue<pii, vector<pii>, greater<pii>> q;
	minTime[s] = 0;
	q.push(make_pair(minTime[s], s));
	while(!q.empty())
	{
		int u = q.top().second, t = q.top().first; 
		q.pop();
		done[u] = true;
		for(unsigned i = 0; i < G[u].size(); ++i)
		{
			const Edge &e = edges[G[u][i]];
			if(done[e.to]) continue;
			if( minTime[u] + e.time < minTime[e.to])
			{
				minTime[e.to] = minTime[u] + e.time;
				q.push( make_pair(minTime[e.to], e.to) );
				pre[e.to].clear();
				pre[e.to].push_back(u);
			}
			else if( minTime[u] + e.time == minTime[e.to] )
			{
				pre[e.to].push_back(u);
//				q.push( make_pair(minTime[e.to], e.to) );/*这句不能有,可能引起死循环, 原因??*/
			}
		}
	}
}

void dfs(int v)
{
	if(!v )
	{//若是到达起点0
		int rem = 0, need = 0;
		for(int i = tmpPath.size() - 1; i >= 0; --i)
		{
			int id = tmpPath[i];
			if(bike[id] > 0) rem += bike[id];
			else
			{
				if( rem > abs(bike[id]) ) rem += bike[id];
				else 
				{
					need += abs(bike[id]) - rem;
					rem = 0;
				}
			}
		}
		if(need < send || (need == send && rem < take))
		{
			send = need;
			take = rem;
			bestPath = tmpPath;
			bestPath.push_back(0);
		}
		return;
	}
	for(unsigned i = 0; i < pre[v].size(); ++i)
	{
		tmpPath.push_back(v);
		dfs(pre[v][i]);
		tmpPath.pop_back();
	}
}

int main()
{
	freopen("F:\\input.txt", "r", stdin);
	scanf("%d%d%d%d", &cmax, &n, &sp, &m);
	for(int i = 1; i <= n; ++i) scanf("%d", bike + i);
	for(int i = 1; i <= n; ++i) bike[i] -= cmax / 2;
	bike[0] = cmax / 2;
	for(int i = 0, si, sj, t; i < m; ++i)
	{
		scanf("%d%d%d", &si, &sj, &t);
		edges.push_back(Edge(si, sj, t));
		G[si].push_back(edges.size() - 1);
		edges.push_back(Edge(sj, si, t));
		G[sj].push_back(edges.size() - 1);
	}
	Dijkstra(0);
	dfs(sp);
	printf("%d ", send);
	for(int i = bestPath.size() - 1; i >= 0; --i)
	{
		if(i + 1 < bestPath.size()) printf("->");
		printf("%d", bestPath[i]);
	}
	printf(" %d\n", take);
	return 0;
}