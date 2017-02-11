/*
	PAT(A):1034. Head of a Gang (30)
	Date: 2016年3月3日 14:17:12
	Finished: 2016年3月3日 15:36:10
	并查集
*/
#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<set>
#include<algorithm>
using namespace std;

const int maxn = 26 * 26 * 26 * 26 + 10;	//ZZZ对应的是26^4 - 1
int myset[maxn], wt[maxn], total[maxn];
string num2name[maxn];

struct Edge
{
	int from, to, len;
	Edge(int f = -1, int t = -1, int l = -1): from(f), to(t), len(l){}
};
vector<Edge> edges;

int str_hash(const string &str)
{
	int idx = 0;
	for(unsigned i = 0; i < str.size(); ++i)	idx += idx * 26 + str[i] - 'A';
	return idx;
}

int Find(int x)
{
	return myset[x] < 0 ? x : myset[x] = Find(myset[x]);
}

bool Merge(int x, int y, int len)
{
	int rt1 = Find(x);
	int rt2 = Find(y);
	if(rt1 == rt2) 
	{
		total[rt1] += len;
		return false;
	}
	if(wt[rt1] > wt[rt2]) 
	{
		myset[rt1] += myset[rt2];
		myset[rt2] = rt1;
		total[rt1] += total[rt2] + len;
	}
	else
	{
		myset[rt2] += myset[rt1];
		myset[rt1] = rt2;
		total[rt2] += total[rt1] + len;
	}
	return true;
}

inline void init()
{
	fill(myset, myset + maxn, -1);
	fill(wt, wt + maxn, 0);
	fill(total, total + maxn, 0);
}

int main()
{
	freopen("F:\\input.txt", "r", stdin);
	char a[4], b[4];
	int n, k;
	scanf("%d%d", &n, &k);
	init();
	for(int i = 0, len; i < n; ++i)
	{
		scanf("%s %s %d", a, b, &len);
		int ka = str_hash(a);
		int kb = str_hash(b);
		num2name[ka] = a;
		num2name[kb] = b;
		wt[ka] += len;
		wt[kb] += len;
		edges.push_back(Edge(ka, kb, len));
	}
	for(unsigned i = 0; i < edges.size(); ++i) Merge(edges[i].from, edges[i].to, edges[i].len);
	vector<pair<string, int>> ans;
	for(int i = 0; i < maxn; ++i)
	{
		if(myset[i] < -2 && total[i] > k)	
			ans.push_back(make_pair(num2name[i], -myset[i]));
	}
	printf("%d\n", ans.size());
	for(unsigned i = 0; i < ans.size(); ++i) printf("%s %d\n", ans[i].first.c_str(), ans[i].second);
	return 0;
} 