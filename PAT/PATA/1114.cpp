/*
	PAT(A):1114. Family Property (25)
	Date:2016年3月15日 10:25:39
	Finished: 
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>
using namespace std;

const int maxn = 1e4;
struct Info
{
	double estateNum, area;
	Info(double num = 0, double ar = 0) : estateNum(num), area(ar){}
} info[maxn];
int myset[maxn];

inline void init()
{
	fill(myset, myset + maxn, -1);
}

int Find(int x)
{
	return myset[x] < 0 ? x : myset[x] = Find(myset[x]);
}

bool Merge(int x, int y)
{
	int rt1 = Find(x);
	int rt2 = Find(y);
	if(rt1 == rt2) return false;
	int root = rt1 < rt2 ? rt1 : rt2;
	int child = rt1 > rt2 ? rt1 : rt2;
	myset[root] += myset[child];
	myset[child] = root;
	info[root].area += info[child].area;
	info[root].estateNum += info[child].estateNum;
}

int main()
{
	freopen("F:\\input.txt", "r", stdin);
	init();
	int n, self, fa, ma, cNum, ch, eNum;
	double eArea;
	scanf("%d", &n);
	vector<vector<int>> family(n);
	unordered_set<int> idSet;
	for(int i = 0; i < n; ++i)
	{
		scanf("%d%d%d%d", &self, &fa, &ma, &cNum);
		family[i].push_back(self);
		idSet.insert(self);
		if(fa > -1) { family[i].push_back(fa); idSet.insert(fa);}
		if(ma > -1) { family[i].push_back(ma); idSet.insert(ma); }
		for(int j = 0; j < cNum; ++j)
		{
			scanf("%d", &ch);
			family[i].push_back(ch);
			idSet.insert(ch);
		}
		scanf("%d%lf", &eNum, &eArea);
		info[self].estateNum += eNum;
		info[self].area += eArea;
	}
	for(int i = 0; i < n; ++i)
	{
		if(family[i].size() < 2)	continue;
		for(int j = 1; j < family[i].size(); ++j) Merge(family[i][0], family[i][j]);
	}
	vector<int> ans;
	for(auto it = idSet.begin(); it != idSet.end(); ++it)
	{
		if(myset[*it] > -1) continue;
		ans.push_back(*it);
		info[*it].estateNum /= -myset[*it];
		info[*it].area /= -myset[*it];
	}
	printf("%d\n", ans.size());
	sort(ans.begin(), ans.end(), [](int a, int b)->bool
	{
		if(info[a].area != info[b].area) return info[a].area > info[b].area;
		else return a < b;
	});
	for(int i = 0; i < ans.size(); ++i)
	{
		int id = ans[i];
		cNum = -myset[id];
		printf("%04d %d %.3lf %.3lf\n", id, cNum, info[id].estateNum, info[id].area);
	}
	return 0;
}