/*
	PAT(A):1063. Set Similarity (25)
	Date: 2016年3月6日 20:20:15
	Finished: 2016年3月6日 20:51:13
*/
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int main()
{
	freopen("F:\\input.txt", "r", stdin);
	int n, q;
	scanf("%d", &n);
	vector<set<int>> st(n + 1);
	for(int i = 1, j, tmp; i <= n; ++i) 
	{
		scanf("%d", &j);
		while(j--)
		{
			scanf("%d", &tmp);
			st[i].insert(tmp);
		}
	}
	scanf("%d", &q);
	for(int i = 0, x, y; i < q; ++i)
	{
		scanf("%d%d", &x, &y);
		int Nc = 0, Nt = st[x].size() + st[y].size();
		for(auto j = st[x].begin(); j != st[x].end(); ++j)
		{
			if(st[y].find(*j) != st[y].end())
			{
				++Nc;	--Nt;
			}
		}
		if(Nt == 0) puts("100%");
		else printf("%.1lf%%\n", 100.0 * Nc / Nt);
	}
	return 0;
}
