/*
	PAT(A):1053. Path of Equal Weight (30)
	Date: 2016年3月1日 10:45:17
	Finished:2016年3月1日 14:14:38
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 100 + 10;
vector<vector<int>> ans;
vector<int> child[maxn], tmp;
int weight[maxn];
bool visited[maxn];
int m, n, s;

void dfs(int rt, int sum)
{
	if(sum > s || (sum == s && !child[rt].empty() ) || (sum < s && child[rt].empty()) ) return;
	if(sum == s && child[rt].empty()) {ans.push_back(tmp); return;}
	for(auto i = 0; i < child[rt].size(); ++i)
	{
		if(weight[child[rt][i]] + sum <= s && !visited[child[rt][i]])
		{
			tmp.push_back(weight[child[rt][i]]);
			dfs(child[rt][i], weight[child[rt][i]] + sum);
			tmp.pop_back();
			visited[child[rt][i]] = true;
		}
	}
}

int main()
{
	freopen("F:\\input.txt", "r", stdin);
	scanf("%d%d%d", &n, &m, &s);
	for(int i = 0; i < n; ++i) scanf("%d", weight + i);
	for(int i = 0, id, k; i < m; ++i)
	{
		scanf("%d%d", &id, &k);
		child[id].resize(k);
		for(int j = 0; j < k; ++j) scanf("%d", &child[id][j]);
	}
	tmp.push_back(weight[0]);
	dfs(0, weight[0]);
	sort(ans.begin(), ans.end(), [](const vector<int> &a, const vector<int> &b)->bool
	{
		auto i = 0;
		while(i < a.size() && i < b.size() && a[i] == b[i]) ++i;
		if(i < a.size() && i < b.size())
		{
			return a[i] > b[i];
		}
		else return false;
	});
	for(auto i = 0; i < ans.size(); ++i)
	{
		printf("%d", ans[i][0]);
		for(auto j = 1; j < ans[i].size(); ++j) printf(" %d", ans[i][j]);
		puts("");
	}
	return 0;
}