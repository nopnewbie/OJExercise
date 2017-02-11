/*
	PAT(A):1044. Shopping in Mars (25)
	Date: 2016年2月24日 22:47:08
	Finished:2016年2月25日 09:51:17
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn = 100000 + 10;
int a[maxn];
int maxPrice = 1e8 + 1;

inline int bisearch(int left, int right, int m)
{
	int mid, beg = left - 1, diff;	//beg为起点
	while(left < right)
	{
		mid = left + (right - left) / 2;
		diff = a[mid] - a[beg];
		if(diff < m) left = mid + 1;
		else right = mid;
	}
	return left;
}

int main()
{
	freopen("F:\\input.txt", "r", stdin);
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) { scanf("%d", a + i); a[i] += a[i - 1];}
	vector<pair<int, int>> ans;
	for(int i = 1; i <= n; ++i)
	{
		int j = /*bisearch(i, n + 1, m)*/lower_bound(a + i, a + n + 1, a[i-1] + m) - a;
		if(j > n) continue;
		int diff = a[j] - a[i - 1];
		if(diff < maxPrice && diff >= m)
		{
			maxPrice = diff;
			ans.clear();
			ans.push_back(make_pair(i, j));
		}
		else if(diff == maxPrice) ans.push_back(make_pair(i, j));
	}
	for(auto i = 0; i < ans.size(); ++i) printf("%d-%d\n", ans[i].first, ans[i].second);
	return 0;
}