/*
	PAT(A):1039. Course List for Student (25)
	Date: 2016年3月12日 11:14:13
	Finished: 
*/
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

const int maxn = 36 * 36 * 36 * 36 + 10;
vector<int> lst[maxn];

unsigned hashStr(char *na)
{
	int idx = 0;
	for(int i = 0; i < 3; ++i)	idx = idx * 36 + na[i] - 'A';
	idx = idx * 36 + na[3] - '0';
	return idx;
}

int main()
{
	freopen("F:\\input.txt", "r", stdin);
	int n, k;
	scanf("%d %d", &n, &k);
	char na[5];
	for(int i = 0, c, num ; i < k; ++i)
	{
		scanf("%d %d", &c, &num);
		for(int j = 0; j < num; ++j)
		{
			scanf("%s", na);
			int idx = hashStr(na);
			lst[idx].push_back(c);
		}
	}
	for(int i = 0 ; i < n; ++i)
	{
		scanf("%s", na);
		unsigned idx = hashStr(na);
		printf("%s %d", na, lst[idx].size());
		if(!lst[idx].empty()) sort(lst[idx].begin(), lst[idx].end());
		for(int j = 0; j < lst[idx].size(); ++j) printf(" %d", lst[idx][j]);
		puts("");
	}
	return 0;
}