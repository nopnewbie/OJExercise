/*
	PAT(A):1094. The Largest Generation (25)
	Date: 2016年3月1日 19:31:22
	Finished: 2016年3月1日 19:55:45
*/
#include<iostream>
#include<queue>
#include<vector>
#include<utility>
using namespace std;

const int maxn = 100 + 10;
int n, m, maxGen = 1;
vector<int> child[maxn];
int g[maxn];	//统计每代人数

typedef pair<int, int> pairInt;

void bfs(int s)
{
	queue<pairInt> q;
	q.push(make_pair(s, 1));
	while(!q.empty())
	{
		int v = q.front().first, lv = q.front().second; q.pop();
		maxGen = lv > maxGen ? lv : maxGen;
		++g[lv];	//lv代人数+1
		for(unsigned i = 0; i < child[v].size(); ++i) q.push(make_pair(child[v][i], lv + 1));
	}
}

int main()
{
	freopen("F:\\input.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	for(int i = 0, id, k; i < m; ++i)
	{
		scanf("%d%d", &id, &k);
		child[id].resize(k);
		for(int j = 0; j < k; ++j) scanf("%d", &child[id][j]);
	}
	bfs(1);
	int lv = 1;
	for(int i = 2; i <= maxGen; ++i) lv = g[lv] > g[i] ? lv : i;
	printf("%d %d\n", g[lv], lv);
	return 0;
}