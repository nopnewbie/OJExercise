/*
	PAT(A):1072. Gas Station (30)
	Date: 2016年3月7日 20:24:08
	Finished: 2016年3月8日 09:50:45
*/
#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<cstring>
#include<algorithm>
using namespace std;

const int INF = 0x7fffffff;
const int maxn = 1e3 + 20;
const double eps = 1e-6;

struct Station
{
	bool isValid;
	double avg_dist, min_dist;
	int id;
	Station(bool v = true, double ad = 0, int md = 0):isValid(v), avg_dist(ad), min_dist(md){}
	bool operator < (const Station &rhs) const
	{
//		if(!isValid) return false;
		if(min_dist != rhs.min_dist) return min_dist > rhs.min_dist;
		else if(abs(avg_dist - rhs.avg_dist) > eps) return avg_dist < rhs.avg_dist;
		else return id < rhs.id;
	}
}station[12];

struct Edge
{
	int from, to, dist;
	Edge(int f, int t, int d):from(f), to(t), dist(d){}
};
vector<Edge> eg;
vector<int> G[maxn];
int dist[maxn];
int n, m, k, ds;

void Dijkstra(int st)
{
	vector<bool> done(maxn, false);
	fill(dist, dist + maxn, INF);
	typedef pair<int, int> pii;
	priority_queue<pii, vector<pii>, greater<pii>> q;
	q.push( make_pair(dist[st] = 0, st) );
	while(!q.empty())
	{
		int u = q.top().second;
		q.pop();
		if(done[e.to]) continue;
		done[u] = true;
		for(unsigned i = 0; i < G[u].size(); ++i)
		{
			const Edge &e = eg[G[u][i]];
			if(dist[e.to] > dist[u] + e.dist)
			{
				dist[e.to] = dist[u] + e.dist;
				q.push( make_pair(dist[e.to], e.to) );
			}
		}
	}
}

int main()
{
	freopen("F:\\input.txt", "r", stdin);
	scanf("%d%d%d%d", &n, &m, &k, &ds);
	char a[3], b[3];
	int d;
	for(int i = 0; i < k; ++i)
	{
		int x, y;
		scanf("%s %s %d", a, b, &d);
		if(a[0] != 'G') sscanf(a, "%d", &x);
		else 
		{
			sscanf(a + 1, "%d", &x);
			x += n;
		}
		if(b[0] != 'G') sscanf(b, "%d", &y);
		else 
		{
			sscanf(b + 1, "%d", &y);
			y += n;
		}
		eg.push_back(Edge(x, y, d));
		G[x].push_back(eg.size() - 1);
		eg.push_back(Edge(y, x, d));
		G[y].push_back(eg.size() - 1);
	}
	for(int i = n + 1; i <= n + m; ++i)
	{
		Dijkstra(i);
		double sum = 0;
		int mind = dist[1];
		station[i - n].id = i - n;
		for(int j = 1; j <= n; ++j)
		{
			if(dist[j] > ds) 
			{
				station[i - n].isValid = false;
				break;
			}
			else
			{
				sum += dist[j];
				mind = dist[j] < mind ? dist[j] : mind;
			}
		}
		if(station[i - n].isValid)
		{
			station[i - n].min_dist = mind;
			station[i - n].avg_dist = sum / n;
		}
	}
	sort(station + 1, station + m + 1);
	int ans = 1;
	while(ans <= m && !station[ans].isValid) ++ans;
	if(ans <= m)
	{
		printf("G%d\n", station[ans].id);
		printf("%.1lf %.1lf\n", station[ans].min_dist, station[ans].avg_dist);
	}
	else puts("No Solution");
	return 0;
}