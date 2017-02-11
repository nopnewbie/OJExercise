/*
	PAT(A):1107. Social Clusters (30)
	Date: 2016年3月1日 20:25:23
	Finished: 2016年3月1日 21:13:04
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 1000 + 10;
int myset[maxn], hb[maxn];
int n;

int Find(int x)
{
	return myset[x] < 0 ? x : myset[x] = Find(myset[x]);
}

bool Merge(int x, int y)
{
	int rt1 = Find(x);
	int rt2 = Find(y);
	if(rt1 == rt2) return false;
	else if(myset[rt1] <= myset[rt2])
	{
		myset[rt1] += myset[rt2];
		myset[rt2] = rt1;
	}
	else
	{
		myset[rt2] += myset[rt1];
		myset[rt1] = rt2;
	}
	return true;
}

int main()
{
	freopen("F:\\input.txt", "r", stdin);
	scanf("%d", &n);
	fill(myset + 1, myset + n + 1, -1);
	for(int i = 1, k; i <= n; ++i)
	{
		scanf("%d: ", &k);
		for(int j = 0, h; j < k; ++j)
		{
			scanf("%d", &h);
			if(!hb[h]) hb[h] = i;
			Merge(i, hb[h]);
		}
	}
	vector<int> ans;
	for(int i = 1; i <= n; ++i) if(myset[i] < 0) ans.push_back(-myset[i]);
	sort(ans.begin(), ans.end(), greater<int>());
	printf("%d\n%d", ans.size(), ans[0]);
	for(unsigned i = 1; i < ans.size(); ++i) printf(" %d", ans[i]);
	return 0;
}