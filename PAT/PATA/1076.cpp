/*
	PAT(A):1076. Forwards on Weibo (30)
	Date: 2016年3月3日 19:00:36
	Finished: 2016年3月3日 19:20:24
*/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
using namespace std;

const int maxn = 1000 + 10;
int n, l, k;
vector<int> G[maxn];

void bfs(int s)
{
	vector<bool> inq(n + 1, false);
	queue<pair<int, int>> q;
	q.push(make_pair(s, 0));
	inq[s] = true;
	int ans = 0;
	while(!q.empty())
	{
		int v = q.front().first;
		int lv = q.front().second;
		q.pop();
		if(lv < l)
		{
			for(unsigned i = 0; i < G[v].size(); ++i)
			{
				if(inq[G[v][i]]) continue;
				++ans;
				inq[G[v][i]] = true;
				q.push(make_pair(G[v][i], lv + 1));
			}
		}
	}
	printf("%d\n", ans);
}

int main()
{
	freopen("F:\\input.txt", "r", stdin);
	scanf("%d%d", &n, &l);
	for(int i = 1, m; i <= n; ++i)
	{
		scanf("%d", &m);
		for(int j = 0, u; j < m; ++j) 
		{
			scanf("%d", &u);
			G[u].push_back(i);
		}
	}
	scanf("%d", &k);
	for(int i = 0, query; i < k; ++i) 
	{
		scanf("%d", &query);
		bfs(query);
	}
	return 0;
}