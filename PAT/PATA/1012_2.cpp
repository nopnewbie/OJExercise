/*
	参考
	PAT(A):1012. The Best Rank (25)
	Date: 2016年2月15日 10:41:44
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

const int maxn = 1e6 + 10;
const char Subject[] = {'A', 'C', 'M', 'E'};
struct Student
{	
	int id;
	int grade[4];
}stu[2010];

int Rank[maxn][4];	//第一维:id, 第二维:各科成绩
int now;	//控制科目

int cmp(const Student &a, const Student &b)
{
	return a.grade[now] > b.grade[now];
}

int main()
{
#define LOCAL
#ifdef LOCAL
	freopen("F:\\input.txt", "r", stdin);
#endif
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i)
	{
		scanf("%d%d%d%d", &stu[i].id, &stu[i].grade[1], &stu[i].grade[2], &stu[i].grade[3]);
		stu[i].grade[0] = (stu[i].grade[1] + stu[i].grade[2] +stu[i].grade[3]) / 3.0;
	}
	for(now = 0; now < 4; ++now)
	{
		sort(stu, stu + n, cmp);
		Rank[stu[0].id][now] = 1;	//当前科目排名第一
		for(int i = 1; i < n; ++i)
		{
			if(stu[i].grade[now] == stu[i - 1].grade[now] )	Rank[stu[i].id][now] = Rank[stu[i-1].id][now];
			else Rank[stu[i].id][now] = i + 1;
		}
	}
	for(int i = 0; i < m; ++i)
	{
		int id, k;
		scanf("%d", &id);
		if(Rank[id][0])
		{//有记录则排名非零
			k = 0;
			for(int j = 1, rk = Rank[id][0]; j < 4; ++j)
			{
				if(Rank[id][j] < rk) { k = j; rk = Rank[id][j];}
			}
			printf("%d %c\n", Rank[id][k], Subject[k]);
		}
		else puts("N/A");
	}
	return 0;
}