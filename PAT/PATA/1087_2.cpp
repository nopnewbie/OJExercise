/*
	PAT(A):1087. All Roads Lead to Rome (30)
	Date:2016年3月17日 10:42:37
	Finished: 
	bellman-ford / spfa
*/
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

const int maxn = 200 + 10;
const int INF = 0x3fffffff;
struct Edge
{
	string from, to;
	int cost;
	Edge(string f, string t, int c = 0):from(f), to(t), cost(c){}
};
vector<Edge> eg;
map<string, vector<int>> G;
int n, m;
string beg;
map<string, int> wt, cost;
map<string, set<string>> pre;

void spfa(string s)
{
//	fill(cost.begin(), cost.end(), INF);	//不能用
	for (auto i : cost) i.second = INF;
	queue<string> q;
	cost[s] = 0;
	q.push(s);
	while (!q.empty())
	{
		string u = q.front(); q.pop();
		for (int i = 0; i < G[u].size(); ++i)
		{
			const Edge &e = eg[G[u][i]];
			if (cost[e.to] > cost[u] + e.cost)
			{
				cost[e.to] = cost[u] + e.cost;
				q.push(e.to);
				pre[e.to].clear();
				pre[e.to].insert(u);
			}
			else if (cost[e.to] == cost[u] + e.cost)
			{
				pre[e.to].insert(u);
			}
		}
	}
}

vector<string> tmpPath, bestPath;
int max_happy = 0, pathNum = 0, max_avg = 0;
void dfs(string v)
{
	if (v == beg)
	{
		++pathNum;
		tmpPath.push_back(v);
		int hp = 0;
		for (auto i : tmpPath)	hp += wt[i];
		int avg = hp / (tmpPath.size() - 1);
		if (hp > max_happy ||(hp == max_happy && avg > max_avg))
		{
			max_happy = hp;
			max_avg = avg;
			bestPath = tmpPath;
		}
		tmpPath.pop_back();
		return;
	}
	tmpPath.push_back(v);
	for (auto i : pre[v]) dfs(i);
	tmpPath.pop_back();
}

int main()
{
	freopen("F:\\input.txt", "r", stdin);
	cin >> n >> m >> beg;
	wt[beg] = cost[beg] = 0;
	string c1, c2;
	for (int i = 0, hp; i < n - 1; ++i)
	{
		cin >> c1 >> hp;
		wt[c1] = hp;
		cost[c1] = INF;
	}
	for (int i = 0, cos; i < m; ++i)
	{
		cin >> c1 >> c2 >> cos;
		eg.push_back(Edge(c1, c2, cos));
		G[c1].push_back(eg.size() - 1);
		eg.push_back(Edge(c2, c1, cos));
		G[c2].push_back(eg.size() - 1);
	}
	spfa(beg);
	dfs("ROM");
	printf("%d %d %d %d\n%s",pathNum, cost["ROM"], max_happy, max_avg, beg.c_str());
	for (int i = bestPath.size() - 2; i >= 0; --i)
		printf("->%s", bestPath[i].c_str());
	return 0;
}