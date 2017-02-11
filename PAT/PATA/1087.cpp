/*
	PAT(A):1087. All Roads Lead to Rome (30)
	Date: 2016年3月5日 13:53:23
	Finished: 2016年3月5日 15:13:51
*/
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<utility>
using namespace std;

struct Edge
{
	string from, to;
	int cost;
	Edge(const string &f,const string &t,	int c  = 0):from(f), to(t), cost(c){}
};


const int maxn = 200 + 10;
const int INF = 1e9;
int n, k, pathNum, maxHp = -1, minCity = maxn;
string st;
map<string, int> happy, cost;
map<string, vector<int>> G;
vector<Edge> edges;
map<string, bool> vis;
map<string, vector<string>> pre;
vector<string> tmpPath, bestPath;
void Dijkstra(string s)
{
	for(auto it = happy.begin(); it != happy.end(); ++it) { vis[it->first]  = false;	cost[it->first] = INF; }
	typedef pair<int, string> pis;
	priority_queue<pis, vector<pis>, greater<pis>> q;
	q.push(make_pair(cost[s] = 0, s));
	while(!q.empty())
	{
		string u = q.top().second;
		int cst = q.top().first;
		q.pop();
		vis[u] = true;
		for(unsigned i  = 0; i < G[u].size(); ++i)
		{
			const Edge &e = edges[ G[u][i] ];
			if(vis[e.to]) continue;
			if(cost[e.to] > cost[u] + e.cost)
			{
				cost[e.to] = cost[u] + e.cost;
				pre[e.to].clear();
				pre[e.to].push_back(u);
				q.push(make_pair(cost[e.to], e.to));
			}
			else if(cost[e.to] == cst + e.cost)
			{
				pre[e.to].push_back(u);
			}
		}
	}
}

void dfs(string s, int hp, int city)
{
	if(s == st)
	{
		tmpPath.push_back(s);
		++pathNum;	//路径+1
		if(hp > maxHp )	
		{
			maxHp		= hp; 
			minCity		= city;
			bestPath	= tmpPath; 
		}
		else if(hp == maxHp && city < minCity) 
		{
			minCity = city; 
			bestPath = tmpPath;
		}
		tmpPath.pop_back();
		return;
	}
	for(unsigned i = 0; i < pre[s].size(); ++i)
	{
		string id = pre[s][i];
		tmpPath.push_back(s);
		dfs(id, hp + happy[s], city + 1);
		tmpPath.pop_back();
	}
}

int main()
{
	freopen("F:\\input.txt", "r", stdin);
	char buf[4], buf2[4];
	scanf("%d %d %s", &n, &k, buf);
	happy[st = buf] = 0;
	for(int i = 1, hp; i < n; ++i)
	{
		scanf("%s %d", buf, &hp);
		happy[buf] = hp;
	}
	for(int i = 0, cost; i < k; ++i)
	{
		scanf("%s %s %d", buf, buf2, &cost);
		edges.push_back(Edge(buf, buf2, cost));
		G[buf].push_back(edges.size() - 1);
		edges.push_back(Edge(buf2, buf, cost));
		G[buf2].push_back(edges.size() - 1);
	}
	Dijkstra(st);
	dfs("ROM", 0, 0);
	printf("%d %d %d %d\n", pathNum, cost["ROM"], maxHp, maxHp / minCity);
	for(int i = bestPath.size() - 1; i >= 0; --i)
	{
		if(i < bestPath.size() - 1) printf("->");
		printf("%s", bestPath[i].c_str());
	}
	return 0;
}