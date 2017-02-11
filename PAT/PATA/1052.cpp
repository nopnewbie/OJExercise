/*
	PAT(A):1052. Linked List Sorting (25)
	Date: 2016年2月21日 21:48:21
	Finished: 2016年2月22日 09:26:45
*/
#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<fstream>
using namespace std;

const int maxn = 100000;

struct node
{
	int key, next;
}link[maxn];

int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
	freopen("F:\\input.txt", "r", stdin);
#endif
	int n, beg;
	cin >> n >> beg;
	for(int i = 0, ad, key, nxt; i < n; ++i)
	{
		cin >> ad >> key >> nxt;
		link[ad].key = key;
		link[ad].next = nxt;
	}
	vector<pair<int, int>> ans;
	for(int now = beg; now > -1; now = link[now].next)
	{
		ans.push_back(make_pair(link[now].key, now));
	}
	if(ans.empty())
	{
		printf("0 -1\n");
	}
	else
	{
		sort(ans.begin(), ans.end());
		printf("%d %05d\n", ans.size(), ans[0].second);
		for(int i = 0; i < ans.size() - 1; ++i)
		{
			printf("%05d %d %05d\n", ans[i].second, ans[i].first, ans[i + 1].second);
		}
		printf("%05d %d -1\n", ans.back().second, ans.back().first);
	}
	return 0;
}