/*
	PAT(A):1110. Complete Binary Tree (25)
	Date: 2016年3月12日 19:35:23
	Finished: 2016年3月12日 19:48:27
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int maxn = 20 + 10;
int lch[maxn], rch[maxn], fa[maxn];
int n;
vector<int> ans;
int bfs(int x)
{
	queue<int> q;
	q.push(x);
	int last;
	while(!q.empty())
	{
		int u = q.front();	q.pop();
		ans.push_back(u);
		if(u < 0) continue;
		last = u;
		q.push(lch[u]);
		q.push(rch[u]);
	}
	return last;
}
int main()
{
	freopen("F:\\input.txt", "r", stdin);
	scanf("%d", &n);
	fill(fa, fa + n, -1);
	for(int i = 0; i < n; ++i)
	{
		char a[5], b[5];
		int lc = -1, rc = -1;
		scanf("%s %s", a, b);
		if(a[0] != '-') {sscanf(a, "%d", &lc); fa[lc] = i; }
		if(b[0] != '-') {sscanf(b, "%d", &rc); fa[rc] = i; }
		lch[i] = lc;	rch[i] = rc;
	}
	int root = 0;
	for(int i = 0; i < n; ++i) if(fa[i] < 0) {root = i; break;}
	int last = bfs(root);
	bool flag = true;
	for(int i = 0; i < n; ++i) if(ans[i] < 0) {flag = false; break;}
	if(flag) printf("YES %d\n", last);
	else printf("NO %d\n", root);
	return 0;
}