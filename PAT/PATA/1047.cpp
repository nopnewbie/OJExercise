/*
	PAT(A):1047. Student List for Course (25)
	Date: 2016年3月6日 19:07:34
	Finished: 2016年3月6日 20:13:59
	Note: 用string最后一个测试点会超时
*/
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 1679616 + 10; //36^4
int n, k;
char name[maxn][5];
vector<int> course[2501];

int str_hash(char *str)
{
	int key = 0;
	for(int i = 0; i < 3; ++i)
	{
		key = key * 36 + (str[i] - 'A' + 10);
	}
	key = key * 36 + str[3] - '0';		
	//这里不能忘记称36, 0~Z为36进制。因为这个错误，最后一个点卡了半小时orz
	return key;
}

int main()
{
	freopen("F:\\input.txt", "r", stdin);
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; ++i)
	{
		char na[5];
		int c, key;
		scanf("%s %d", na, &c);
		key = str_hash(na);
		strcpy(name[key], na);
		for(int j = 0, t; j < c; ++j)
		{
			scanf("%d", &t);
			course[t].push_back(key);
		}
	}
	for(int i = 1; i <= k; ++i)
	{
		sort(course[i].begin(), course[i].end());
		printf("%d %d\n", i, course[i].size());
		for(int j = 0; j < course[i].size(); ++j)	puts(name[course[i][j]]);
	}
	return 0;
}